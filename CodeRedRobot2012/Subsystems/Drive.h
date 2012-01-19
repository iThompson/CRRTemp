#ifndef DRIVE_H
#define DRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Ian
 */
class Drive: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Drive();
	void InitDefaultCommand();
};

#endif
