#include "AlignDrive.h"

static const INT16 kAngleDeadband = 100;

AlignDrive::AlignDrive() {
	Requires(drive);
}

// Called just before this Command runs the first time
void AlignDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AlignDrive::Execute() {
	INT16 angle = vision->GetTargetAngle();
	
	// Take average of two joystick for base speed
	double base = (oi->GetStickL()->GetY() + oi->GetStickR()->GetY()) / 2;
	// and scale it to +- 0.6 (1.0 - max offset)
	base *= 0.6;
	
	double offset;
	
	if (abs(angle) < kAngleDeadband) {
		// Close enough to aligned
		offset = 0.0;
	} else if (angle < 0) {
		// Too far to the right
		offset = 0.4;
	} else {
		// Too far to the left
		offset = -0.4;
	}
	
	// Apply offset to the base speed
	drive->TankDrive(base + offset, base - offset);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AlignDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignDrive::Interrupted() {
}
