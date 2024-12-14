#ifndef WRITETOBINFILEBUTTON_H
#define WRITETOBINFILEBUTTON_H

#include "../Button.h"
class WriteToBinFileButton : public Button
{
public:
	WriteToBinFileButton(sf::Vector2f position);
private:
	sf::Texture* m_texture;
};
#endif