#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>


namespace Bo
{
	class Box
	{
		public:
			float x;
			float y;
			float width = 10;
			float height = 10;
			float screenDist;
			float rotation = 0.0;
			sf::Vector2f position = {x,y};
			sf::Color color = sf::Color::White;
			void draw(sf::RenderWindow* screen)
			{
				
				sf::RectangleShape square(sf::Vector2f(width, height));
				square.setPosition(x, y);
				square.setOrigin(width/2.f, height/2.f);
				square.setFillColor(color);
				square.rotate(rotation);
				screen->draw(square);
				
				
			}
	};
}