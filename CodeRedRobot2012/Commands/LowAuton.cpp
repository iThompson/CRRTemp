#include "LowAuton.h"
#include "Shooter/ShootManual.h"
#include "AutonDrive.h"
#include "Acquirer/RunBelt.h"
#include "Loader/Fire.h"

LowAuton::LowAuton() {
	AddParallel(new ShootManual(0.4));
	AddSequential(new AutonDrive(-0.6, -0.6), 5.0);
	AddParallel(new RunBelt(true));
	AddParallel(new AutonDrive(0.0, 0.0));
	AddSequential(new Fire());
	AddSequential(new WaitCommand(2.0));
	AddSequential(new Fire());
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
