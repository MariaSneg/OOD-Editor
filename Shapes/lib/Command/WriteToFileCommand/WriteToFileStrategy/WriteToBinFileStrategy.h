#ifndef IWRITETOBINFILESTRATEGY_H
#define IWRITETOBINFILESTRATEGY_H

#include <fstream>
#include "IWriteToFileStrategy.h"

class WriteToBinFileStrategy : public IWriteToFileStrategy
{
public:
	WriteToBinFileStrategy(std::string fileName);
	void Write() override;
private:
	std::string m_fileName;
};
#endif