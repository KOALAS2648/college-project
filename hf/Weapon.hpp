#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "P.hpp"

namespace W
{
	// defines the rifle class, probaly going to be the only weapon in the game.
    class Rifle
    {
        public:
            float x;
            float y;
            int ammo=50;

            const int MAXAMMO = 50;
            int magAmmo = 30;
            float rotation;
            float height = 10;
            float width =40;
            int diffrence = 30-magAmmo;
            Player* attachedPlayer;
            sf::Vector2f position;
            sf::Color color = sf::Color::Blue;
			// allows drawing to the screen via refrence
            void draw(sf::RenderWindow* screen)
			{
				if (attachedPlayer->alive){
                    sf::RectangleShape square(sf::Vector2f(width, height));
				    square.setPosition(x, y);
				    square.setOrigin(0, height/2.f);
				    square.setFillColor(color);
				    square.rotate(rotation);
				    screen->draw(square);
                    position = {x,y};
                }
			}
    };
}
