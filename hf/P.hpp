#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <vector>
#include <SFML/Audio.hpp>
#include <random>

namespace PlayerCode
{
	// contains the drawing and defines the varibles of where to draw the player
    class Player
    {
        public:
            public:
            float x;
            float y;
            float raduis = 10;
            int health = 100;
            bool alive=true;
            sf::Color color = sf::Color::Red;
			sf::Vector2f position;
            void draw(sf::RenderWindow* window)
            {

                sf::RenderWindow &screen = *window;
                sf::CircleShape circle1(raduis);
                circle1.setFillColor(color);
                circle1.setOrigin(raduis, raduis);
                circle1.setPosition(x,y);
                if(health > 0)
                {
                    screen.draw(circle1);
                }else
                {
                    alive=false;
                }
                
				position = {x, y};
            }
    };
}
