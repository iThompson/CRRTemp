#ifndef DRIVE_H
#define DRIVE_H
#include "Commands/Subsystem.h"
#include "../DriveMotorOutput.h"
#include "WPILib.h"

/**
 *
 *
 * @author Devon Loehr
 * 
 */
class Drive: public Subsystem {
private:
	DriveMotorOutput lDrive;
	DriveMotorOutput rDrive;
	Solenoid shifter;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Drive();
	void InitDefaultCommand();
	void TankDrive(double left, double right);
	void Shift(bool high);
	
	void SetMotorsCoasting();
	void SetMotorsDefault();
};

#endif
