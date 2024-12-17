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

void ShapeLoader::AddCircle(std::istringstream& ss)
{
    CircleBuilder builder = CircleBuilder(ss);
    m_director.MakeCircle(builder);
    if (m_isComposite)
    {
        m_composite->Add(builder.GetResult());
        return;
    }
    m_shapes.push_back(builder.GetResult());
}

void ShapeLoader::AddTriangle(std::istringstream& ss)
{
    TriangleBuilder builder = TriangleBuilder(ss);
    m_director.MakeTriangle(builder);
    if (m_isComposite)
    {
        m_composite->Add(builder.GetResult());
        return;
    }
    m_shapes.push_back(builder.GetResult());
}

void ShapeLoader::AddRectangle(std::istringstream& ss)
{
    RectangleBuilder builder = RectangleBuilder(ss);
    m_director.MakeRectangle(builder);
    if (m_isComposite)
    {
        m_composite->Add(builder.GetResult());
        return;
    }
    m_shapes.push_back(builder.GetResult());
}

void ShapeLoader::AddComposite()
{
    m_isComposite = false;
    m_shapes.push_back(m_composite);
    m_composite = new Composite();
}

void ShapeLoader::CreateComposite()
{
    m_isComposite = true;
}