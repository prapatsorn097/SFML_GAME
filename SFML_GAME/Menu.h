#pragma once
#include <SFML/Graphics.hpp>
#define Max_main_menu 3
class Menu
{
public:
    Menu(float width, float height);

    void Draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();

    int mainMenuPressed()
    {
        return mainMenuSelected;
    }
    ~Menu();

private:
    int mainMenuSelected;
    sf::Font font;
    sf::Text mainMenu[Max_main_menu];
};