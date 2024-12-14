#ifndef SHAPEDIRECTOR_H
#define SHAPEDIRECTOR_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "../CircleBuilder.h"
#include "../RectangleBuilder.h"
#include "../TriangleBuilder.h"

class ShapeDirector
{
public:
	void MakeCircle(CircleBuilder& builder);
	void MakeRectangle(RectangleBuilder& builder);
	void MakeTriangle(TriangleBuilder& builder);
};
#endif
