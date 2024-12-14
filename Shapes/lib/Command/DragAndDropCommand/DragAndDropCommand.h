#ifndef DRAGANDDROPCOMMAND_H
#define DRAGANDDROPCOMMAND_H

#include"../ICommand.h"

class DragAndDropCommand : public ICommand
{
public:
	void Execute() override;
};
#endif