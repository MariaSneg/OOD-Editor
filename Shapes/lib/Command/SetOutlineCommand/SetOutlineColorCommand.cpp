#include "SetOutlineColorCommand.h"
#include "../../CommandHandler.h"
#include "../../State/SetOutlineState.h"

SetOutlineColorCommand::SetOutlineColorCommand(sf::Color color)
	:m_color(color)
{
}

void SetOutlineColorCommand::Execute()
{
	SetOutlineState* state = dynamic_cast<SetOutlineState*>(CommandHandler::GetState());
	state->SetColor(m_color);
}
