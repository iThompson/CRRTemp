#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class CodeRedRobot : public IterativeRobot {
private:
	
	virtual void RobotInit() {
		CommandBase::init();
	}
	
	virtual void AutonomousInit() {
	}
	
	virtual void AutonomousPeriodic() {
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

