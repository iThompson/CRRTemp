/*
 * ShotLogger.h
 *
 *  Created on: Apr 14, 2012
 *      Author: Ian
 */

#ifndef SHOTLOGGER_H_
#define SHOTLOGGER_H_

#include <stdio.h>

class ShotLogger {
public:
	static ShotLogger* GetInstance();
	void Info(const char* info);
	void Shot(double power, double compression);
	void InMatch();
	
private:
	ShotLogger();
	virtual ~ShotLogger();
	
	static bool FileExists(const char* name);
	
	FILE* m_log;
	
	static ShotLogger* m_self;
};

#endif /* SHOTLOGGER_H_ */
