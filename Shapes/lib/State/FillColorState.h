#ifndef FILLCOLORSTATE_H
#define FILLCOLORSTATE_H

#include "State.h"

class FillColorState : public State
{
public:
	void SetFillColor(sf::RenderWindow* window) override;
	void SetColor(sf::Color color);
private:
	sf::Color m_color = sf::Color::Green;
};
#endif