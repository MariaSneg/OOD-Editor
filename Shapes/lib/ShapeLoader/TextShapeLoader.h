#include <string>
#include "../DrawDecorator/IDrawDecorator.h"
#include "ShapeLoader.h"
#ifndef TEXTSHAPELOADER_H
#define TEXTSHAPELOADER_H

class TextShapeLoader : public ShapeLoader
{
public:
	TextShapeLoader(std::string fileName);
	std::vector<std::string> Read() override;
	void Parse(std::vector<std::string> data) override;
	void AddCircle(std::istringstream& ss);
	void AddTriangle(std::istringstream& ss);
	void AddRectangle(std::istringstream& ss);
};
#endif