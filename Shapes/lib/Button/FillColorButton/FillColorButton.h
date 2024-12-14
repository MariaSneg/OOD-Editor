#ifndef FILLCOLORBUTTON_H
#define FILLCOLORBUTTON_H

#include "../Button.h"
class FillColorButton : public Button
{
public:
	FillColorButton(sf::Vector2f position, sf::Color color);
private:
	sf::Color m_color;
};
#endif