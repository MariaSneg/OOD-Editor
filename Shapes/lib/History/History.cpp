#include "History.h"

void History::AddMemento(const Memento& memento)
{
	m_mementos.push_back(memento);
}

Memento History::Undo()
{
	Memento memento = m_mementos.back();
	m_mementos.pop_back();
	return memento;
}

bool History::IsEmpty()
{
	return m_mementos.empty();
}


