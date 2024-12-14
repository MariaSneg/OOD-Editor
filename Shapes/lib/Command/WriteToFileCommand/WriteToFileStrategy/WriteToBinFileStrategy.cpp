#include "WriteToBinFileStrategy.h"
#include "../../../CommandHandler.h"

WriteToBinFileStrategy::WriteToBinFileStrategy(std::string fileName)
	:m_fileName(fileName)
{
}

void WriteToBinFileStrategy::Write()
{
	std::ofstream out(m_fileName, std::ios::binary);
	for (auto shape : CommandHandler::GetShapes())
	{
		out << shape->ToString();
	}
}
