#include "MovementAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStacker/ResetTote.h"
#include "../ContainerStacker/ResetClaw.h"

MovementAuto::MovementAuto() {
	AddParallel(new ResetTote());
	AddParallel(new ResetClaw());
	AddParallel(new JoystickAutoDrive(.3,0,0,INCH * 60,0,0), 5);

}
