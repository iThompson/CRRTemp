// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/Shooter/ShooterStop.h"
Shooter::Shooter() : Subsystem("Shooter") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	spinner = RobotMap::shooterSpinner;
	cam = RobotMap::shooterCam;
	camDetect = RobotMap::shooterCamDetect;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ShooterStop());
}

void Shooter::CamStop()
{
	cam->Set(0.0);
}



void Shooter::SetSpeed(double speed)
{
	spinner->Set(speed);
}



void Shooter::CamRun()
{
	cam->Set(1.0);
}



void Shooter::Start()
{
	spinner->EnableControl();
}



void Shooter::Stop()
{
	spinner->DisableControl();
}



bool Shooter::IsCamHome()
{
	return camDetect->Get();
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
