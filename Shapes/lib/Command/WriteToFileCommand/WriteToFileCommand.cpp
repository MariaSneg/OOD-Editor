#include "WriteToFileCommand.h"

WriteToFileCommand::WriteToFileCommand(IWriteToFileStrategy* strategy)
	:m_strategy(strategy)
{
}

void WriteToFileCommand::Execute()
{
	m_strategy->Write();
}
