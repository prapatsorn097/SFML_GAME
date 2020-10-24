#include <SFML/Graphics.hpp>
#include <iostream>
#include"Player.h"
#include "Platform.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1960, 1080), "Candy Runner",
        sf::Style::Titlebar | sf::Style::Close);

    window.setVerticalSyncEnabled(true);
    sf::Texture texture;
    if (!texture.loadFromFile("image/city.png"))
        return EXIT_FAILURE;
    texture.setRepeated(true);
    sf::Sprite sprite(texture);
    sprite.setPosition(0, 0);
    sprite.setColor(sf::Color(255, 255, 255, 200));

    sf::Shader parallaxShader;
    parallaxShader.loadFromMemory(
        "uniform float offset;"

        "void main() {"
        "    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
        "    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
        "    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;" // magic
        "    gl_FrontColor = gl_Color;"
        "}"
        , sf::Shader::Vertex);

    float offset = 0.f;


    sf::Clock clock2;






    //ตัวละคร
    sf::Texture playerTexture;
    playerTexture.loadFromFile("image/game-sprite01.png");
    
    Player player(&playerTexture, sf::Vector2u(10, 6), 0.1f, 300.0);

    Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
    Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
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

            case sf::Event::TextEntered:
                if (event.text.unicode < 128) {


                    printf("%c", event.text.unicode);


                }
            }

        }
        parallaxShader.setUniform("offset", offset += clock2.restart().asSeconds() / 10);


        //รับค่าผ่านคีย์บอร์ด
        ///if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        ///{
        ///    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
         ///   player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
       /// }

        player.Update(deltaTime);
       
        Collision playerCollision = player.GetCollision();

        platform1.GetCollision().CheckCollision(playerCollision, 0.0f);

        platform2.GetCollision().CheckCollision(playerCollision, 1.0f);

        window.clear();
        window.draw(sprite, &parallaxShader);
        player.Draw(window);
        platform1.Draw(window);
        platform2.Draw(window);
        window.display();
    }
    return EXIT_SUCCESS;
}