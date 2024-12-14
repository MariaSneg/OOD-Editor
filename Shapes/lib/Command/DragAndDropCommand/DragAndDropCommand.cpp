#include "DragAndDropCommand.h"
#include "../../CommandHandler.h"
#include "../../State/DragAndDropState.h"

void DragAndDropCommand::Execute()
{
	CommandHandler::ChangeState(new DragAndDropState());
}
