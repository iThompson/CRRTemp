#ifndef AUTON_H
#define AUTON_H

#include "Commands/CommandGroup.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Auton: public CommandGroup {
public:	
	Auton();
	DriveForward();
	
};

#endif
