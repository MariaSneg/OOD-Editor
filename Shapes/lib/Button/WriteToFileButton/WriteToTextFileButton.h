#ifndef WRITETOTEXTFILEBUTTON_H
#define WRITETOTEXTFILEBUTTON_H

#include "../Button.h"
class WriteToTextFileButton : public Button
{
public:
	WriteToTextFileButton(sf::Vector2f position);
private:
	sf::Texture* m_texture;
};
#endif