#ifndef VISION_H
#define VISION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

// Be VERY careful if adding anything other than UINT16s
// PPC has strict alignment rules, so care must be taken
// to not break the format across the network

typedef struct {
	char magic[4];
	UINT16 pt1;
	UINT16 pt2;
} TrackingData;

/**
 *
 *
 * @author Ian
 */
class Vision: public Subsystem {
private:
	static int s_ServerTask(Vision* thisPtr);
	int ServerTask();
	
	TrackingData buf1;
	TrackingData buf2;
	
	TrackingData *inBuf;
	TrackingData *outBuf;
	
	SEM_ID m_bufferSem;
	
	Task m_task;
	
	Timer m_watchdog;
	
	int m_curTarget;
public:
	Vision();
	void InitDefaultCommand();
	
	// Returns a copy of the current data
	TrackingData GetCurrentData();
	bool IsDataValid();
	
	void SelectTarget(int id);
};

#endif
