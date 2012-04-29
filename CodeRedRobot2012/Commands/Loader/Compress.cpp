#include "Compress.h"

Compress::Compress(bool shouldLog) :
									m_logging(shouldLog)
{
	Requires(loader);
	
//	m_log = ShotLogger::GetInstance();
}

// Called just before this Command runs the first time
void Compress::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Compress::Execute() {
	loader->CompressTest();
//	if (m_logging) {
//		m_log->Compression(loader->GetCompression());
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool Compress::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Compress::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Compress::Interrupted() {
}
