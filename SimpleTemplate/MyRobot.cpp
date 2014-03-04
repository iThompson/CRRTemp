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
	Joystick lstick; 	// left joystick
	Joystick rstick; 	// right joystick
	Victor left;		// Raptor or Kitbot
	Victor right;		// Raptor or Kitbot
	Compressor comp;	

public:
	RobotDemo(void):
		lstick(1),		// as they are declared above.
		rstick(2),
		left(1,2),
		right(1,1),
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
			left.Set(lstick.GetY());	
			right.Set(-rstick.GetY());
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
