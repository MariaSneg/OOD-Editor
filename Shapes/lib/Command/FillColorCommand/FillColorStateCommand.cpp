#include "FillColorStateCommand.h"
#include "../../CommandHandler.h"
#include "../../State/FillColorState.h"

void FillColorStateCommand::Execute()
{
	CommandHandler::ChangeState(new FillColorState());
}
