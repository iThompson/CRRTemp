// RobotBuilder Version: 1.5
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


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANTalon* RobotMap::driveLeftDrive = NULL;
CANTalon* RobotMap::driveRightDrive = NULL;
CANTalon* RobotMap::driveCenterDrive = NULL;
Solenoid* RobotMap::drivelowerWheel = NULL;
SerialPort* RobotMap::serialPort = NULL;
IMU* RobotMap::m_imu = NULL;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	serialPort = new SerialPort(57600,SerialPort::kMXP);
	uint8_t updateRateHz = 50;
	m_imu = new IMU(serialPort, updateRateHz);

	driveLeftDrive = new CANTalon(8);
	driveLeftDrive->ConfigNeutralMode(CANTalon::NeutralMode::kNeutralMode_Brake);
	
	driveRightDrive = new CANTalon(5);
	driveRightDrive->ConfigNeutralMode(CANTalon::NeutralMode::kNeutralMode_Brake);
	
	driveCenterDrive = new CANTalon(4);
	driveCenterDrive->ConfigNeutralMode(CANTalon::NeutralMode::kNeutralMode_Brake);
	
//	double pl = 0;
//	double pr = 0;
//	double ps = 0;
//	double il = 0;
//	double ir = 0;
//	double is = 0;
//	double dl = 0;
//	double dr = 0;
//	double ds = 0;
//	double fl = 0;
//	double fr = 0;
//	double fs = 0;
//	int izone = 1024;
	double ramprate = 48;
//	int profile = 1;
//	driveLeftDrive->SelectProfileSlot(profile);
//	driveRightDrive->SelectProfileSlot(profile);
//	driveCenterDrive->SelectProfileSlot(profile);
//	driveLeftDrive->SetPID(pl, il, dl);
//	driveRightDrive->SetPID(pr, ir, dr);
//	driveCenterDrive->SetPID(ps, is, ds);
//	driveLeftDrive->SetIzone(izone);
//	driveRightDrive->SetIzone(izone);
//	driveCenterDrive->SetIzone(izone);
	driveLeftDrive->SetCloseLoopRampRate(ramprate);
	driveRightDrive->SetCloseLoopRampRate(ramprate);
	driveCenterDrive->SetCloseLoopRampRate(ramprate);
//	driveLeftDrive->SetFeedbackDevice(CANTalon::QuadEncoder);
//	driveRightDrive->SetFeedbackDevice(CANTalon::QuadEncoder);
//	driveCenterDrive->SetFeedbackDevice(CANTalon::QuadEncoder);

	drivelowerWheel = new Solenoid(0, 0);

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
