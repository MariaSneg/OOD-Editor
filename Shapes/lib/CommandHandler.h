#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <cassert>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "PerimeterAreaDecorator/IPerimeterAreaDecorator.h"
#include "Shape/IShape.h"
#include "Composite/Composite.h"
#include "Toolbar.h"
#include "State/IState.h"
#include "History/History.h"

class CommandHandler
{
public:
    static CommandHandler* GetInstance(sf::RenderWindow* window, std::ifstream& input, std::ofstream& output);
    static void AddShape(IDrawDecorator* shape);
    static void SetShapes(std::vector<IDrawDecorator*> shapes);
    static std::vector<IDrawDecorator*>& GetShapes();
    static void ChangeState(IState* state);
    static std::string GetStateName();
    static IState* GetState();
    static void Save();
    void ReadShapes();
    void PrintShapes();
    void DrawShapes();
    void MoveShapes();
    void EventHandle(sf::Event event);
    void UngroupShapes();
    void Undo();
    Composite* FindSelectedComposite();
    void UngroupComposite(Composite* composite);
    void GroupShapes();
    Composite* CreateCompositeFromSelectedShapes();
private:
    CommandHandler(sf::RenderWindow* window, std::ifstream& input, std::ofstream& output);

    void AddCircle();
    void AddTriangle();
    void AddRectangle();

    sf::RenderWindow* m_window;
    std::ifstream& m_input;
    std::ofstream& m_output;
    Toolbar m_toolbar;
    static History m_history;
    static IState* m_state;
    static std::vector<IDrawDecorator*> m_drawDecorators;
    static std::vector<IPerimeterAreaDecorator*> m_mathDecorators;
    bool isDragging = false;

    static CommandHandler* m_commandHandler;
};

#endif
