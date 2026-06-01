#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "collisions.hpp"

namespace B
{
    class BulletClass
    {
        public:
            float x=0;
            float y=0;
            float raduis = 10;
            float moveAngle;
            int speed = 15;
            bool show=true;
            sf::Color color = sf::Color::Yellow;
			sf::Vector2f position={0,0};
            void draw(sf::RenderWindow* window)
            {

                
                sf::CircleShape circle1(raduis);
                circle1.setFillColor(color);
                circle1.setOrigin(raduis, raduis);
                
                circle1.setPosition(x,y);
                window->draw(circle1);
				position = {x, y};
            }
            void move()
            {
                x += speed*cos(moveAngle);
                y += speed*sin(moveAngle);
                    
            }
    };
}