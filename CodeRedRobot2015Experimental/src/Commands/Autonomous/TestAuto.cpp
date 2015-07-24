#include "TestAuto.h"
#include "../Drive/SideAutoDrive.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"

TestAuto::TestAuto() {
	AddSequential(new SideAutoDrive(10,.5));
}
