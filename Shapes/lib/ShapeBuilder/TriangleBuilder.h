#include <string>
#include "Builder.h"
#include "../Shape/Triangle.h"
#ifndef TRIANGLEBUILDER_H
#define TRIANGLEBUILDER_H

class TriangleBuilder : public Builder
{
public:
	TriangleBuilder(std::istringstream& data);
	void ParseString() override;
	void AddDecorators() override;
private:
	Triangle* m_triangle;
};
#endif