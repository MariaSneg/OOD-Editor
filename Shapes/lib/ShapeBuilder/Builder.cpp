#include "Builder.h"

Builder::Builder(std::istringstream& data)
	:m_data(data)
{
}

void Builder::Make()
{
	ParseString();
	AddDecorators();
}

IDrawDecorator* Builder::GetResult()
{
	return m_drawDecorator;
}
