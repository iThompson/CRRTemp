#include "TwoDiscAuton.h"
#include "Drive/JoystickAutoDrive.h"
#include "Arm/ArmPosition.h"
#include "Shooter/ShooterSpin.h"
#include "Loader/Fire.h"

TwoDiscAuton::TwoDiscAuton() {
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
	AddSequential(new JoystickAutoDrive(0.5, 0.5), 5);
	AddSequential(new ArmPosition(ARM_POS_TOP_EL, ARM_POS_TOP_WR, Arm::kHigh, true));
	AddSequential(new ShooterSpin(false));
	AddParallel(new ArmPosition(ARM_POS_TOP_EL, ARM_POS_TOP_WR, Arm::kHigh));
	AddParallel(new Fire());
}
