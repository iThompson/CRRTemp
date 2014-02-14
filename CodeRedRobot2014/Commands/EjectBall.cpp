#include "EjectBall.h"
#include "Ejection/ExtendKicker.h"
#include "Acquisition/RollerSpin.h"

#define TIME_TO_EJECT 3

EjectBall::EjectBall() {
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
	
	AddSequential(new ExtendKicker());			// Knock the ball out of shooter and into rollers
	AddSequential(new RollerSpin(false, true), TIME_TO_EJECT); // Roll the ball out of robot
	
}
