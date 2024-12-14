#include <SFML/Graphics.hpp>
#include <iostream>
#include "lib/CommandHandler.h"

const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";
const std::string ERROE_OPEN_INPUT_FILE = "Failed to open input.txt for reading\n";
const std::string ERROE_OPEN_OUTPUT_FILE = "Failed to open output.txt for writing\n";
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const sf::String WINDOW_NAME = L"Shapes";

int main()
{
    auto window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Default);
    window->setVerticalSyncEnabled(true);

    std::ifstream input(INPUT_FILE_NAME);

    if (!input.is_open())
    {
        std::cout << ERROE_OPEN_INPUT_FILE;
        return 1;
    }

    std::ofstream output(OUTPUT_FILE_NAME);
    if (!output.is_open())
    {
        std::cout << ERROE_OPEN_OUTPUT_FILE;
        return 1;
    }

    CommandHandler* handler = CommandHandler::GetInstance(window, input, output);

    handler->ReadShapes();

    handler->PrintShapes();

    handler->DrawShapes();

    return 0;
}