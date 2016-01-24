#include "MoveLeftAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"
#include "../Drive/LowerHWheel.h"
#include "../ContainerStacker/ContainerPositionChange.h"

MoveLeftAuto::MoveLeftAuto() {
	AddParallel(new ResetToteNew(), 10);
	AddParallel(new ResetClaw());
	AddSequential(new LowerHWheel());
	AddSequential(new JoystickAutoDrive(0,.75,0,0,60 * INCH,0), 2.75);
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0),2.5);
	AddSequential(new ContainerPositionChange(5));
}
