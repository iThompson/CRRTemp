#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class KitBot2011 : public SimpleRobot
{
	CANJaguar lJagA;
	CANJaguar lJagB;
	CANJaguar rJagA;
	CANJaguar rJagB;
	Joystick stick1; // only joystick
	Joystick stick2;
	Solenoid Sol1;
	Solenoid Sol2;
	Solenoid Sol3;
	Solenoid Sol4;
	Solenoid Sol5;
	
	AnalogChannel dist;

public:
	KitBot2011(void):
		lJagA(2),
		lJagB(3),
		rJagA(4),
		rJagB(5),	// these must be initialized in the same order
		stick1(1),
		stick2(2),
		Sol1(1),
		Sol2(2),
		Sol3(3),
		Sol4(4),
		Sol5(5),
		dist(1)     // as they are declared above.
	{
		
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)
	{
//		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			double distance = dist.GetVoltage() / (5.0 / 512.0);
			SmartDashboard::Log(distance, "Rangefinder distance");
			SmartDashboard::Log(dist.GetVoltage(), "Rangefinder voltage");
			
			Sol1.Set(stick1.GetRawButton(1));
			Sol2.Set(stick1.GetRawButton(2));
			Sol3.Set(stick1.GetRawButton(3));
			Sol4.Set(stick1.GetRawButton(4));
			Sol5.Set(stick1.GetRawButton(5));
			
			
//			myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
			lJagA.Set(stick1.GetY());
			lJagB.Set(stick1.GetY());
			rJagA.Set(stick2.GetY());
			rJagB.Set(stick2.GetY());
			Wait(0.010);				// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(KitBot2011);

