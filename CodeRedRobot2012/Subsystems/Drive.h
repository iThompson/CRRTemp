#ifndef DRIVE_H
#define DRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Ian
 * Devon
 */
class Drive: public Subsystem {
private:
	CANJaguar *lJagA;
	CANJaguar *lJagB;
	CANJaguar *rJagA;
	CANJaguar *rJagB;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Drive();/* {
		Go Forward;
	}*/
	void InitDefaultCommand();
	void TankDrive(double left, double right);
};

#endif
