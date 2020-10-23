#pragma once
#include"player.h"
#include <SFML/Graphics.hpp>
class Collider
{

public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }
	bool CheckCollision(Collider& other, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize(); }

private:
	sf::RectangleShape& body;

};