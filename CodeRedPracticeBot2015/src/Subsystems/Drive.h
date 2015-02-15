// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVE_H
#define DRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "../IMU.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Drive: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* leftDrive;
	CANTalon* rightDrive;
	CANTalon* centerDrive;
	CANTalon* toteStacker;
	CANTalon* containerStacker;
	Solenoid* lowerWheel;
//	IMU* imu;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Drive();
	void InitDefaultCommand();
	void HDrive(double forwardSpeed, double sideSpeed, double turnSpeed);
	void ToggleHalfSpeed();
	void ToggleNOS();
	void SetCenterWheel(bool down);
	double GetRobotHeading();
	void ResetIMU();
	int GetContainerEnc();
	int GetToteEnc();
	void ZeroCont();
	void SetContPID(double p, double i, double d);
	int GetContError();
	int GetToteError();
	double GetSpeed();
	bool FullSpeed;
	bool NOS;

	//Not Drive But I'm Lazy
	void SetClawPos(int pos);
	void SetClawSpeed(double speed);
	void SetTotePos(int pos);
	void SetToteSpeed(double speed);
};

#endif
