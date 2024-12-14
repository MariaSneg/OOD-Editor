#ifndef FILLCOLORSTATECOMMAND_H
#define FILLCOLORSTATECOMMAND_H

#include"../ICommand.h"

class FillColorStateCommand : public ICommand
{
public:
	void Execute() override;
};
#endif