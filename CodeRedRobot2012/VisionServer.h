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
// PPC has very strict alignment rules, so care must be taken
// to not break the format across the network

typedef struct {
	char magic[4];
	UINT16 pt1;
	UINT16 pt2;
} TrackingData;

class VisionServer {
public:
	
	static void Init();	
	static int ServerTask();
	
	static TrackingData GetCurrentData();
	static bool IsDataValid();
	
private:
	
	static TrackingData buf1;
	static TrackingData buf2;
	
	static TrackingData *inBuf;
	static TrackingData *outBuf;
	
	static SEM_ID m_bufferSem;
	
	static Task *m_task;
	
	static Timer *m_watchdog;
};

#endif /* VISIONSERVER_H_ */
