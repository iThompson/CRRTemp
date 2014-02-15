#include "WPILib.h"
#include "PIDJaguar.h"
#include "LiveWindow/LiveWindow.h"
#include <math.h>

#define TIME_THRESH_1 .2
#define TIME_THRESH_2 .4

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
	Joystick ostick;
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
	//	GearTooth gears;
	Solenoid Shift;
	Solenoid Shoot1;
	Solenoid Shoot2;
	Solenoid Acq;
	Solenoid Kicker;
	
	bool lastPressed;
	bool acqState;

	Timer mtrTime;

public:
	RobotDemo(void):
		lstick(1),		// as they are declared above.
		rstick(2),
		ostick(3),
		//left(1,2),		// Raptor other
		//right(1,1),
		rollers(1,1),
		Jag1(2),		// Kitbot
		Jag2(3),
		Jag3(4),		// Raptor drive
		Jag4(5),
		Jag5(6),
		Jag6(7),
		comp(1,1),
		Shift(1,1),
		Shoot1(1,2),
		Shoot2(1,3),
		Acq(1,4),
		Kicker(1,5)
	//		GearTooth(1,1)
	{
		comp.Start();
		SmartDashboard::init();

		mtrTime.Start();
		mtrTime.Reset();

		Jag1.ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		Jag2.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		Jag3.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		Jag4.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		Jag5.ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		Jag6.ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);

		SmartDashboard::PutBoolean("Control Mtr L 1", false);
		SmartDashboard::PutBoolean("Control Mtr L 2", false);
		SmartDashboard::PutBoolean("Control Mrt L 3", false);
		SmartDashboard::PutBoolean("Control Mtr R 1", false);
		SmartDashboard::PutBoolean("Control Mtr R 2", false);
		SmartDashboard::PutBoolean("Control Mrt R 3", false);
		
		acqState = true;
		lastPressed = false;
		
		Acq.Set(acqState);
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
			if(Jag1.Get()*lstick.GetY() <= 0 || Jag6.Get()*-rstick.GetY() <= 0) mtrTime.Reset();
			Jag1.Set(lstick.GetY());
			Jag6.Set(-rstick.GetY());
			if(mtrTime.Get() > TIME_THRESH_1)
			{
				Jag2.Set(lstick.GetY());
				Jag5.Set(-rstick.GetY());
			}
			else
			{
				Jag2.Set(0);
				Jag5.Set(0);
			}
			if(mtrTime.Get() > TIME_THRESH_2)
			{
				Jag3.Set(lstick.GetY());
				Jag4.Set(-rstick.GetY());
			}
			else
			{
				Jag3.Set(0);
				Jag4.Set(0);
			}
			
			SmartDashboard::PutNumber("ostickY", ostick.GetY());
			if(ostick.GetZ() < .2 && ostick.GetZ() > -.2) rollers.Set(0);
			else rollers.Set(ostick.GetZ());
			Shift.Set(lstick.GetRawButton(1));
			Shoot1.Set(lstick.GetRawButton(2));
			Shoot2.Set(lstick.GetRawButton(2));
			Kicker.Set(lstick.GetRawButton(4));
			
			if(lstick.GetRawButton(3)  && !lastPressed) // Should mean that button just pressed
			{
				acqState = !acqState;
				if(acqState)
				{
					Acq.Set(1);
					Wait(.275);
					Acq.Set(0);
					Wait(.25);
					Acq.Set(1);
				}
				else 
				{
					Acq.Set(0);
					Wait(.8);
					Acq.Set(1);
					Wait(.1);
					Acq.Set(0);
				}
			}
			lastPressed = lstick.GetRawButton(3);

//			Shift.Set(0);
//			Shoot1.Set(0);
//			Shoot2.Set(0);
//			Kicker.Set(0);
//			Acq.Set(0);
			
			SmartDashboard::PutNumber("Josytick Y", lstick.GetY());
			SmartDashboard::PutNumber("Josytick Z", lstick.GetZ());

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

