/*
 * VisionServer.h
 *
 *  Created on: Feb 8, 2012
 *      Author: Ian
 */

#ifndef VISIONSERVER_H_
#define VISIONSERVER_H_

#include "Task.h"

// Be VERY careful if adding anything other than UINT16s
// PPC has very strict alignment rules, so care must be taken
// to not break the format across the network

typedef struct {
	UINT16 pt1;
	UINT16 pt2;
} TrackingData;

class VisionServer {
public:
	
	static void Init();	
	static int ServerTask();
	
private:
	
	static TrackingData buf1;
	static TrackingData buf2;
	
	static TrackingData *inBuf;
	static TrackingData *outBuf;
	
	static SEM_ID m_bufferSem;
	
	static Task *m_task;
};

#endif /* VISIONSERVER_H_ */
