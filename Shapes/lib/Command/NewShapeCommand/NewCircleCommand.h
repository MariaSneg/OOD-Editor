#ifndef NEWCIRCLECOMMAND_H
#define NEWCIRCLECOMMAND_H

#include"../ICommand.h"

class NewCircleCommand : public ICommand
{
public:
	void Execute() override;
};
#endif