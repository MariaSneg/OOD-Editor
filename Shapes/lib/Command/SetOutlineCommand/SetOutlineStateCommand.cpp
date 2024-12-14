#include "SetOutlineStateCommand.h"
#include "../../CommandHandler.h"
#include "../../State/SetOutlineState.h"

void SetOutlineStateCommand::Execute()
{
	CommandHandler::ChangeState(new SetOutlineState());
}
