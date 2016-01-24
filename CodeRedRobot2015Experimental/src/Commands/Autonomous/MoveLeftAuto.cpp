#include "MoveLeftAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"
#include "../Drive/LowerHWheel.h"
#include "../ContainerStacker/ContainerPositionChange.h"
#include "../Drive/SideAutoDrive.h"
#include "../Drive/ForwardAutoDrive.h"
#include "../Drive/TurnAutoDrive.h"

MoveLeftAuto::MoveLeftAuto() {
	AddParallel(new ResetToteNew(), 10);
	AddParallel(new ResetClaw());
	AddSequential(new LowerHWheel());
	AddSequential(new SideAutoDrive(60,.75), 4);
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0),2.5);
	AddSequential(new ContainerPositionChange(5));
}
