#include "SafeMode.h"

SafeMode::SafeMode() : CommandBase("SafeMode"),
						m_ballState(0)
{
	Requires(drive);
	Requires(gate);
	Requires(acquirer);
	Requires(loader);
	Requires(shooter);
	
	// This command will take complete control over the robot. Don't let it be overriden
	SetInterruptible(false);
}

// Called just before this Command runs the first time
void SafeMode::Initialize() {
	m_ballState = 0;
}

// Called repeatedly when this Command is scheduled to run
void SafeMode::Execute() {
	// Low gear only
	drive->Shift(false);
	
	// Disable the bridge manipulator
	gate->SetState(false);
	
	// Acquisition control
	if (oi->GetAqsState() == 1) {
		// Hard forward
		acquirer->BeltRun();
	} else if (oi->GetAqsState() == -1) {
		// Hard reverse
		acquirer->BeltReverse();
	} else {
		// Automatic control
		if (m_ballState != 0) {
			acquirer->BeltRun();
		} else {
			acquirer->BeltStop();
		}
	}
	
	// Loader control
	if (m_ballState == 1) {
		loader->Launch();
		
		if (!acquirer->IsExitReady()) {
			m_ballState = -1;
		}
	} else if (m_ballState == 0) {
		loader->Lock();
	} else {
		loader->Load();
		
		if (acquirer->IsExitReady()) {
			m_ballState = 0;
		}
	}
	
	// Drive and Shooter Control
	if (oi->GetAllowFire()) {
		// Firing, so no driving
		drive->TankDrive(0.0, 0.0);
		
		shooter->SetSpeed(0.75);
		shooter->Run();
	} else {
		// Allow free driving
		drive->TankDrive(oi->GetYLeft(), oi->GetYRight());
		
		// No shooting allowed!
		shooter->Stop();
	}
	
	// Check the fire button
	if (m_ballState == 0 && oi->GetFireButton()) {
		// Next loop will fire
		if (oi->GetAllowFire()) {
			m_ballState = 1;
		} else {
			m_ballState = -1;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SafeMode::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SafeMode::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SafeMode::Interrupted() {
}
