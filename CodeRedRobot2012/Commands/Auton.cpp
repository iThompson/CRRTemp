#include "Auton.h"
#include "Drive/AlignDrive.h"
#include "Shooter/ShootAuto.h"
#include "Shooter/Shoot.h"
#include "Loader/Fire.h"
#include "Acquirer/RunBelt.h"

Auton::Auton() : CommandGroup("Auton")
{
	//TODO Timeouts on AutonDrive are random guesses, update them later with experimental data
	AddParallel(new ShootAuto());
	AddSequential(new AlignDrive(), 8.0);
	AddParallel(new Shoot());
	AddParallel(new RunBelt(true));
	AddSequential(new Fire());
	AddParallel(new RunBelt(true));
	AddParallel(new Shoot());
	AddSequential(new Fire());
	
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
	
