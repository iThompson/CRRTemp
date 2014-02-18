#include "SimpleAuton.h"
#include "Acquisition/ArmLower.h"
#include "Acquisition/RollerSpin.h"
#include "Drive/DriveToDistance.h"
#include "Drive/JoystickAutoDrive.h"
#include "Shooter/Fire.h"

#define TIME_TO_DRIVE 1.5 //TODO: Replace dummy value
#define DIST_TO_WALL 10 //TODO: REPLACE DUMMY VALUE!

SimpleAuton::SimpleAuton() {
	AddSequential(new ArmLower());
	AddParallel(new RollerSpin(false, false, false));
	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	AddSequential(new WaitCommand(.5));
	AddParallel(new JoystickAutoDrive(0, 0));
//	AddSequential(new DriveToDistance(DIST_TO_WALL));
	AddSequential(new Fire(1, false, true));
}
