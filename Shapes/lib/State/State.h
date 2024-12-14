#ifndef STATE_H
#define STATE_H

#include "../CommandHandler.h"
#include "IState.h"

class State : public IState
{
public:
	void Select(sf::RenderWindow* window) override;
	void SetFillColor(sf::RenderWindow* window) override;
	void SetOutline(sf::RenderWindow* window) override;
protected:
	std::vector<IDrawDecorator*>& m_shapes = CommandHandler::GetShapes();
};
#endif