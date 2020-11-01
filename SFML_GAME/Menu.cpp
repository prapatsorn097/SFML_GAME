#include "Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("font/arial.ttf"))
        printf("LOAD MAI DAI I SUS");

    //Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::Blue);
    mainMenu[0].setString("PLAY");
    mainMenu[0].setCharacterSize(60);
    mainMenu[0].setPosition(940, 100);

    //Score
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("SCORE");
    mainMenu[1].setCharacterSize(40);
    mainMenu[1].setPosition(940, 200);

    //Quit
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("QUIT");
    mainMenu[2].setCharacterSize(40);
    mainMenu[2].setPosition(940, 300);

    mainMenuSelected = 0;

}

Menu::~Menu()
{

}

//Draw MainMenu
void Menu::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < 3; i++)
    {
        window.draw(mainMenu[i]);
    }
}

//move up
void Menu::moveUp()
{
    if (mainMenuSelected - 1 >= -1)
    {
        mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

        mainMenuSelected--;
        if (mainMenuSelected == -1)
        {
            mainMenuSelected = 2;
        }
        mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);
    }
}

//move down
void Menu::moveDown()
{
    if (mainMenuSelected + 1 <= Max_main_menu)
    {
        mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

        mainMenuSelected++;
        if (mainMenuSelected == 3)
        {
            mainMenuSelected = 0;
        }
        mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);
    }
}