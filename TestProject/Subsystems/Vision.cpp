#include "Vision.h"
#include "../Robotmap.h"
#include "../CommandBase.h"
#include <errno.h>

#define VISION_LISTEN_PORT 6639

Vision::Vision() : Subsystem("Vision"),
				   m_bufferSem(semMCreate(SEM_Q_PRIORITY)),
				   m_task("VisionServer", (FUNCPTR)s_ServerTask),
				   m_watchdog(),
				   m_curTarget(0)
{
	inBuf = &buf1;
	outBuf = &buf2;
		
	if (!m_task.Start((INT32)this)) {
		printf("ERROR: Failed to launch Vision Server task\n");
	}
}
    
void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
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
		bytes = recv(beagleSock,
				(char *)inBuf,
				sizeof(TrackingData),
				MSG_WAITALL);
		
		if (sizeof(TrackingData) != bytes) {
			printf ("Invalid packet: recv returned %d, errno is %s\n", bytes, strerror(errno));
			continue;
		}
		
		// Magic number doesn't include a null, so use strncmp to filter it out
		if (strncmp (inBuf->magic, "0639", 4) != 0) {
			// We appear to have a bad packet. IGNORE!
			printf("Dropping invalid packet, bad header\n");
			continue;
		}

		// Perform byte-swaps as necessary
		inBuf->distHigh 	= ntohs(inBuf->distHigh);
		inBuf->angleHigh 	= ntohs(inBuf->angleHigh);
		inBuf->distRight 	= ntohs(inBuf->distRight);
		inBuf->angleRight	= ntohs(inBuf->angleRight);
		inBuf->distLeft 	= ntohs(inBuf->distLeft);
		inBuf->angleLeft 	= ntohs(inBuf->angleLeft);
		inBuf->distLow 		= ntohs(inBuf->distLow);
		inBuf->angleLow 	= ntohs(inBuf->angleLow);

		// Fill in invalid data with old values
		if (inBuf->distHigh == 0) {
			inBuf->distHigh = outBuf->distHigh;
			inBuf->angleHigh = outBuf->angleHigh;
		} else {
			// Reset the timer since the last valid data
			m_timeHigh.Reset();
			m_timeHigh.Start();
		}
		if (inBuf->distRight == 0) {
			inBuf->distRight = outBuf->distRight;
			inBuf->angleRight = outBuf->angleRight;
		} else {
			// Reset the timer since the last valid data
			m_timeRight.Reset();
			m_timeRight.Start();
		}
		if (inBuf->distLeft == 0) {
			inBuf->distLeft = outBuf->distLeft;
			inBuf->angleLeft = outBuf->angleLeft;
		} else {
			// Reset the timer since the last valid data
			m_timeLeft.Reset();
			m_timeLeft.Start();
		}
		if (inBuf->distLow == 0) {
			inBuf->distLow = outBuf->distLow;
			inBuf->angleLow = outBuf->angleLow;
		} else {
			// Reset the timer since the last valid data
			m_timeLow.Reset();
			m_timeLow.Start();
		}
		
		CRITICAL_REGION(m_bufferSem);
		{
			// Swap the buffers
			TrackingData* tmp;
			tmp = outBuf;
			outBuf = inBuf;
			inBuf = tmp;
			
			SmartDashboard::Log(outBuf->distHigh, "DistHigh");
			SmartDashboard::Log(outBuf->angleHigh, "AngleHigh");

			// Reset the packet timer
			m_watchdog.Reset();
			m_watchdog.Start();
		}
		END_REGION;
	}
	
	// Clean up (if we ever get here)
	close(beagleSock);
}

bool Vision::IsDataValid()
{
	switch (m_curTarget) {
		case 0:
			return (m_timeHigh.Get() != 0.0) && (m_timeHigh.Get() < 0.5);
		case 1:
			return (m_timeRight.Get() != 0.0) && (m_timeRight.Get() < 0.5);
		case 2:
			return (m_timeLeft.Get() != 0.0) && (m_timeLeft.Get() < 0.5);
		case 3:
			return (m_timeLow.Get() != 0.0) && (m_timeLow.Get() < 0.5);
	}
	
	return (m_watchdog.Get() != 0) && (m_watchdog.Get() < 0.50);
	
//	bool isValid;
//	
//	// Timers are actually thread safe. Just doing this for good measure
//	Synchronized sync(m_bufferSem);
//	
//	// Watchdog will be 0 until initial data is received
//	isValid = (m_watchdog.Get() != 0) && (m_watchdog.Get() < 0.50);
//	
//	return isValid;
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
	
	
}

UINT16 Vision::GetTargetDistance() {
	TrackingData data = GetCurrentData();
	
	switch (m_curTarget) {
	case 0:
		return data.distHigh;
	case 1:
		return data.distLeft;
	case 2:
		return data.distRight;
	case 3:
		return data.distLow;
	}
	
	return 0;
}
UINT16 Vision::GetTargetAngle() {
	TrackingData data = GetCurrentData();

	switch (m_curTarget) {
	case 0:
		return data.angleHigh;
	case 1:
		return data.angleLeft;
	case 2:
		return data.angleRight;
	case 3:
		return data.angleLow;
	}

	return 0;
}
