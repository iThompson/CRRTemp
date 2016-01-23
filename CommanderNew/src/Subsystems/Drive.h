#ifndef Drive_H
#define Drive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor* lDrive1;
	Victor* lDrive2;
	Victor* rDrive1;
	Victor* rDrive2;
public:
	Drive();
	void InitDefaultCommand();
	void TankDrive(double lSpeed, double rSpeed);
};

#endif
