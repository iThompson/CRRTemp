#include "WPILib.h"
#include "PIDJaguar.h"
#include "LiveWindow/LiveWindow.h"
#include <math.h>


/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */
class RobotDemo : public SimpleRobot
{
	//If you see this code, replace with head revision, please
	Joystick lstick; 	// left joystick
	Joystick rstick; 	// right joystick
	//Victor left;		// Raptor Drive
	//Victor right;		// Raptor Drive
	Victor rollers;
	CANJaguar Jag1;	
	CANJaguar Jag2;		
	CANJaguar Jag3;		// Raptor other
	CANJaguar Jag4;		// Raptor other
	CANJaguar Jag5;
	CANJaguar Jag6;
	Compressor comp;	

public:
	RobotDemo(void):
		lstick(1),		// as they are declared above.
		rstick(2),
		//left(1,2),		// Raptor other
		//right(1,1),
		rollers(1,1),
		Jag1(2),		// Kitbot
		Jag2(3),
		Jag3(4),		// Raptor drive
		Jag4(5),
		Jag5(6),
		Jag6(7),
		comp(1,1)
	{
//		comp.Start();
		SmartDashboard::init();
		
		Jag1.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		Jag2.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		Jag3.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		
		SmartDashboard::PutBoolean("Control Mtr L 1", false);
		SmartDashboard::PutBoolean("Control Mtr L 2", false);
		SmartDashboard::PutBoolean("Control Mrt L 3", false);
		SmartDashboard::PutBoolean("Control Mtr R 1", false);
		SmartDashboard::PutBoolean("Control Mtr R 2", false);
		SmartDashboard::PutBoolean("Control Mrt R 3", false);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
		/*
		myRobot.SetSafetyEnabled(false);
		myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		myRobot.Drive(0.0, 0.0); 	// stop robot
		*/
	}

	void OperatorControl(void)
	{
		while (IsOperatorControl() && IsEnabled())
		{
//			left.Set(lstick.GetY());	// Raptor drive
//			right.Set(-rstick.GetY());	
//			if(SmartDashboard::GetBoolean("Control Mtr L 1"))
				Jag1.Set(lstick.GetY());
//			if(SmartDashboard::GetBoolean("Control Mtr L 2"))
				Jag2.Set(lstick.GetY());	
//			if(SmartDashboard::GetBoolean("Control Mtr L 3"))
				Jag3.Set(lstick.GetY());
//			if(SmartDashboard::GetBoolean("Control Mtr R 1"))
				Jag4.Set(-rstick.GetY());
//			if(SmartDashboard::GetBoolean("Control Mtr R 2"))
				Jag5.Set(-rstick.GetY());	
//			if(SmartDashboard::GetBoolean("Control Mtr R 3"))
				Jag6.Set(-rstick.GetY());
			if(rstick.GetZ() > .5)
				rollers.Set(lstick.GetZ());
			
			SmartDashboard::PutNumber("Mtr1 Current", Jag1.GetOutputCurrent());
			SmartDashboard::PutNumber("Mtr2 Current", Jag2.GetOutputCurrent());
			SmartDashboard::PutNumber("Mtr3 Current", Jag3.GetOutputCurrent());
			SmartDashboard::PutNumber("Mtr4 Current", Jag4.GetOutputCurrent());
			SmartDashboard::PutNumber("Mtr5 Current", Jag5.GetOutputCurrent());
			SmartDashboard::PutNumber("Mtr6 Current", Jag6.GetOutputCurrent());
			
			Wait(0.01);				// wait for a motor update time
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {
//		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(RobotDemo);

