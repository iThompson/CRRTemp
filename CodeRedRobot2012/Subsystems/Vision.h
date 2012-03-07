#ifndef VISION_H
#define VISION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

// Be VERY careful if adding anything other than UINT16s
// PPC has strict alignment rules, so care must be taken
// to not break the format across the network
// The data array follows the format of the commented out section
typedef struct {
	char hdr[4];
	UINT16 data[8];
/*	UINT16 distHigh;
	INT16 angleHigh;
	UINT16 distRight;
	INT16 angleRight;
	UINT16 distLeft;
	INT16 angleLeft;
	UINT16 distLow;
	INT16 angleLow;*/
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
	
	Timer m_fieldWd[4];
	
	int m_curTarget;
	
	AnalogChannel m_ultrasonic;
public:
	Vision();
	void InitDefaultCommand();
	
	// Returns a copy of the current data
	TrackingData GetCurrentData();
	bool IsTargetValid();
	bool IsDataValid();
	
	UINT16 GetTargetDistance();
	INT16 GetTargetAngle();
	
	int GetUSDistance();
	
	void SelectTarget(int id);
};

#endif
