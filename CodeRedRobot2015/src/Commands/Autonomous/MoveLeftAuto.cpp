#include "MoveLeftAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStacker/ResetTote.h"
#include "../ContainerStacker/ResetClaw.h"
#include "../Drive/LowerHWheel.h"

MoveLeftAuto::MoveLeftAuto() {
	AddParallel(new ResetTote());
	AddParallel(new ResetClaw());
	AddSequential(new LowerHWheel());
	AddSequential(new JoystickAutoDrive(.3,0,0,INCH * 60,0,0), 5);
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0),2.5);
}
