#ifndef SHOOTONCE_H
#define SHOOTONCE_H

#include "Commands/CommandGroup.h"
#include "ShooterShoot.h"
#include "ShooterSpin.h"

/**
 *
 *
 * @author Programmer
 * 
 * Run ShooterShoot, then ShooterSpin -- Ignore this for now
 */
class ShootOnce: public CommandGroup {
public:	
	ShootOnce();
};

#endif
