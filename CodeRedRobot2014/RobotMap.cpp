// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

CANJaguar* RobotMap::driveleft1 = NULL;
CANJaguar* RobotMap::driveleft2 = NULL;
CANJaguar* RobotMap::driveleft3 = NULL;
CANJaguar* RobotMap::driveright1 = NULL;
CANJaguar* RobotMap::driveright2 = NULL;
CANJaguar* RobotMap::driveright3 = NULL;
Encoder* RobotMap::drivelEnc = NULL;
Encoder* RobotMap::driverEnc = NULL;
Ultrasonic* RobotMap::driverangeFinder = NULL;
Ultrasonic* RobotMap::drivegoalSensor = NULL;
Solenoid* RobotMap::driveshift = NULL;
Solenoid* RobotMap::shooterleft = NULL;
Solenoid* RobotMap::shooterright = NULL;
SpeedController* RobotMap::acquisitionroller = NULL;
Solenoid* RobotMap::acquisitionraise = NULL;
AnalogChannel* RobotMap::acquisitionproc1 = NULL;
AnalogChannel* RobotMap::acquisitionproc2 = NULL;
AnalogChannel* RobotMap::acquisitionproc3 = NULL;
Solenoid* RobotMap::ejectionkicker = NULL;
DigitalInput* RobotMap::visiongoalHot = NULL;
Relay* RobotMap::visionLEDs = NULL;
AnalogChannel* RobotMap::testultrasonic = NULL;

void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();

	driveleft1 = new CANJaguar(DRV_MTR_LEFT_ONE);
	
	driveleft2 = new CANJaguar(DRV_MTR_LEFT_TWO);
	
	driveleft3 = new CANJaguar(DRV_MTR_LEFT_THREE);
	
	driveright1 = new CANJaguar(DRV_MTR_RIGHT_ONE);
	
	driveright2 = new CANJaguar(DRV_MTR_RIGHT_TWO);
	
	driveright3 = new CANJaguar(DRV_MTR_RIGHT_THREE);
	
	drivelEnc = new Encoder(DRV_ENC_LEFT);
	
	driverEnc = new Encoder(DRV_ENC_RIGHT);
	
	driverangeFinder = new Ultrasonic(DRV_ULT_LONGDIST);
	
	drivegoalSensor = new Ultrasonic(DRV_ULT_SHORTDIST);
	
	driveshift = new Solenoid(DRV_SOL_SHIFT);
	lw->AddActuator("Drive", "shift", driveshift);
	
	shooterleft = new Solenoid(SHO_SOL_LEFT);
	lw->AddActuator("Shooter", "left", shooterleft);
	
	shooterright = new Solenoid(SHO_SOL_RIGHT);
	lw->AddActuator("Shooter", "right", shooterright);
	
	acquisitionroller = new Victor(ACQ_MTR_ROLLER);
	lw->AddActuator("Acquisition", "roller", (Victor*) acquisitionroller);
	
	acquisitionraise = new Solenoid(ACQ_SOL_RAISE);
	lw->AddActuator("Acquisition", "raise", acquisitionraise);
	
	acquisitionproc1 = new AnalogChannel(DRV_ANA_PROC_1);
	
	acquisitionproc2 = new AnalogChannel(DRV_ANA_PROC_2);
	
	acquisitionproc3 = new AnalogChannel(DRV_ANA_PROC_3);
		
	ejectionkicker = new Solenoid(EJT_SOL_KICK);
	lw->AddActuator("Ejection", "kicker", ejectionkicker);

	visiongoalHot = new DigitalInput(VIS_DIN_HOT);

	visionLEDs = new Relay(VIS_REL_LED);

	testultrasonic = new AnalogChannel(1,4);
}
