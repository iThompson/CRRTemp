#include "VisionAuton.h"
#include "Acquisition/ArmLower.h"
#include "Acquisition/RollerSpin.h"
#include "Drive/DriveToDistance.h"
#include "Drive/JoystickAutoDrive.h"
#include "Shooter/Fire.h"

#define TIME_TO_DRIVE 1.5 //TODO: Replace potential dummy value
#define DIST_TO_WALL 10 //TODO: REPLACE DUMMY VALUE!!!
#define TIME_TO_WAIT 3 //TODO: Replace Dummy Value

VisionAuton::VisionAuton() {
	AddSequential(new ArmLower());
	AddParallel(new RollerSpin(false, false, false));
	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
//	AddSequential(new DriveToDistance(DIST_TO_WALL));
	AddParallel(new JoystickAutoDrive(0, 0));
	AddSequential(new WaitCommand(.5));
	if(Robot::vision->IsGoalHot()) 
		AddSequential(new Fire(SHO_DEFAULT_GOAL, false, true));
	else 
	{
		AddSequential(new WaitCommand(TIME_TO_WAIT));
		AddSequential(new Fire(SHO_DEFAULT_GOAL, false, true));
	}
}
