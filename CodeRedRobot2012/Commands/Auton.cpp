#include "Auton.h"


Auton::Auton() {
	AddSequential(new AutoShot());
	AddSequential(new AutonDrive(-1,1));
	/*Add timeout for turn when we know the speed*/
	AddSequential(new AutonDrive(1,1));
	/*Add timeout for drive when we know the speed*/
    /*AddSequential(new BridgeLower());*/   	 //Placeholder until we have an actual method to lower bridge, if necessary
	AddSequential(new Acquire());
	AddSequential(new AutonDrive(-1,1));
	/*Add timeout for turn when we know the speed*/
	AddSequential(new AutonDrive(1,1));
	/*Add timeout for drive when we know the speed*/
	AddSequential(new AutoShot());
	
	// Add Commands here:
	// I have added a comment.
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
	
