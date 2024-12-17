#include "TextShapeLoader.h"
#include <map>
#include <sstream>

std::map<std::string, int> textShapeLoaderMap
{
    {"CIRCLE", 1},
    {"TRIANGLE", 2},
    {"RECTANGLE", 3},
    {"COMPOSITE", 4},
    {"END", 5}
};

TextShapeLoader::TextShapeLoader(std::string fileName)
    :ShapeLoader(fileName)
{
}

std::vector<std::string> TextShapeLoader::Read()
{
    std::vector<std::string> data;

    std::ifstream in(m_fileName);
    std::string line;
    while (std::getline(in, line))
    {
        data.push_back(line);
    }
    return data;
}

void TextShapeLoader::Parse(std::vector<std::string> data)
{
    for (std::string line : data) {
        std::istringstream ss(line);
        std::getline(ss, line, ':');
        switch (textShapeLoaderMap.at(line)) {
        case 1: AddCircle(ss); break;
        case 2: AddTriangle(ss); break;
        case 3: AddRectangle(ss); break;
        case 4: CreateComposite(); break;
        case 5: AddComposite(); break;
        }
    }
}
