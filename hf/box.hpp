#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>


namespace Bo
{
	class Box
	{
		// defines the varibles that can/might be changed throught the program.
		// rotation needs to be changed into a private variable
		public:
			float x;
			float y;
			float width = 100;
			float height = 75;
			float screenDist;
			sf::Angle rotation;
			sf::Vector2f position = {x,y};
			sf::Vector2f dimensions = {width, height};
			sf::Color color = sf::Color::White;
			void draw(sf::RenderWindow* screen)
			{
				
				sf::RectangleShape square(sf::Vector2f(width, height));
				position = {x,y};
				square.setPosition(position);
				square.setOrigin(dimensions);
				square.setFillColor(color);
				square.rotate(rotation);
				screen->draw(square);
				
				
			}
	};
}
