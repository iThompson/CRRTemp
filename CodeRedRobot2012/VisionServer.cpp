/*
 * VisionServer.cpp
 *
 *  Created on: Feb 8, 2012
 *      Author: Ian
 */

#include "VisionServer.h"
#include <hostLib.h>
#include <inetLib.h>
#include <sockLib.h>

#define VISION_LISTEN_PORT 6639

void VisionServer::Init() {
	m_bufferSem = semMCreate(SEM_Q_PRIORITY);
	inBuf = &buf1;
	outBuf = &buf2;
	
	m_watchdog = new Timer();
	
	// Will show up in task list as "FRC_VisionServer"
	m_task = new Task("VisionServer", (FUNCPTR)ServerTask);
	if (!m_task->Start()) {
		printf("ERROR: Failed to launch Vision Server task\n");
	}
}

int VisionServer::ServerTask()
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
		
		m_watchdog->Reset();
		m_watchdog->Start();
		
		semGive(m_bufferSem);
	}
}

bool VisionServer::IsDataValid()
{
	bool isValid;
	
	semTake(m_bufferSem, WAIT_FOREVER);
	// Watchdog will be 0 until initial data is received
	isValid = (m_watchdog->Get() != 0) && (m_watchdog->Get() < 0.25);
	semGive(m_bufferSem);
	
	return isValid;
}



TrackingData VisionServer::GetCurrentData()
{
	TrackingData rv;
	
	semTake(m_bufferSem, WAIT_FOREVER);
	rv =  *outBuf;
	semGive(m_bufferSem);
	
	return rv;
}
