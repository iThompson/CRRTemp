#include "TestAuto.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"
#include "../Drive/SideAutoDrive.h"
#include "../Drive/ForwardAutoDrive.h"
#include "../Drive/TurnAutoDrive.h"
#include "../Drive/JoystickAutoDrive.h"

TestAuto::TestAuto() {
	AddSequential(new TurnAutoDrive(50,.5));
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0), 2.5);
}
