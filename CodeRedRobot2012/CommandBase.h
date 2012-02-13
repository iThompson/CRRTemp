#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "OI.h"
#include "Subsystems/Acquirer.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Loader.h"
#include "Subsystems/Gate.h"
#include "Subsystems/Vision.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static Acquirer *acquirer;
	static Drive *drive;
	static Shooter *shooter;
	static Loader *loader;
	static Gate *gate;
	static Vision *vision;
};

#endif
