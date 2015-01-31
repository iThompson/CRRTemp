// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CONTAINERSTACKER_H
#define CONTAINERSTACKER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ContainerStacker: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* containerLift;
	Solenoid* claw;
	DigitalInput* containerHome;
	AnalogInput* clawIR;
	int m_targetPos;
	bool m_standingMode;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ContainerStacker();
	void InitDefaultCommand();
	void SetClaw(bool closed);
	void ZeroClaw();
	void SetPos(int position);
	int GetTargetPos();
	void SetTargetPos(int position);
	bool IsAtHome();
	void SetMode(bool standing);
	bool GetStanding();
};

#endif
