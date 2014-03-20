#include "VisionAutonLow.h"
#include "Acquisition/ArmLower.h"
#include "Acquisition/RollerSpin.h"
#include "Acquisition/RollerStop.h"
#include "Drive/DriveToDistance.h"
#include "Drive/JoystickAutoDrive.h"
#include "Vision/TurnLEDsOn.h"
#include "EjectBall.h"

#define TIME_TO_DRIVE 1.5 	//TODO: Test potential dummy value
#define DIST_TO_GOAL 1 		//TODO: REPLACE DUMMY VALUE!!!
#define TIME_TO_WAIT 3 		//TODO: Test Dummy Value

VisionAutonLow::VisionAutonLow() {
	AddParallel(new TurnLEDsOn(), 10); // Run LEDs until end of autonomous
	AddSequential(new ArmLower());
//	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	AddSequential(new DriveToDistance(DIST_TO_GOAL, false));
	AddParallel(new JoystickAutoDrive(0, 0));
//	AddSequential(new WaitCommand(1));
	AddSequential(new RollerSpin(false, true, false, true), TIME_TO_WAIT);
	AddSequential(new RollerSpin(false, true, false), TIME_TO_WAIT);
	AddSequential(new RollerStop());
}
