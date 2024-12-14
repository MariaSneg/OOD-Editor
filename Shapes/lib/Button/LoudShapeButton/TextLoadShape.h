#ifndef TEXTLOUDSHAPEBUTTON_H
#define TEXTLOUDSHAPEBUTTON_H

#include "../Button.h"
class TextLoadShapeButton : public Button
{
public:
	TextLoadShapeButton(sf::Vector2f position);
private:
	sf::Texture* m_texture;
};
#endif