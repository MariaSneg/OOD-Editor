#ifndef IWRITETOFILESTRATEGY_H
#define IWRITETOFILESTRATEGY_H

#include <fstream>

class IWriteToFileStrategy
{
public:
	virtual void Write() = 0;
};
#endif