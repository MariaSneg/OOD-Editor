#ifndef MEMENTO_H
#define MEMENTO_H

#include "../DrawDecorator/IDrawDecorator.h"

class Memento
{
public:
    Memento(std::vector<IDrawDecorator*>& drawDecorators);
    std::vector<IDrawDecorator*> GetState();
private:
    std::vector<IDrawDecorator*> m_drawDecorators;
};
#endif 

