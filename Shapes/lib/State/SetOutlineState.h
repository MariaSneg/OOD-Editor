#ifndef SETOUTLINESTATE_H
#define SETOUTLINESTATE_H

#include "State.h"

class SetOutlineState : public State
{
public:
	void SetOutline(sf::RenderWindow* window) override;
	void SetColor(sf::Color color);
	void SetThicness(int thickness);
private:
	sf::Color m_color = sf::Color::Blue;
	int m_thickness = 5;
};
#endif