// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ToteStacker/BrakeOff.h"
#include "Commands/ToteStacker/BrakeOn.h"
#include "Commands/ContainerStacker/CloseClaw.h"
#include "Commands/ToteStacker/DropTotes.h"
#include "Commands/Acquisition/ExtendArms.h"
#include "Commands/Drive/JoystickAutoDrive.h"
#include "Commands/Drive/JoystickHDrive.h"
#include "Commands/Drive/LowerHWheel.h"
#include "Commands/ContainerStacker/OpenClaw.h"
#include "Commands/Drive/RaiseHWheel.h"
#include "Commands/ContainerStacker/ResetClaw.h"
#include "Commands/ToteStacker/ResetTote.h"
#include "Commands/Acquisition/RetractArms.h"
#include "Commands/Wings/RetractWings.h"
#include "Commands/ContainerStacker/SetClawPos.h"
#include "Commands/Acquisition/StopWheels.h"
#include "Commands/Acquisition/ToteIntake.h"
#include "Commands/Acquisition/ToteOutput.h"
#include "Commands/ToteStacker/ToteSetPos.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

     	 m_sStick = new Joystick(0);
     	 m_cStick = new Joystick(1);

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("ToteIntake", new ToteIntake());

	SmartDashboard::PutData("ToteOutput", new ToteOutput());

	SmartDashboard::PutData("ExtendArms", new ExtendArms());

	SmartDashboard::PutData("RetractArms", new RetractArms());

	SmartDashboard::PutData("StopWheels", new StopWheels());

	SmartDashboard::PutData("JoystickHDrive", new JoystickHDrive());

	SmartDashboard::PutData("JoystickAutoDrive", new JoystickAutoDrive(0,0,0));

	SmartDashboard::PutData("RetractWings", new RetractWings());

	SmartDashboard::PutData("LowerHWheel", new LowerHWheel());

	SmartDashboard::PutData("RaiseHWheel", new RaiseHWheel());

	SmartDashboard::PutData("ResetClaw", new ResetClaw());

	SmartDashboard::PutData("CloseClaw", new CloseClaw());

	SmartDashboard::PutData("OpenClaw", new OpenClaw());

	SmartDashboard::PutData("SetClawPos", new SetClawPos(0));

	SmartDashboard::PutData("ResetTote", new ResetTote());

	SmartDashboard::PutData("DropTotes", new DropTotes());

	SmartDashboard::PutData("BrakeOn", new BrakeOn());

	SmartDashboard::PutData("BrakeOff", new BrakeOff());

	SmartDashboard::PutData("ToteSetPos", new ToteSetPos());

        // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

double OI::GetSingleTurn() {
	return m_sStick->GetThrottle();
}

double OI::GetSingleX() {
	return m_sStick->GetX();
}

double OI::GetSingleY() {
	return m_sStick->GetY();
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
