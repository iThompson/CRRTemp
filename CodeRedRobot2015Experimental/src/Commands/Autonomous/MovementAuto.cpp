#include "MovementAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"
#include "../Drive/SideAutoDrive.h"
#include "../Drive/ForwardAutoDrive.h"
#include "../Drive/TurnAutoDrive.h"

MovementAuto::MovementAuto() {
	AddParallel(new ResetToteNew());
	AddParallel(new ResetClaw());
	AddSequential(new ForwardAutoDrive(72,.3), 7);
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0),2.5);
}
