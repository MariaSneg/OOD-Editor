#include <string>
#include "../DrawDecorator/IDrawDecorator.h"
#include "ShapeLoader.h"
#include "../ShapeBuilder/ShapeDirector/ShapeDirector.h"
#ifndef BINSHAPELOADER_H
#define BINSHAPELOADER_H

class BinShapeLoader : public ShapeLoader
{
public:
	BinShapeLoader(std::string fileName);
	std::vector<std::string> Read() override;
	void Parse(std::vector<std::string> data) override;
	void AddCircle(std::istringstream& line);
	void AddTriangle(std::istringstream& line);
	void AddRectangle(std::istringstream& line);
};
#endif