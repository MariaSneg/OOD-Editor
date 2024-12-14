#include "SetOutlineThicknessCommand.h"
#include "../../CommandHandler.h"
#include "../../State/SetOutlineState.h"

SetOutlineThicknessCommand::SetOutlineThicknessCommand(int thickness)
	:m_thickness(thickness)
{
}

void SetOutlineThicknessCommand::Execute()
{
	SetOutlineState* state = dynamic_cast<SetOutlineState*>(CommandHandler::GetState());
	state->SetThicness(m_thickness);
}
