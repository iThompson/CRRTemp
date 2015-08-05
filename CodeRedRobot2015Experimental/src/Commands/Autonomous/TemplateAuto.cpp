#include "TemplateAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"
#include "../Drive/SideAutoDrive.h"
#include "../Drive/ForwardAutoDrive.h"
#include "../Drive/TurnAutoDrive.h"

TemplateAuto::TemplateAuto() {
	AddParallel(new ResetToteNew(),10);
	AddParallel(new ResetClaw());
}
