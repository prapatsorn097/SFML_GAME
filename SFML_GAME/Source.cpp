#include <SFML/Graphics.hpp>
#include <iostream>
#include"Animation.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 960), "Candy Runner",
        sf::Style::Resize | sf::Style::Close);

    sf::RectangleShape player(sf::Vector2f(150.0f, 168.0f));///ขนาดตัวละคร
    player.setPosition(50.0f, 50.0f);///ตำแหน่งตัวละคร
  

    //ตัวละคร
    sf::Texture playerTexture;
    playerTexture.loadFromFile("image/game-sprite01.png");
    player.setTexture(&playerTexture);
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 10;
    textureSize.y /= 6;

    player.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));
    Animation animation(&playerTexture, sf::Vector2u(10, 6), 0.8f);

    float deltaTime = 0.0f;
    sf::Clock clock;



    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << event.size.width << "New window height:" << event.size.height << std::endl;
                printf("New winsow wigth : %i  New Window height : %i\n", event.size.width, event.size.height);
                break;
            case sf::Event::TextEntered:
                if (event.text.unicode < 128) {


                    printf("%c", event.text.unicode);


                }
            }

        }


        //รับค่าผ่านคีย์บอร์ด
        ///if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        ///{
        ///    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
         ///   player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
       /// }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            player.move(0.0f, 0.1f);
        }

        animation.Update(0,deltaTime);
        player.setTextureRect(animation.uvRect);

        window.clear();
        window.draw(player);
        window.display();
    }
        return EXIT_SUCCESS;
    }