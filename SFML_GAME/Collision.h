#pragma once
#include<SFML/Graphics.hpp>

class Collision
{
public:
    Collision(sf::RectangleShape& body);
    ~Collision();

    void Move(float dx, float dy) { body.move(dx, dy); }

    bool CheckCollision(Collision& other,float push);
    sf::Vector2f GetPoistion() { return body.getPosition(); }
    sf::Vector2f GetHalfSize() { return body.getSize() / 1.0f; }
private:
    sf::RectangleShape& body;

};