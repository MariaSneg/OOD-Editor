#ifndef LOADSHAPECOMMAND_H
#define LOADSHAPECOMMAND_H

#include"../ICommand.h"
#include <SFML/Graphics.hpp>
#include "../../ShapeBuilder/ShapeDirector/ShapeDirector.h"
#include "../../ShapeLoader/ShapeLoader.h"

class LoadShapeCommand : public ICommand
{
public:
	LoadShapeCommand(ShapeLoader* loader);
	void Execute() override;
private:
	ShapeLoader* m_loader;
};
#endif