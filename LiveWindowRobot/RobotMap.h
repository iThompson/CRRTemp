#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "LiveSolenoid.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// The following variables are automatically assigned by
	// robotbuilder and will be updated the next time you export to
	// Java from robot builder. Do not put any code or make any change
	// in the following block or it will be lost on an update. To
	// prevent this subsystem from being automatically updated, delete
	// the following line.
	static CANJaguar* DRIVE_LJAGA;
	static CANJaguar* DRIVE_LJAGB;
	static CANJaguar* DRIVE_RJAGA;
	static CANJaguar* DRIVE_RJAGB;
	static Encoder* DRIVE_LENC;
	static Encoder* DRIVE_RENC;
	static LiveSolenoid* DRIVE_SHIFTER;

	static void init();
};
#endif
