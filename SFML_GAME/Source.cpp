#include <SFML/Graphics.hpp>
#include <iostream>
#include"Player.h"
#include "Platform.h"
#include "Menu.h"
//#include <vector>
int page_number;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1960, 1080), "Candy Runner",
        sf::Style::Titlebar | sf::Style::Close);

    window.setVerticalSyncEnabled(true);
    sf::Texture texture;
    if (!texture.loadFromFile("image/bg1.png"))
        return EXIT_FAILURE;
    texture.setRepeated(true);
    sf::Sprite sprite(texture);
    sprite.setPosition(0, 0);
    sprite.setColor(sf::Color(255, 255, 255, 200));


    sf::Texture test;
    if (!test.loadFromFile("image/1.png"))
        return EXIT_FAILURE;
    
    /// หน้าเมนู
     

    Menu menu(1960, 1080);
    
    /// พื้นหลัง

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

  //collision
   /* std::vector<Platform> platforms;
        platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(200.0f, 200.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(200.0f, 0.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(200.0f, 200.0f)));*/



    //ตัวละคร
    sf::Texture playerTexture;
    playerTexture.loadFromFile("image/game-sprite01.png");

    Player player(&playerTexture, sf::Vector2u(10, 6), 0.1f,200.0f);


    

    sf::Clock clock;

    


    float deltaTime = 0.0f;
    float offset = 0.f;
    sf::Clock clock2;

    /// หน้าต่างเมนู
    while (window.isOpen())
    {


        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::KeyReleased:
                switch (evnt.key.code)
                {
                case sf::Keyboard::W:
                    menu.moveUp();
                    break;

                case sf::Keyboard::S:
                    menu.moveDown();
                    break;

                case sf::Keyboard::Enter:
                    switch (menu.mainMenuPressed())
                    {
                    case 0:
                        window.close();
                        page_number = 1;
                        break;
                    case 1:
                        window.close();
                        page_number = 2;
                        break;
                    case 2:
                        window.close();
                        page_number = 3;
                        break;
                    }
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        //set an arbitrary value as the offset, you'd calculate this based on camera position


        menu.Draw(window);
        window.display();
    }
    if (page_number == 1)
    {

        //Play
        sf::RenderWindow window_play(sf::VideoMode(1960, 1080), "Play!", sf::Style::Titlebar| sf::Style::Close);
        while (window_play.isOpen())
        {

            deltaTime = clock.restart().asSeconds();

            sf::Event evnt;
            while (window_play.pollEvent(evnt))
            {
                switch (evnt.type)
                {
                case sf::Event::KeyReleased:
                    switch (evnt.key.code)
                    {
                    case sf::Keyboard::Escape:
                        window_play.close();
                        main();
                        break;
                    }
                    break;
                }

            }
            parallaxShader.setUniform("offset", offset += clock2.restart().asSeconds() /10);





            player.Update(deltaTime);
            Collision playerCollision = player.GetCollision();

            sf::Vector2f direction;

            /*for (Platform& platform : platforms)
                if (platform.GetCollision().CheckCollision(playerCollision,direction, 1.0f))
                    player.GetCollision(direction);*/
            

            window_play.clear();
            
            window_play.draw(sprite, &parallaxShader);
            player.Draw(window_play);
           /* for (Platform& platform : platforms)
                platform.Draw(window);*/
     
            window_play.display();
            window_play.setFramerateLimit(60);
          
        }
    }
    return EXIT_SUCCESS;
}