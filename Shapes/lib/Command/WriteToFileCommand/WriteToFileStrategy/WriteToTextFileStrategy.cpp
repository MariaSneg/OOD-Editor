#include "WriteToTextFileStrategy.h"
#include "../../../CommandHandler.h"

WriteToTextFileStrategy::WriteToTextFileStrategy(std::string fileName)
	:m_fileName(fileName)
{
}

void WriteToTextFileStrategy::Write()
{
	std::ofstream out(m_fileName);
	out.clear();
	for (auto shape : CommandHandler::GetShapes())
	{
		out << shape->ToString();
	}
}
