#ifndef NEWTRIANGLECOMMAND_H
#define NEWTRIANGLECOMMAND_H

#include"../ICommand.h"

class NewTriangleCommand : public ICommand
{
public:
	void Execute() override;
};
#endif
