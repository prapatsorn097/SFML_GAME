#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1960, 1080), "Candy!");
	////// bg
	sf::Texture t;
	t.loadFromFile("image/city.png");
	sf::Sprite s(t);

	////// Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("image/02.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	////// Sprite
	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);

	int spriteSizeX = playerTexture.getSize().x / 3;
	int spriteSizeY = playerTexture.getSize().y / 4;

	int animationFrame = 0;
	shapeSprite.setTextureRect(sf::IntRect(0, 0, 50, 65));






	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		window.draw(s);
		window.draw(shapeSprite);
		window.display();

		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			shapeSprite.move(.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 1, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			shapeSprite.move(-.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			shapeSprite.move(0.f, -.1f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, 0, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			shapeSprite.move(0.f, .1f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX , spriteSizeY * 2, spriteSizeX, spriteSizeY));
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		animationFrame++;

		if (animationFrame >= 2) {
			animationFrame = 0;
		}
		window.clear();
	}
	return 0;
}