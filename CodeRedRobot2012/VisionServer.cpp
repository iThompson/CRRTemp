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
	
	m_task = new Task("VisionServer", (FUNCPTR)ServerTask);
	if (!m_task->Start()) {
		printf("ERROR: Failed to launch Vision Server thread\n");
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
		
		//TODO: Perform checks for valid data here
		
		// Calls to ntohs for each field would probably be good here
		// Though the cRIO is in big endian mode, so it's not strictly necessary
		
		semTake(m_bufferSem, WAIT_FOREVER);
		
		// Swap the buffers
		TrackingData* tmp;
		tmp = outBuf;
		outBuf = inBuf;
		inBuf = tmp;
		
		semGive(m_bufferSem);
	}
}


