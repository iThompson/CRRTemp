#ifndef Drive_H
#define Drive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<Victor> lDrive1;
	std::shared_ptr<Victor> lDrive2;
	std::shared_ptr<Victor> rDrive1;
	std::shared_ptr<Victor> rDrive2;
public:
	Drive();
	void InitDefaultCommand();
	void TankDrive(double lSpeed, double rSpeed);
};

#endif
