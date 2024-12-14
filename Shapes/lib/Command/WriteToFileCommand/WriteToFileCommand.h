#ifndef WRITETOFILECOMMAND_H
#define WRITETOFILECOMMAND_H

#include"../ICommand.h"
#include <SFML/Graphics.hpp>
#include "WriteToFileStrategy/IWriteToFileStrategy.h"

class WriteToFileCommand : public ICommand
{
public:
	WriteToFileCommand(IWriteToFileStrategy* strategy);
	void Execute() override;
private:
	IWriteToFileStrategy* m_strategy;
};
#endif