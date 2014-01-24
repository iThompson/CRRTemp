#include "WPILib.h"
#include "PIDJaguar.h"
#include "LiveWindow/LiveWindow.h"
#include <math.h>

#define SOL_WAIT_TIME .5

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */
class RobotDemo : public SimpleRobot
{
	Joystick lstick; 	// left joystick
	Joystick rstick; 	// right joystick
	Victor left;		// Raptor Drive
	Victor right;		// Raptor Drive
	Jaguar Jag1;		// Kitbot
	Jaguar Jag2;		// Kitbot
	CANJaguar Jag3;		// Raptor other
	CANJaguar Jag4;		// Raptor other
	Solenoid Sol1;		// Pneumatics Testing
	Solenoid Sol2;
	Compressor comp;	

public:
	RobotDemo(void):
		lstick(1),		// as they are declared above.
		rstick(2),
		left(1,2),		// Raptor other
		right(1,1),
		Jag1(3),		// Kitbot
		Jag2(4),
		Jag3(7),		// Raptor drive
		Jag4(8),		
		Sol1(1),
		Sol2(2),
		comp(1,1)
	{
//		comp.Start();
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
//			Jag1.Set(lstick.GetY());	// Kitbot
//			Jag2.Set(-rstick.GetY());	
//			Jag3.Set(lstick.GetY());	// Raptor other
//			Jag4.Set(-rstick.GetY());	
			if(lstick.GetZ() <= .5)
			{
				Sol1.Set(lstick.GetTrigger());
				Sol2.Set(lstick.GetTrigger());
			}
			else 
			{
				if (lstick.GetTrigger())
				{
					Sol1.Set(1);
					Sol2.Set(1);
					Wait(SOL_WAIT_TIME);
					Sol1.Set(0);
					Sol2.Set(0);
				}
			}
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

