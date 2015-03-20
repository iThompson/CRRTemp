#include "TemplateAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"

TemplateAuto::TemplateAuto() {
	AddParallel(new ResetToteNew(),10);
	AddParallel(new ResetClaw());
}
