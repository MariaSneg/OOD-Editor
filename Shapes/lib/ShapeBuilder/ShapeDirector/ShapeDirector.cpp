#include "ShapeDirector.h"

void ShapeDirector::MakeCircle(CircleBuilder& builder)
{
	builder.Make();
}

void ShapeDirector::MakeRectangle(RectangleBuilder& builder)
{
	builder.Make();
}

void ShapeDirector::MakeTriangle(TriangleBuilder& builder)
{
	builder.Make();
}
