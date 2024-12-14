#include "ShapeLoader.h"

ShapeLoader::ShapeLoader(std::string fileName)
	:m_fileName(fileName)
{
}

std::vector<IDrawDecorator*> ShapeLoader::Load()
{
	m_shapes.clear();
	std::vector<std::string> data = Read();
	Parse(data);
	return m_shapes;
}
