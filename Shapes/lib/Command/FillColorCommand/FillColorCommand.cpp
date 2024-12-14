#include "FillColorCommand.h"
#include "../../CommandHandler.h"
#include "../../State/FillColorState.h"

FillColorCommand::FillColorCommand(sf::Color color)
	:m_color(color)
{
}

void FillColorCommand::Execute()
{
	auto state = dynamic_cast<FillColorState*>(CommandHandler::GetState());
	state->SetColor(m_color);
}
