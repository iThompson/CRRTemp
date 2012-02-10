/*
 * VisionServer.h
 *
 *  Created on: Feb 8, 2012
 *      Author: Ian
 */

#ifndef VISIONSERVER_H_
#define VISIONSERVER_H_

#include "Task.h"
#include "Timer.h"

// Be VERY careful if adding anything other than UINT16s
// PPC has strict alignment rules, so care must be taken
// to not break the format across the network

typedef struct {
	char magic[4];
	UINT16 pt1;
	UINT16 pt2;
} TrackingData;

class VisionServer {
public:
	
	static VisionServer* GetInstance();

	// Returns a copy of the current data
	TrackingData GetCurrentData();
	bool IsDataValid();
	
private:
	
	VisionServer();
	~VisionServer();
	
	static int s_ServerTask(VisionServer* thisPtr);
	int ServerTask();
	
	TrackingData buf1;
	TrackingData buf2;
	
	TrackingData *inBuf;
	TrackingData *outBuf;
	
	SEM_ID m_bufferSem;
	
	Task m_task;
	
	Timer m_watchdog;
	
	static VisionServer *m_self;
};

#endif /* VISIONSERVER_H_ */
