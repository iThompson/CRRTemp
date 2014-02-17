#include "VisionAuton.h"
#include "Acquisition/ArmLower.h"
#include "Acquisition/RollerSpin.h"
#include "Drive/DriveToDistance.h"
#include "Drive/JoystickAutoDrive.h"
#include "Shooter/Fire.h"

#define TIME_TO_DRIVE 2 //TODO: Replace potential dummy value
#define DIST_TO_WALL 10 //TODO: REPLACE DUMMY VALUE!!!
#define TIME_TO_WAIT 3 //TODO: Replace Dummy Value

VisionAuton::VisionAuton() {
        // Add Commands here:
        // e.g. AddSequential(new Command1());
        //      AddSequential(new Command2());
        // these will run in order.

        // To run multiple commands at the same time,
        // use AddParallel()
        // e.g. AddParallel(new Command1());
        //      AddSequential(new Command2());
        // Command1 and Command2 will run in parallel.

        // A command group will require all of the subsystems that each member
        // would require.
        // e.g. if Command1 requires chassis, and Command2 requires arm,
        // a CommandGroup containing them would require both the chassis and the
        // arm.
	AddSequential(new ArmLower());
	AddParallel(new RollerSpin(false, false));
//	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	AddSequential(new DriveToDistance(DIST_TO_WALL));
	if(Robot::vision->IsGoalHot()) AddSequential(new Fire(SHO_DEFAULT_GOAL, false));
	AddSequential(new WaitCommand(TIME_TO_WAIT));
	AddSequential(new Fire(SHO_DEFAULT_GOAL, false));
	AddSequential(new JoystickAutoDrive(0, 0));
}
