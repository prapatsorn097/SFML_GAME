#include "Player.h"
#include "Collision.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed):
animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	row = 0 ;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 118.0f));
	body.setPosition(20.0f,785.0f);
	body.setTexture(texture);
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
		movement.x -= speed ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed ;

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
	

	body.move(movement*deltaTime);
	animation.Update(row,deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

