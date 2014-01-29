#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class CodeRedTestbot : public IterativeRobot {
private:
	
	virtual void RobotInit() {
		CommandBase::init();
		//SmartDashboard::GetInstance()->PutData(Scheduler::GetInstance());
	}
	
	virtual void AutonomousInit() {
	}
	
	virtual void AutonomousPeriodic() {
	}
	
	virtual void TeleopInit() {
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(CodeRedTestbot);

