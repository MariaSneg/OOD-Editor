#ifndef NEWRECTANGLECOMMAND_H
#define NEWRECTANGLECOMMAND_H

#include"../ICommand.h"

class NewRectangleCommand : public ICommand
{
public:
	void Execute() override;
};
#endif