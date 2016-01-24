#include "ContainersOnStepAuto.h"
#include "../Drive/JoystickAutoDrive.h"
#include "../Wings/RetractWings.h"
#include "../Wings/ExtendWings.h"
#include "../ToteStackerNew/ResetToteNew.h"
#include "../ContainerStacker/ResetClaw.h"
#include "../Drive/SideAutoDrive.h"
#include "../Drive/ForwardAutoDrive.h"
#include "../Drive/TurnAutoDrive.h"


ContainersOnStepAuto::ContainersOnStepAuto() {
	/*
	AddParallel(new ResetToteNew());
	AddParallel(new ResetClaw());
	//AddParallel(new ExtendWings());
	AddSequential(new JoystickAutoDrive(-.7,0,0,5000,0,0), 2);
	//AddSequential(new JoystickAutoDrive(0,0,.7,0,0,-90), 1.125); //Important
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0),2.5);
	//AddSequential(new RetractWings());
	*/


	//Official
	AddParallel(new ResetToteNew());
	AddParallel(new ResetClaw());
	AddSequential(new JoystickAutoDrive(0,0,.7,0,0,-90), 1.125);
	AddParallel(new JoystickAutoDrive(0,0,0,0,0,0), 1);
	AddSequential(new ExtendWings());
	AddSequential(new JoystickAutoDrive(-.7,0,0,5000,0,0), 73.7 * INCH_TIME);
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0), .5);
	AddSequential(new JoystickAutoDrive(.7,0,0,5000,0,0), 12 * INCH_TIME);
	AddSequential(new JoystickAutoDrive(0,0,0,0,0,0), 1.5);
	AddSequential(new JoystickAutoDrive(.7,0,0,5000,0,0), 107 * INCH_TIME);
	AddParallel(new JoystickAutoDrive(0,0,0,0,0,0), 1);
	AddSequential(new JoystickAutoDrive(-.7,0,0,5000,0,0), 24 * INCH_TIME);
	AddParallel(new JoystickAutoDrive(0,0,0,0,0,0), 1);
	AddSequential(new RetractWings());


}
