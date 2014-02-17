#include "SimpleAuton.h"
#include "Acquisition/ArmLower.h"
#include "Acquisition/RollerSpin.h"
#include "Drive/DriveToDistance.h"
#include "Drive/JoystickAutoDrive.h"
#include "Shooter/Fire.h"

#define TIME_TO_DRIVE 2 //TODO: Replace dummy value
#define DIST_TO_WALL 10 //TODO: REPLACE DUMMY VALUE!

SimpleAuton::SimpleAuton() {
	AddSequential(new ArmLower());
	AddParallel(new RollerSpin(false, false, false));
//	AddSequential(new JoystickAutoDrive(0, 0), TIME_TO_DRIVE);
	AddSequential(new DriveToDistance(DIST_TO_WALL));
	AddSequential(new Fire(SHO_DEFAULT_GOAL, false));
	AddSequential(new JoystickAutoDrive(0, 0));
}
