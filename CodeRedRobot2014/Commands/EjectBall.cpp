#include "EjectBall.h"
#include "Ejection/ExtendKicker.h"
#include "Acquisition/RollerSpin.h"

EjectBall::EjectBall() {
	AddParallel(new ExtendKicker());			// Knock the ball out of shooter and into rollers
	AddSequential(new RollerSpin(false, true, false)); // Roll the ball out of robot
}
