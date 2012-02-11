#include "Auton.h"
#include "../Commands/AutonDrive.h"
#include "../Commands/Autoshot.h"
#include "../Commands/Acquire.h"
#include "../Commands/Gate/Deploy.h"
#include "../Commands/Gate/Undeploy.h"

Auton::Auton() {
	//TODO Timeouts on AutonDrive are random guesses, update them later with experimental data
	AddSequential(new AutoShot());					// Shoot one or both of the balls we start with
	AddSequential(new AutonDrive(-1,1), 1.0);		// Turn 180 degrees to face the gate
	AddSequential(new AutonDrive(1,1), 1.0);		// Drive forward to gate
    AddSequential(new Deploy());					// Close the brige-lowering mechanism
	AddSequential(new Acquire());					// Pick up balls from the gate
	AddParallel(new Undeploy());					// Retract gate-lowering mechanism
	AddSequential(new AutonDrive(-1,1), 1.0);		// Turn 180 degrees to face the baskets
	AddSequential(new AutonDrive(1,1), 1.0);		// Drive forward to the key
	AddSequential(new AutoShot());					// Fire the balls we picked up
	
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
	
