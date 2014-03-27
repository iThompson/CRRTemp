#include "TwoBallAuton.h"
#include "../Acquisition/ArmLower.h"
#include "../Acquisition/RollerSpin.h"
#include "../Acquisition/RollerStop.h"
#include "../Drive/DriveToDistance.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../Shooter/Fire.h"
#include "../Shooter/HotFire.h"
#include "../BallToShooter.h"
#include "../Vision/TurnLEDsOn.h"

//TODO: Confirm dummy values; they seem to work
#define TIME_TO_DRIVE 1.5 //TODO: Test potential dummy value
#define TIME_TO_DRIVE_BACK 2.75 //TODO: Replace mega-dummy value
#define DIST_TO_WALL 3.65 //TODO: REPLACE Semi-DUMMY VALUE!!!

TwoBallAuton::TwoBallAuton() {
	AddSequential(new ArmLower());
	AddParallel(new RollerSpin(false, true));
//	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	AddSequential(new DriveToDistance(DIST_TO_WALL, true));
	AddParallel(new JoystickAutoDrive(0, 0));
	AddParallel(new BallToShooter(), .7);
	AddSequential(new WaitCommand(1));
	AddSequential(new Fire(1, true));
	AddParallel(new RollerSpin(false, true));
	AddSequential(new JoystickAutoDrive(-1, 1), TIME_TO_DRIVE_BACK);
	AddSequential(new DriveToDistance(DIST_TO_WALL, true));
	AddParallel(new JoystickAutoDrive(0, 0));
	AddParallel(new BallToShooter(), .7);
	AddSequential(new WaitCommand(1));
	AddSequential(new Fire(1, true));
	AddSequential(new RollerStop());
}
