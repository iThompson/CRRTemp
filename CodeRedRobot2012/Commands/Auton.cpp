#include "Auton.h"
#include "../Commands/DriveForward.h"
#include "../Commands/JoystickDrive.h"
#include "../Commands/Shoot.h"
#include "../Commands/Autoshot.h"
#include "../Commands/AutoAcquire.h"

Auton::Auton() {
	AddSequential(new AutoShot());
	AddSequential(new DriveForward(0,1));
	/*Add timeout for turn when we know the speed*/
	AddSequential(new DriveForward(1,1));
	/*Add timeout for drive when we know the speed*/
	AddSequential(new AutoAcquire());
    /*AddSequential(new BridgeLower());*/    			//Placeholder until we have an actual method to lower bridge
	AddSequential(new DriveForward(1,1));
	/*Add timeout for drive when we know the speed*/
	AddSequential(new AutoShot());
	
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
}
	
