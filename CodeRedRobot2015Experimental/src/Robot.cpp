// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

#include "Commands/Autonomous/ContainersOnStepAuto.h"
#include "Commands/Autonomous/MovementAuto.h"
#include "Commands/Autonomous/TemplateAuto.h"
#include "Commands/Autonomous/MoveLeftAuto.h"
#include "Commands/Autonomous/LiftContainerAuto.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Drive* Robot::drive = 0;
Acquisition* Robot::acquisition = 0;
//ToteStacker* Robot::toteStacker = 0;
ToteStackerNew* Robot::toteStackerNew = 0;
ContainerStacker* Robot::containerStacker = 0;
Wings* Robot::wings = 0;
OI* Robot::oi = 0;
//Sensors* Robot::sensors = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	drive = new Drive();
	acquisition = new Acquisition();
//	toteStacker = new ToteStacker();
	toteStackerNew = new ToteStackerNew();
	containerStacker = new ContainerStacker();
	wings = new Wings();
//	sensors = new Sensors();
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	firstIteration = true;

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousChooser = new SendableChooser();
	autonomousChooser->AddDefault("Empty Autonomous", new TemplateAuto());
	autonomousChooser->AddObject("Wing Autonomous", new ContainersOnStepAuto());
	autonomousChooser->AddObject("Motion Autonomous", new MovementAuto());
	autonomousChooser->AddObject("Right Move", new MoveLeftAuto());
	autonomousChooser->AddObject("Untested Claw Auto", new LiftContainerAuto());

	SmartDashboard::PutData("Auto Selector", autonomousChooser);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand =  (Command*) autonomousChooser->GetSelected();
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.

	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();

}

void Robot::TeleopPeriodic() {
	if(firstIteration)
	{
		bool isCalibrating = RobotMap::m_imu->IsCalibrating();
		if(!isCalibrating)
		{
			Wait(.03);
			RobotMap::m_imu->ZeroYaw();
			firstIteration = false;
		}
	}
	//SmartDashboard::PutNumber("Yaw", RobotMap::m_imu->GetYaw());
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
