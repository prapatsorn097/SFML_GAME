#pragma once
#include<SFML\Graphics.hpp>
#include"Animation.h"
#include"Collider.h"
class player
{
public:
    player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed);
    ~player();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
  
    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetsCollider() { return Collider(body); }

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    

};

