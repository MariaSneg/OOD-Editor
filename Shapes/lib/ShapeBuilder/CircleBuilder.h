#include <string>
#include "Builder.h"
#include "../Shape/Circle.h"
#ifndef CIRCLEBUILDER_H
#define CIRCLEBUILDER_H

class CircleBuilder : public Builder
{
public:
	CircleBuilder(std::istringstream& data);
	void ParseString() override;
	void AddDecorators() override;
private:
	Circle* m_circle;
};
#endif