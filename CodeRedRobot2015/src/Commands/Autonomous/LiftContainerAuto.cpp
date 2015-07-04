#include "LiftContainerAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"
#include "../ContainerStacker/OpenClaw.h"
#include "../ContainerStacker/CloseClaw.h"
#include "../ContainerStacker/ContainerPositionChange.h"

LiftContainerAuto::LiftContainerAuto() {
	AddParallel(new CloseClaw());
	AddParallel(new ResetToteNew());
	AddSequential(new ResetClaw());
	AddSequential(new CloseClaw());
	AddSequential(new ContainerPositionChange(5));
}
