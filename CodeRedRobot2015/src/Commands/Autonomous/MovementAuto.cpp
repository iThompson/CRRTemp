#include "MovementAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStacker/ResetTote.h"
#include "../ContainerStacker/ResetClaw.h"

MovementAuto::MovementAuto() {
	AddParallel(new ResetTote());
	AddParallel(new ResetClaw());
	AddParallel(new JoystickAutoDrive(1,0,0,5000,0,0), 5);

}
