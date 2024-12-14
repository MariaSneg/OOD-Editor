#ifndef BINLOUDSHAPEBUTTON_H
#define BINLOUDSHAPEBUTTON_H

#include "../Button.h"
class BinLoadShapeButton : public Button
{
public:
	BinLoadShapeButton(sf::Vector2f position);
private:
	sf::Texture* m_texture;
};
#endif