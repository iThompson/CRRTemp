/*
 * GearToothEncoder.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Ian
 */

#include "GearToothEncoder.h"

GearToothEncoder::GearToothEncoder(UINT32 channel, bool directionSensitive) :
									GearTooth(channel, directionSensitive)
{
}

GearToothEncoder::GearToothEncoder(UINT8 moduleNumber, UINT32 channel, bool directionSensitive) :
									GearTooth(moduleNumber, channel, directionSensitive)
{
}

GearToothEncoder::~GearToothEncoder() {
	// TODO Auto-generated destructor stub
}

double GearToothEncoder::GetRate() {
	return 1 / GetPeriod();
}
