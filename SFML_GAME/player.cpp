#include "Player.h"
#include "Collision.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(180.0f, 198.0f));
	body.setPosition(20.0f, 710.0f);
	body.setTexture(texture);


}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y = -9 * speed * deltaTime;
   

    if (body.getPosition().y + body.getSize().y < groundHeight || movement.y < 0)
    {

        movement.y += gravity;
    }
    else {
        body.setPosition(body.getPosition().x, groundHeight - body.getSize().y);
        movement.y = 0;
    }
    body.move(movement.x, movement.y);

    if (movement.y == 0.0f)
    {
        row = 5;
    }
    else if (movement.y < 0) {

        row = 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        row = 4;
    }
	



	body.move(movement * deltaTime);
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

