#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
/*
Class that acts as the game engin.
wrapp
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;


	//Private Function
	void initVariables();
	void initWindow();
public: 
	//Constructor / Destructors
	Game();
	virtual ~Game();
	
	//Functions
	void update();
	{

	}
	void render();
};
