#include "AlignDrive.h"

static const INT16 kDeadband = 50;
static const double kPulseTime = 0.07;
static const double kOffsetPower = 0.23;

AlignDrive::AlignDrive() : CommandBase("AlignDrive")
{
	Requires(drive);
	
	m_heldTime.Start();
}

// Called just before this Command runs the first time
void AlignDrive::Initialize() {
	drive->SetMotorsCoasting();
}

// Called repeatedly when this Command is scheduled to run
void AlignDrive::Execute() {
	INT16 angle = vision->GetTargetAngle();

	// Take average of two joystick for base speed
	double base = (oi->GetYLeft() + oi->GetYRight()) / 2;
	// and scale it such that the differential is always maintained
	base *= 1.0 - kOffsetPower;

	double offset;

	if (abs(angle) < kDeadband) {
		// Close enough to aligned
		offset = 0.0;
		
	} else if (angle < 0) {
		// Too far to the right
		offset = kOffsetPower;
	} else {
		// Too far to the left
		offset = -kOffsetPower;
	}
	
	if (!vision->IsTargetValid()) {
		offset = 0.0;
		
		// If this is part of an auto sequence, abort immediately
		// Targets have 0.5 seconds to be re-acquired (see IsTargetValid())
		m_inDeadband = true;
	}

	// If this is not a fresh packet
	if (angle == m_lastData) {
		// Check how long we've been running with this packet
		if (m_heldTime.Get() > kPulseTime) {
			// And stop moving if we've gone far enough
			offset = 0.0;
		}
	} else {
		// New packet, let's reset our timer
		m_heldTime.Reset();
	}

	// Apply offset to the base speed
	drive->TankDrive(base + offset, base - offset);

	m_lastData = angle;
}

// Make this return true when this Command no longer needs to run execute()
bool AlignDrive::IsFinished() {
	if (GetGroup() == NULL) {
		// When not in an auto sequence: Never give up, never surrender!
		return false;
	} else {
		// Exit if we've settled and are in an auto sequence
		return m_inDeadband;
	}
}

// Called once after isFinished returns true
void AlignDrive::End() {
	drive->SetMotorsDefault();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignDrive::Interrupted() {
	// Don't neeed to do anything special here
	End();
}
