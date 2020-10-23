#include "player.h"
#include "Collider.h"

player::player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed):
animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	row = 0 ;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 118.0f));
	body.setPosition(20.0f,785.0f);
	body.setTexture(texture);
}

player::~player()
{

}

void player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
		movement.x -= speed * deltaTime;	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;
	if (movement.x == 0.0f) 
	{
		row = 0;
	}
	else
	{
		row = 5;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
