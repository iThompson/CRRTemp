#include "DriveAuton.h"
#include "../Acquisition/ArmRaise.h"
#include "../Drive/JoystickAutoDrive.h"

#define TIME_TO_DRIVE 4 

DriveAuton::DriveAuton() {
	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	AddParallel(new JoystickAutoDrive(0, 0));
	AddParallel(new ArmRaise());
}
