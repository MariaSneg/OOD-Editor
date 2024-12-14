#ifndef SETOUTLINECOLORBUTTON_H
#define SETOUTLINECOLORBUTTON_H

#include "../../Button.h"
class SetOutlineColorButton : public Button
{
public:
	SetOutlineColorButton(sf::Vector2f position, sf::Color color);
private:
	sf::Color m_color;
};
#endif