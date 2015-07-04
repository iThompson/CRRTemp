/*
 * ShotLogger.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: Ian
 */

#include "ShotLogger.h"

ShotLogger* ShotLogger::m_self = NULL;

ShotLogger::ShotLogger() {
	m_log = NULL;
	// Find the first available filename
	char buf[30];
	int i;
	
	for (i=0; i < 200; i++) {
		sprintf(buf, "/log/norm/log%d.csv", i);
		if (!FileExists(buf)) {
			m_log = fopen(buf, "w");
			break;
		}
	}
	
	if (m_log == NULL) {
		printf("[LOGGER] Failed to open logfile %s\n", buf);
	}
}

ShotLogger::~ShotLogger() {
	if (m_log != NULL) {
		fclose(m_log);
	}
}

void ShotLogger::InMatch() {
	// Read in the current match number
	int id = 0;
	char buf[25];
	FILE* fTemp = fopen("/log/matchID", "r");
	if (fTemp == NULL) {
		printf("[LOGGER] Failed to find matchID. Using regular file\n");
		return;
	}
	
	// Read the current matchID from the file
	fscanf(fTemp, "%u", &id);
	if (id == 0) {
		printf("[LOGGER] Failed to read matchID from file. Using regular file\n");
		return;
	}
	fclose(fTemp);
	
	sprintf(buf, "/log/match/match%d.csv", id);
	
	fTemp = fopen(buf, "w");
	if (fTemp == NULL) {
		printf("[LOGGER] Failed to open %s. Using regular file\n", buf);
		return;
	}
	
	// Close out the regular logfile
	if (m_log != NULL) {
		Info("MATCH MODE");
		fclose(m_log);
		m_log = NULL;
	}
	m_log = fTemp;

	// Write in the match header
	sprintf(buf, "MATCH %d", id);
	Info(buf);
}

void ShotLogger::Info(const char* info) {
	if (m_log != NULL) {
		fprintf(m_log, " , ,%s\n", info);
	}
}

void ShotLogger::Shot(double power, double compression) {
	if (m_log != NULL) {
		fprintf(m_log, "%f, %f, \n", power, compression);
	}
}

bool ShotLogger::FileExists(const char* name) {
	FILE* test;
	if ((test = fopen(name, "r")) != NULL) {
		fclose(test);
		return true;
	}
	return false;
}

ShotLogger* ShotLogger::GetInstance() {
	if (m_self == NULL) {
		m_self = new ShotLogger();
	}
	
	return m_self;
}
