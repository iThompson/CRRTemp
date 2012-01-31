#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Auton.h"
#include "CommandBase.h"

class CodeRedRobot : public IterativeRobot {
private:
	
	virtual void RobotInit() {
		CommandBase::init();
	}
	
	virtual void AutonomousInit() {
		// Initialize the autonomous command(group), load into scheduler
		// To change auton sequences, change which class is being instantiated
		
		// Note that autoCommand will only have 1 shot to run
		// After finishing, all subsystems will revert to default commands
		Command *autoCommand = new Auton();
		autoCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(CodeRedRobot);

