#include "Vision.h"
#include "../Commands/Vision/AimHigh.h"
#include "../Robotmap.h"
#include "../CommandBase.h"

#define VISION_LISTEN_PORT 6639

static const double kDataTimeout = 0.50;

Vision::Vision() : Subsystem("Vision"),
				   m_bufferSem(semMCreate(SEM_Q_PRIORITY)),
				   m_task("VisionServer", (FUNCPTR)s_ServerTask),
				   m_watchdog(),
				   m_curTarget(0),
				   m_ultrasonic(VSN_ANA_US)
{
	inBuf = &buf1;
	outBuf = &buf2;
	
	// Initialize all our timers
	m_watchdog.Start();
	for (int i = 0; i < 4; i++) m_fieldWd[i].Start();
		
	// Launch the actual server task
	if (!m_task.Start((INT32)this)) {
		printf("ERROR: Failed to launch Vision Server task\n");
	}
}
    
void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new AimHigh());
}

int Vision::s_ServerTask(Vision* thisPtr) {
	return thisPtr->ServerTask();
}

int Vision::ServerTask()
{
	struct sockaddr_in serverAddr;
	int sockAddrSize = sizeof(serverAddr);
	int beagleSock = ERROR;
	size_t bytes;
	bzero ((char *) &serverAddr, sockAddrSize);
	serverAddr.sin_len = (u_char) sockAddrSize;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons (VISION_LISTEN_PORT);
	serverAddr.sin_addr.s_addr = htonl (INADDR_ANY);
	// ^^^ Was copied from PCVideoServer.
	
	if ((beagleSock = socket(AF_INET, SOCK_DGRAM, 0)) == ERROR) {
		printf("ERROR: Failed to create Vision socket\n");
		return -1;
	}
	
	if (bind(beagleSock, (struct sockaddr *) &serverAddr, sockAddrSize) == ERROR) {
		printf("ERROR: Failed to bind Vision socket\n");
		close(beagleSock);
		return -1;
	}
	
	// Begin the main server loop
	while(1) {
		// Will block until new data comes in
		recv(beagleSock,
				(char *)inBuf,
				sizeof(TrackingData),
				0);

		if (sizeof(TrackingData) != bytes) {
			printf ("Invalid packet: recv returned %d, errno is %s\n", bytes, strerror(errno));
			continue;
		}
		
		// Header doesn't include a null, so use strncmp to filter it out
		if (strncmp (inBuf->hdr, "0639", 4) != 0) {
			printf("Invalid packet: Improper header\n");
			continue;
		}

		// Perform byte-swaps as necessary
		for (int i=0; i < 8; i++) {
			inBuf->data[i] = ntohs(inBuf->data[i]);
		}
		
		// If a target was not found in this frame, it will have a distance of 0
		// If this happens, fill in the data from the last packet so that no 'hiccups' will occur
		for (int i = 0; i < 4; i++) {
			if (inBuf->data[2*i] == 0) {
				// Carry over the distance/angle pair
				inBuf->data[2*i] = outBuf->data[2*i];
				inBuf->data[2*i+1] = outBuf->data[2*i+1];
			} else {
				// Reset the data timer
				m_fieldWd[i].Reset();
			}
		}
		
		CRITICAL_REGION(m_bufferSem);
		{
			// Swap the buffers
			TrackingData* tmp;
			tmp = outBuf;
			outBuf = inBuf;
			inBuf = tmp;
			
			// Post the new target data to the dashboard
			SmartDashboard::Log(outBuf->data[m_curTarget*2], "Target Distance");
			SmartDashboard::Log(outBuf->data[m_curTarget*2 + 1], "Target Angle");
			SmartDashboard::Log(IsTargetValid(), "Target Valid");
			SmartDashboard::Log(IsDataValid(), "Beagle Valid");

			// Reset the packet timer
			m_watchdog.Reset();
		}
		END_REGION;
	}
	
	// Clean up (if we ever get here)
	close(beagleSock);
}


bool Vision::IsTargetValid()
{
	return (m_fieldWd[m_curTarget].Get() < kDataTimeout);
}

bool Vision::IsDataValid()
{
	return (m_watchdog.Get() < kDataTimeout);
}



TrackingData Vision::GetCurrentData()
{
	TrackingData rv;
	
	Synchronized sync(m_bufferSem);
	
	rv = *outBuf;
	
	return rv;
}



void Vision::SelectTarget(int id) {
	if (id < 0) id = 0;
	if (id > 3) id = 3;
	m_curTarget = id;
	
	
	// HACK: display ultrasonic status here
	SmartDashboard::Log(GetUSDistance(), "Ultrasonic distance");
	SmartDashboard::Log(GetUSDistance(), "Ultrasonic graph");
}

UINT16 Vision::GetTargetDistance() {
	TrackingData target = GetCurrentData();
	
	return target.data[2*m_curTarget];
}


INT16 Vision::GetTargetAngle() {
	TrackingData target = GetCurrentData();

	// Angle data is actually sent as INT16. Cast it back here
	return (INT16) target.data[2*m_curTarget + 1];
}

int Vision::GetUSDistance() {
	return (int) m_ultrasonic.GetVoltage() / (5.0 / 512.0);
}
