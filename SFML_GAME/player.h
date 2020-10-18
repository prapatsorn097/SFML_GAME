#pragma once
#include<SFML\Graphics.hpp>
#include "Animation.h"
class player
{
public:
	player();
	~player();
	void Update(int row, float deltaTime, bool faceRight);
	void Draw(sf::RenderWindow window);
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;


};

