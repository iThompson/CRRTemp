#include "VisionAuton.h"
#include "Acquisition/ArmLower.h"
#include "Acquisition/RollerSpin.h"
#include "Acquisition/RollerStop.h"
#include "Drive/DriveToDistance.h"
#include "Drive/JoystickAutoDrive.h"
#include "Shooter/Fire.h"
#include "Shooter/HotFire.h"
#include "BallToShooter.h"
#include "Vision/TurnLEDsOn.h"

#define TIME_TO_DRIVE 1.5 //TODO: Test potential dummy value
#define DIST_TO_WALL 3.65 //TODO: REPLACE Semi-DUMMY VALUE!!!
#define TIME_TO_WAIT 3 //TODO: Test Dummy Value

VisionAuton::VisionAuton() {
	AddParallel(new TurnLEDsOn(), 10); // Run LEDs until end of autonomous
	AddSequential(new ArmLower());
	AddParallel(new RollerSpin(false, false, true));
//	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	AddSequential(new DriveToDistance(DIST_TO_WALL, true));
	AddParallel(new JoystickAutoDrive(0, 0));
	AddParallel(new BallToShooter(), .7);
	AddSequential(new WaitCommand(1));
	AddSequential(new HotFire(), TIME_TO_WAIT);
	AddSequential(new Fire(1, false, true));
	AddSequential(new RollerStop());
}
