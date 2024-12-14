#ifndef FILLCOLORSTATEBUTTON_H
#define FILLCOLORSTATEBUTTON_H

#include "../Button.h"
class FillColorStateButton : public Button
{
public:
	FillColorStateButton(sf::Vector2f position);
	void Draw(sf::RenderWindow* window) override;
private:
	sf::Texture* m_texture;
};
#endif