#include "LoadShapeCommand.h"
#include "../../CommandHandler.h"

LoadShapeCommand::LoadShapeCommand(ShapeLoader* loader)
	:m_loader(loader)
{
}

void LoadShapeCommand::Execute()
{
	auto data = m_loader->Load();
	CommandHandler::SetShapes(data);
}
