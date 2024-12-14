#include "Memento.h"

Memento::Memento(std::vector<IDrawDecorator*>& drawDecorators)
{
	for (auto& shape : drawDecorators)
	{
		IDrawDecorator* newShape = dynamic_cast<IDrawDecorator*>(shape->CopyShape());
		m_drawDecorators.push_back(newShape);
	}
}

std::vector<IDrawDecorator*> Memento::GetState()
{
	return m_drawDecorators;
}
