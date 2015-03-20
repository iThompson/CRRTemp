#include "MovementAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"

MovementAuto::MovementAuto() {
	AddParallel(new ResetToteNew());
	AddParallel(new ResetClaw());
	AddSequential(new JoystickAutoDrive(.3,0,0,INCH * 72,0,0), 5);
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0),2.5);
}
