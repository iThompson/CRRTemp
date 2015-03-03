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
CANTalon* RobotMap::drivelDrive = NULL;
CANTalon* RobotMap::driverDrive = NULL;
CANTalon* RobotMap::drivecDrive = NULL;
Solenoid* RobotMap::drivelowerWheel = NULL;
Talon* RobotMap::acquisitionlAcquisition = NULL;
Talon* RobotMap::acquisitionrAcquisition = NULL;
Solenoid* RobotMap::acquisitionacqArm = NULL;
CANTalon* RobotMap::toteStackertoteLift = NULL;
Solenoid* RobotMap::toteStackerbrake = NULL;
CANTalon* RobotMap::containerStackercontainerLift = NULL;
Solenoid* RobotMap::containerStackerclaw = NULL;
Victor* RobotMap::wingswingRetracter = NULL;
DigitalInput* RobotMap::wingsleftLimit = NULL;
DigitalInput* RobotMap::wingsrightLimit = NULL;
AnalogInput* RobotMap::sensorstote1 = NULL;
AnalogInput* RobotMap::sensorstote2 = NULL;
AnalogInput* RobotMap::sensorstote3 = NULL;
AnalogInput* RobotMap::sensorstote4 = NULL;
AnalogInput* RobotMap::sensorstote5 = NULL;
AnalogInput* RobotMap::sensorscontainerSensor = NULL;
DigitalInput* RobotMap::toteStackerhall = NULL;
DigitalInput* RobotMap::containerStackerhall = NULL;
IMU* RobotMap::m_imu = NULL;
SerialPort* RobotMap::serialPort = NULL;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	drivelDrive = new CANTalon(DRV_MTR_LEFT);
	drivelDrive->ConfigNeutralMode(CANTalon::NeutralMode::kNeutralMode_Brake);
	
	driverDrive = new CANTalon(DRV_MTR_RIGHT);
	driverDrive->ConfigNeutralMode(CANTalon::NeutralMode::kNeutralMode_Brake);
	
	drivecDrive = new CANTalon(DRV_MTR_CENTER);
	drivecDrive->ConfigNeutralMode(CANTalon::NeutralMode::kNeutralMode_Brake);
	
	drivelowerWheel = new Solenoid(DRV_SOL_CNTR_SUSP);
	lw->AddActuator("Drive", "lowerWheel", drivelowerWheel);
	
	
	acquisitionlAcquisition = new Talon(ACQ_MTR_LEFT);
	
	
	acquisitionrAcquisition = new Talon(ACQ_MTR_RIGHT);
	
	
	acquisitionacqArm = new Solenoid(ACQ_SOL_EXTEND);
	lw->AddActuator("Acquisition", "acqArm", acquisitionacqArm);
	

	toteStackertoteLift = new CANTalon(TST_MTR_LIFT);
	double pToteLift = 1;
	double iToteLift = 0;
	double dToteLift = 0;
	int izone = 1024;
	double ramprate = 48;
	int profile = 1;
	
	toteStackertoteLift->SelectProfileSlot(profile);
	toteStackertoteLift->SetPID(pToteLift, iToteLift, dToteLift);
	toteStackertoteLift->SetIzone(izone);
	toteStackertoteLift->SetCloseLoopRampRate(ramprate);
	toteStackertoteLift->SetFeedbackDevice(CANTalon::QuadEncoder);
	
	toteStackertoteLift->ConfigFwdLimitSwitchNormallyOpen(false);
	toteStackertoteLift->ConfigRevLimitSwitchNormallyOpen(false);

	toteStackerbrake = new Solenoid(TST_SOL_BRAKE);
	lw->AddActuator("ToteStacker", "brake", toteStackerbrake);
	
	
	containerStackercontainerLift = new CANTalon(CST_MTR_LIFT);
	double pContainerLift = 2.5;
	double iContainerLift = 0;
	double dContainerLift = 0;
	
	containerStackercontainerLift->SelectProfileSlot(profile);
	containerStackercontainerLift->SetPID(pContainerLift, iContainerLift, dContainerLift, 0);
	containerStackercontainerLift->SetIzone(izone);
	containerStackercontainerLift->SetCloseLoopRampRate(ramprate);
	containerStackercontainerLift->SetFeedbackDevice(CANTalon::QuadEncoder);
	containerStackercontainerLift->SetSensorDirection(true);
	
	containerStackercontainerLift->ConfigFwdLimitSwitchNormallyOpen(true);
	containerStackercontainerLift->ConfigRevLimitSwitchNormallyOpen(false);

	containerStackerclaw = new Solenoid(CST_SOL_CLAW);
	lw->AddActuator("ContainerStacker", "claw", containerStackerclaw);
	
	
	sensorscontainerSensor = new AnalogInput(SNS_ANA_CONT);
	lw->AddSensor("Sensors", "containerSensor", sensorscontainerSensor);
	
	wingswingRetracter = new Victor(WNG_MTR_RET);
	
	wingsleftLimit = new DigitalInput(WNG_DIN_LEFT);
	lw->AddSensor("Wings", "leftLimit", wingsleftLimit);
	
	wingsrightLimit = new DigitalInput(WNG_DIN_RIGHT);
	lw->AddSensor("Wings", "rightLimit", wingsrightLimit);

	sensorstote1 = new AnalogInput(SNS_ANA_TOTE1);
	lw->AddSensor("Sensors", "tote1", sensorstote1);

	sensorstote2 = new AnalogInput(SNS_ANA_TOTE2);
	lw->AddSensor("Sensors", "tote2", sensorstote2);

	sensorstote3 = new AnalogInput(SNS_ANA_TOTE3);
	lw->AddSensor("Sensors", "tote3", sensorstote3);

	sensorstote4 = new AnalogInput(SNS_ANA_TOTE4);
	lw->AddSensor("Sensors", "tote4", sensorstote4);

	sensorstote5 = new AnalogInput(SNS_ANA_TOTE5);
	lw->AddSensor("Sensors", "tote5", sensorstote5);

	toteStackerhall = new DigitalInput(TST_DIN_HALL);
	lw->AddSensor("ToteStacker", "hall", toteStackerhall);

	containerStackerhall = new DigitalInput(CST_DIN_HALL);
	lw->AddSensor("ContainerStacker", "hall", containerStackerhall);

	serialPort = new SerialPort(57600,SerialPort::kMXP);
	uint8_t updateRateHz = 50;
	m_imu = new IMU(serialPort, updateRateHz);

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
