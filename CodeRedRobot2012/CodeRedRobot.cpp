#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Auton.h"
#include "Commands/WarlockAuton.h"
#include "Commands/LowAuton.h"
#include "Commands/BridgeAuton.h"
#include "ShotLogger.h"
#include "CommandBase.h"
#include "Robotmap.h"

class CodeRedRobot : public IterativeRobot {
private:
	
	Compressor *m_comp;
	Command* autoCommand;
	ShotLogger* m_log;
	bool m_firstRun;
	
	virtual void RobotInit() {
		CommandBase::init();
		
		m_comp = new Compressor(RBT_PRS, RBT_CMP);
		m_comp->Start();
		
//		autoCommand = new Auton();
//		autoCommand = new WarlockAuton();
//		autoCommand = new LowAuton();
		autoCommand = new BridgeAuton();
		
		// Open the shooter logfile
//		m_log = ShotLogger::GetInstance();
	}
	
	virtual void DisabledInit() {
//		m_log->Info("DISABLED");
	}
	
	virtual void AutonomousInit() {
		GetWatchdog().SetEnabled(false);
		// Initialize the autonomous command(group), load into scheduler
		// To change auton sequences, change which class is being instantiated
		
		// Note that autoCommand will only have 1 shot to run
		// After finishing, all subsystems will revert to default commands
		autoCommand->Start();
		
		// We could move this to DisabledPeriodic() if we wanted to. Shouldn't really make a difference though
//		if (DriverStation::GetInstance()->IsFMSAttached() == true) {
//			// We are in a match situation. 
//			m_log->InMatch();
//		}
		
//		m_log->Info("AUTONOMOUS INIT");
		m_firstRun = true;
	}
	
	virtual void AutonomousPeriodic() {
		// Workaround for field auton not running
		if (m_firstRun == true) {
			// Clear any buttons out of the buffer
			Scheduler::GetInstance()->Run();
			// Now activate our autonomous. It will launch on the next call to Run();
			autoCommand->Start();
			m_firstRun = false;
		}
		
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autoCommand->Cancel();		
		
//		m_log->Info("TELEOP INIT");
		
		GetWatchdog().SetExpiration(0.5);
		GetWatchdog().SetEnabled(false);
	}
	
	virtual void TeleopPeriodic() {
		GetWatchdog().Feed();
		Scheduler::GetInstance()->Run();
		
		SmartDashboard::Log((bool) m_comp->GetPressureSwitchValue(), "Compressor Status");
	}
};

START_ROBOT_CLASS(CodeRedRobot);

