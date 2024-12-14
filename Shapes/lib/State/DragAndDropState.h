#ifndef SELECTSTATE_H
#define SELECTSTATE_H

#include "State.h"

class DragAndDropState : public State
{
public:
	void Select(sf::RenderWindow* window) override;
};
#endif