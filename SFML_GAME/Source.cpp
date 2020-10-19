#include <SFML/Graphics.hpp>
#include <iostream>
#include"player.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1960, 1080), "Candy Runner",
        sf::Style::Titlebar | sf::Style::Close);
    
    sf::Texture t;
    if (!t.loadFromFile("image/city.png"))
        return EXIT_FAILURE;
    t.setRepeated(true);
    sf::Sprite background(t);
    background.setPosition(0, 0);
    background.setColor(sf::Color(255, 255, 255, 200));

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
    float deltaTime2 = 0.0f;
    sf::Clock clock2;
    float offset = 0.0f;



    //ตัวละคร
    sf::Texture playerTexture;
    playerTexture.loadFromFile("image/game-sprite01.png");
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 10;
    textureSize.y /= 6;
    player player(&playerTexture, sf::Vector2u(10, 6), 0.1f,300.0);
    float deltaTime = 0.0f;
    
    sf::Clock clock;
 

    while (window.isOpen())
    {
        deltaTime2 = clock2.restart().asSeconds();
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


        //รับค่าผ่านคีย์บอร์ด
        ///if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        ///{
        ///    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
         ///   player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
       /// }

        parallaxShader.setUniform("offset", offset += clock2.restart().asSeconds() / 20);

        player.Update(deltaTime);
        window.draw(background, &parallaxShader);
        player.Draw(window);
        window.display();
    }
        return EXIT_SUCCESS;
    }