#include <string>
#include "IBuilder.h"
#ifndef BUILDER_H
#define BUILDER_H

class Builder : public IBuilder
{
public:
	Builder(std::istringstream& data);
	void Make() override;
	IDrawDecorator* GetResult() override;
protected:
	std::istringstream& m_data;
	IDrawDecorator* m_drawDecorator;
};
#endif