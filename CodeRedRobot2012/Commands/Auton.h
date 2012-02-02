#ifndef AUTON_H
#define AUTON_H

#include "Commands/CommandGroup.h"
#include "../Commands/AutonDrive.h"
#include "../Commands/JoystickDrive.h"
#include "../Commands/Shoot.h"
#include "../Commands/Autoshot.h"
#include "../Commands/Acquire.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Auton: public CommandGroup {
public:	
	Auton();
};

#endif
