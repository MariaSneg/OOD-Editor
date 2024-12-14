#include "BinShapeLoader.h"
#include <map>
#include <sstream>

std::map<std::string, int> binShapeLoaderMap
{
    {"CIRCLE", 1},
    {"TRIANGLE", 2},
    {"RECTANGLE", 3}
};

BinShapeLoader::BinShapeLoader(std::string fileName)
    :ShapeLoader(fileName)
{
}

std::vector<std::string> BinShapeLoader::Read()
{
    std::vector<std::string> data;
    std::ifstream in(m_fileName, std::ios::binary); 

    const size_t bufferSize = 1024;
    char buffer[bufferSize];

    while (in.read(buffer, bufferSize) || in.gcount() > 0) 
    {
        size_t bytesRead = in.gcount();
        std::string str(buffer, bytesRead);  

        size_t pos = 0;
        while ((pos = str.find('\n')) != std::string::npos) {
            data.push_back(str.substr(0, pos)); 
            str.erase(0, pos + 1);  
        }

        if (!str.empty()) {
            data.push_back(str);
        }
    }

    in.close();
    return data;
}

void BinShapeLoader::Parse(std::vector<std::string> data)
{
    for (std::string line : data) {
        std::istringstream ss(line);
        std::getline(ss, line, ':');
        switch (binShapeLoaderMap.at(line)) {
        case 1: AddCircle(ss); break;
        case 2: AddTriangle(ss); break;
        case 3: AddRectangle(ss); break;
        }
    }
}

void BinShapeLoader::AddCircle(std::istringstream& line)
{
    CircleBuilder builder = CircleBuilder(line);
    m_director.MakeCircle(builder);
    m_shapes.push_back(builder.GetResult());
}

void BinShapeLoader::AddTriangle(std::istringstream& line)
{
    TriangleBuilder builder = TriangleBuilder(line);
    m_director.MakeTriangle(builder);
    m_shapes.push_back(builder.GetResult());
}

void BinShapeLoader::AddRectangle(std::istringstream& line)
{
    RectangleBuilder builder = RectangleBuilder(line);
    m_director.MakeRectangle(builder);
    m_shapes.push_back(builder.GetResult());
}
