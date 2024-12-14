#ifndef SETOUTLINESTATECOMMAND_H
#define SETOUTLINESTATECOMMAND_H

#include"../ICommand.h"

class SetOutlineStateCommand : public ICommand
{
public:
	void Execute() override;
};
#endif