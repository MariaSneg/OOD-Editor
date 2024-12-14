#include <string>
#include "../DrawDecorator/IDrawDecorator.h"
#include "../ShapeBuilder/ShapeDirector/ShapeDirector.h"
#ifndef SHAPELOADER_H
#define SHAPELOADER_H

class ShapeLoader
{
public:
	ShapeLoader(std::string fileName);
	std::vector<IDrawDecorator*> Load();
	virtual std::vector<std::string> Read() = 0;
	virtual void Parse(std::vector<std::string> data) = 0;
protected:
	std::vector<IDrawDecorator*> m_shapes;
	ShapeDirector m_director;
	std::string m_fileName;
};
#endif