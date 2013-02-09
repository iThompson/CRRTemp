// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANJaguar* shooterSpinner;
	static CANJaguar* armWrist;
	static CANJaguar* armElbow;
	static DigitalInput* armLimit;
	static SpeedController* driveLeft;
	static SpeedController* driveRight;
	static Encoder* drivelEnc;
	static Encoder* driverEnc;
	static Solenoid* driveShift;
	static Servo* loaderCam;
	static DigitalInput* loaderCamDetect;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static void init();
};
#endif
/* Naming scheme for ports:
 * "Subsystem_Type_Function"
 * 
 * Subsystem:
 * ARM - Arm
 * DRV - Drive
 * RBT - No subsystem
 * SHO - Shooter
 * 
 * Type:
 * ANA - Analog Channel
 * MTR - Motor
 * SOL - Solenoid
 * ENC - Encoder
 * POT - Potentiometer
 * CNT - Counter
 * PRS - Pressure switch
 * CMP - Compressor
 */
//Arm Positions
//TODO: DUMMY VALUES! REPLACE LATER!
#define ARM_POS_STOW_EL 1
#define ARM_POS_STOW_WR 1
#define ARM_POS_FEED_EL 2
#define ARM_POS_FEED_WR 2
#define ARM_POS_MID_EL 3
#define ARM_POS_MID_WR 3
#define ARM_POS_PYR_EL 4
#define ARM_POS_PYR_WR 4
#define ARM_POS_TOP_EL 5
#define ARM_POS_TOP_WR 5
//Arm
//TODO: DUMMY VALUES! REPLACE LATER!
#define ARM_MTR_WRIST 8
#define ARM_MTR_ELBOW 7
//Drive
#define DRV_MTR_LEFT 1,1
#define DRV_MTR_RIGHT 1,2
#define DRV_SOL_SHIFT 1,1
//Shooter
#define SHO_MTR_SPIN 6
#define SHO_MTR_CAM 1,3
