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
	CANJaguar *lJagA;
	CANJaguar *lJagB;
	CANJaguar *rJagA;
	CANJaguar *rJagB;
	
public:
	Drive();
	void InitDefaultCommand();
	void TankDrive(double left, double right);
};

#endif
