#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>

namespace B
{
    class BulletClass
    {
        public:
            float x=0;
            float y=0;
            float raduis = 10;
            float moveAngle;
            int speed = 5;
            sf::Color color = sf::Color::Yellow;
			sf::Vector2f position={0,0};
            void draw(sf::RenderWindow* window)
            {

                
                sf::CircleShape circle1(raduis);
                circle1.setFillColor(color);
                circle1.setOrigin(raduis, raduis);
                move();
                circle1.setPosition(x,y);
                window->draw(circle1);
				position = {x, y};
            }
            void move()
            {
                x += speed*sin(moveAngle);
                y += speed*cos(moveAngle);    
            }
    };
}