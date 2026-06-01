#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <vector>
#include <SFML/Audio.hpp>
#include <random>

namespace W
{
    class Rifle
    {
        public:
            float x;
            float y;
            int ammo=150;
            const int MAXAMMO = 150;
            int magAmmo = 30;
            float rotation;
            float height = 10;
            float width =40;
            sf::Vector2f position;
            sf::Color color = sf::Color::Blue;

            void draw(sf::RenderWindow* screen)
			{
				
				sf::RectangleShape square(sf::Vector2f(width, height));
				square.setPosition(x, y);
				square.setOrigin(0, height/2.f);
				square.setFillColor(color);
				square.rotate(rotation);
				screen->draw(square);
                position = {x,y};
				
				
			}
    };
}