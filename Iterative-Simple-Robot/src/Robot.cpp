#include "WPILib.h"
#include "IMU.h"

class Robot: public IterativeRobot
{

	RobotDrive myRobot; // robot drive system
	Joystick rStick;
	Joystick lStick;
	LiveWindow *lw;
	IMU *imu;
	Encoder *enc;
	SerialPort *serialPort;
	bool firstIteration;

public:
	Robot() :
		myRobot(0, 1),	// these must be initialized in the same order
		rStick(1),		// as they are declared above.
		lStick(0),
		lw(NULL)
	{
		myRobot.SetExpiration(0.1);
	}

private:
	void RobotInit()
	{
		enc = new Encoder(1,2);
		enc->Reset();
		serialPort = new SerialPort(57600,SerialPort::kMXP);
		uint8_t updateRateHz = 50;
		imu = new IMU(serialPort, updateRateHz);
		lw = LiveWindow::GetInstance();
		if(imu)
		{
			lw->AddSensor("IMU" ,"Gyro", imu);
		}
		lw->AddSensor("Encoder", "Encoder", enc);
		firstIteration = true;
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		if(firstIteration)
		{
			bool isCalibrating = imu->IsCalibrating();
			if(!isCalibrating)
			{
				Wait(.03);
				imu->ZeroYaw();
				firstIteration = false;
			}
		}
		SmartDashboard::PutNumber("Encoder", enc->Get());
		SmartDashboard::PutBoolean( "IMU_Connected", imu->IsConnected());
		SmartDashboard::PutNumber("IMU_Yaw", imu->GetYaw());
		SmartDashboard::PutNumber("IMU_Pitch", imu->GetPitch());
		SmartDashboard::PutNumber("IMU_Roll", imu->GetRoll());
		SmartDashboard::PutNumber("IMU_CompassHeading", imu->GetCompassHeading());
		SmartDashboard::PutNumber("IMU_Update_Count", imu->GetUpdateCount());
		SmartDashboard::PutNumber("IMU_Byte_Count", imu->GetByteCount());
		myRobot.TankDrive(lStick, rStick); // drive with arcade style (use right stick)
		Wait(.1);
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
