#include "DriveAuton.h"
#include "../Drive/JoystickAutoDrive.h"

#define TIME_TO_DRIVE 2 // TODO: Replace Dummy Value

DriveAuton::DriveAuton() {
	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	AddParallel(new JoystickAutoDrive(0, 0));
}
