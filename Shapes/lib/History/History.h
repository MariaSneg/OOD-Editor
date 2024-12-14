#ifndef HISTORY_H
#define HISTORY_H

#include "Memento.h"

class History  
{
public:
    void AddMemento(const Memento& memento);
    Memento Undo();
    bool IsEmpty();
private:
    std::vector<Memento> m_mementos;
};
#endif 

