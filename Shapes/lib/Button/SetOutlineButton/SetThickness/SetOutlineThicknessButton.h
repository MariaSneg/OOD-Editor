#ifndef SETOUTLINETHICKNESSBUTTON_H
#define SETOUTLINETHICKNESSBUTTON_H

#include "../../Button.h"
class SetOutlineThicknessButton : public Button
{
public:
	SetOutlineThicknessButton(sf::Vector2f position, int thickness);
private:
	int m_thickness;
};
#endif