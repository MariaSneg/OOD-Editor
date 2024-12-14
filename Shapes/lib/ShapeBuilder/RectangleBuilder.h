#include <string>
#include "Builder.h"
#include "../Shape/Rectangle.h"
#ifndef RECTANGLEBUILDER_H
#define RECTANGLEBUILDER_H

class RectangleBuilder : public Builder
{
public:
	RectangleBuilder(std::istringstream& data);
	void ParseString() override;
	void AddDecorators() override;
private:
	Rectangle* m_rectangle;
};
#endif