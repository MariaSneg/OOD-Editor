#ifndef DRAGANDDROPBUTTON_H
#define DRAGANDDROPBUTTON_H

#include "../Button.h"
class DragAndDropButton : public Button
{
public:
	DragAndDropButton(sf::Vector2f position);
	void Draw(sf::RenderWindow* window) override;
private:
	sf::Texture* m_texture;
	bool m_isSelected = false;
};
#endif