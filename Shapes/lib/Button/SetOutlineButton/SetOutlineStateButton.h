#ifndef SETOUTLINESTATEBUTTON_H
#define SETOUTLINESTATEBUTTON_H

#include "../Button.h"
class SetOutlineStateButton : public Button
{
public:
	SetOutlineStateButton(sf::Vector2f position);
	void Draw(sf::RenderWindow* window) override;
private:
	sf::Texture* m_texture;
};
#endif