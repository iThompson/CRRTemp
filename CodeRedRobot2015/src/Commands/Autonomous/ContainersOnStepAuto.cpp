#include "ContainersOnStepAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../Wings/RetractWings.h"
#include "../ToteStacker/ResetTote.h"
#include "../ContainerStacker/ResetClaw.h"

ContainersOnStepAuto::ContainersOnStepAuto() {
	AddParallel(new ResetTote());
	AddParallel(new ResetClaw());
	AddParallel(new JoystickAutoDrive(1,0,0,5000,0,0), 5);
	AddSequential(new JoystickAutoDrive(-1,0,0,-1000,0,0), 2);
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0), .5);
	AddSequential(new JoystickAutoDrive(-1,0,0,-6000,0,0), 5);
	AddSequential(new JoystickAutoDrive(1,0,0,1000,0,0), 2);
	AddSequential(new RetractWings());
}
