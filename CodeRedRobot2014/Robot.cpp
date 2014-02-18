// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Robot.h"

Drive* Robot::drive = 0;
Shooter* Robot::shooter = 0;
Acquisition* Robot::acquisition = 0;
Ejection* Robot::ejection = 0;
OI* Robot::oi = 0;
Vision* Robot::vision = 0;

void Robot::RobotInit() {
	RobotMap::init();
	drive = new Drive();
	shooter = new Shooter();
	acquisition = new Acquisition();
	ejection = new Ejection();
	vision = new Vision();
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	comp = new Compressor(1, 1);
	comp->Start();
	lw = LiveWindow::GetInstance();

	// Instantiate the command used for the autonomous period
	autonomousCommand = new VisionAuton();
	m_firstRun = true;
  }
	
void Robot::AutonomousInit() {
	m_firstRun = true;
}
	
void Robot::AutonomousPeriodic() {
	if (m_firstRun == true) {
		// Clear any buttons out of the buffer
		Scheduler::GetInstance()->Run();
		Scheduler::GetInstance()->RemoveAll();
		// Now activate our autonomous. It will launch on the next call to Run();
		if(autonomousCommand != NULL)
			autonomousCommand->Start();
		m_firstRun = false;
	}
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if(autonomousCommand != NULL)
		autonomousCommand->Cancel();
	m_firstRun = true;
}
	
void Robot::TeleopPeriodic() {
	if (m_firstRun == true) {
		// Clear any buttons out of the buffer
		Scheduler::GetInstance()->Run();
		Scheduler::GetInstance()->RemoveAll();
		// Now activate our autonomous. It will launch on the next call to Run()
		m_firstRun = false;
	}
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

