#include "DragAndDropState.h"
#include "../DrawDecorator/WithFrameDecorator.h"
#include "../DrawDecorator/WithoutFrameDecorator.h"

void DragAndDropState::Select(sf::RenderWindow* window)
{
	for (auto& shape : m_shapes)
	{
        if (!shape->IsComposite())
        {
            if (shape->Select(sf::Vector2f(sf::Mouse::getPosition(*window)), false))
            {
                shape = new WithFrameDecorator(shape->GetShape());
            }
            else
            {
                shape = new WithoutFrameDecorator(shape->GetShape());
            }
        }
        else
        {
            shape->Select(sf::Vector2f(sf::Mouse::getPosition(*window)), false);
        }
        shape->SetIsMoved(sf::Vector2f(sf::Mouse::getPosition(*window)), false);
	}
}
