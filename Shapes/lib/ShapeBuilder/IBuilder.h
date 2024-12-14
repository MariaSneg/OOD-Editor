#include <string>
#include "../DrawDecorator/IDrawDecorator.h"
#ifndef IBUILDER_H
#define IBUILDER_H

class IBuilder
{
public:
	virtual void Make() = 0;
	virtual void ParseString() = 0;
	virtual void AddDecorators() = 0;
	virtual IDrawDecorator* GetResult() = 0;
};
#endif