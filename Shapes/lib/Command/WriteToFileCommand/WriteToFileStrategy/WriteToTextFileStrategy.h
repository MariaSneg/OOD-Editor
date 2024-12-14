#ifndef IWRITETOTEXTFILESTRATEGY_H
#define IWRITETOTEXTFILESTRATEGY_H

#include <fstream>
#include "IWriteToFileStrategy.h"

class WriteToTextFileStrategy : public IWriteToFileStrategy
{
public:
	WriteToTextFileStrategy(std::string fileName);
	void Write() override;
private:
	std::string m_fileName;
};
#endif