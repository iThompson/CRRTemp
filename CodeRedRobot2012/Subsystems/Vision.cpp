#include "Vision.h"
#include "../Commands/Vision/AimHigh.h"
#include "../Robotmap.h"
#include "../CommandBase.h"

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
	
	struct sockaddr_in clientAddr;
	int clientAddrSize;
	// Begin the main server loop
	while(1) {
		recvfrom(beagleSock,
				(char *)inBuf,
				sizeof(TrackingData),
				0,
				(sockaddr*)&clientAddr,
				&clientAddrSize);
		
		// Magic number doesn't include a null, so use strncmp to filter it out
		if (strncmp (inBuf->magic, "0639", 4) != 0) {
			// We appear to have a bad packet. IGNORE!
			continue;
		}
		
		// Perform byte-swaps as necessary
		inBuf->pt1 = ntohs(inBuf->pt1);
		inBuf->pt2 = ntohs(inBuf->pt2);
		
		semTake(m_bufferSem, WAIT_FOREVER);
		
		// Swap the buffers
		TrackingData* tmp;
		tmp = outBuf;
		outBuf = inBuf;
		inBuf = tmp;
		
		// Reset the packet timer
		m_watchdog.Reset();
		m_watchdog.Start();
		
		semGive(m_bufferSem);
	}
	
	// Clean up (if we ever get here)
	close(beagleSock);
}

bool Vision::IsDataValid()
{
	bool isValid;
	
	// Timers are actually thread safe. Just doing this for good measure
	semTake(m_bufferSem, WAIT_FOREVER);
	
	// Watchdog will be 0 until initial data is received
	isValid = (m_watchdog.Get() != 0) && (m_watchdog.Get() < 0.50);
	
	semGive(m_bufferSem);
	
	return isValid;
}



TrackingData Vision::GetCurrentData()
{
	TrackingData rv;
	
	semTake(m_bufferSem, WAIT_FOREVER);
	rv = *outBuf;
	semGive(m_bufferSem);
	
	return rv;
}



void Vision::SelectTarget(int id) {
	if (id < 0) id = 0;
	if (id > 3) id = 3;
	m_curTarget = id;
}

UINT16 Vision::GetTargetDistance() {
	
}
UINT16 Vision::GetTargetAngle() {
	
}
