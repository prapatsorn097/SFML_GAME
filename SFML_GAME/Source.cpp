#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1960, 1080), "Candy Runner",
        sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    ///พื้นหลัง

    sf::Texture bg;
    if (!bg.loadFromFile("image/city.png"))
        return EXIT_FAILURE;
    bg.setRepeated(true);

    sf::Sprite sprite(bg);
    sprite.setPosition(0, 0);


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

    sf::Clock clock;

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("image/game-sprite01.png"))
    {
        std::cout << "Load failed" << std::endl;
    }
    ////// Sprite
    sf::Sprite shapeSprite;
    shapeSprite.setTexture(playerTexture);
    int spriteSizeX = playerTexture.getSize().x / 10;
    int spriteSizeY = playerTexture.getSize().y / 6;

    sf::Vector2u spriteSize = playerTexture.getSize();
    int animationFrame = 0;
    shapeSprite.setTextureRect(sf::IntRect(0, 0, 100, 118));
    shapeSprite.setPosition(20, 765);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        ///รับค่าคีย์
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            shapeSprite.move(1.f, 0.f);
            shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 5, spriteSizeX, spriteSizeY));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            shapeSprite.move(0.f, 1.f);
            shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 2, spriteSizeX, spriteSizeY));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        animationFrame++;

        if (animationFrame >= 6) {
            animationFrame = 0;
        }

        ///คำลั่งวาดแสดงผลผ่านหน้าจอ
        parallaxShader.setUniform("offset", offset += clock.restart().asSeconds() / 10);
        window.clear();
        window.draw(sprite, &parallaxShader);
        window.draw(shapeSprite);
        window.display();
    }

    return EXIT_SUCCESS;
}