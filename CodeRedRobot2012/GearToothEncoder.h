/*
 * GearToothEncoder.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Ian
 */

#ifndef GEARTOOTHENCODER_H_
#define GEARTOOTHENCODER_H_

#include <GearTooth.h>

class GearToothEncoder: public GearTooth {
public:
	GearToothEncoder(UINT32 channel, bool directionSensitive = false);
	GearToothEncoder(UINT8 moduleNumber, UINT32 channel, bool directionSensitive = false);
	virtual ~GearToothEncoder();
	
	virtual double GetRate();
};

#endif /* GEARTOOTHENCODER_H_ */
