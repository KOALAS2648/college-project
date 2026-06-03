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
			// which angle to shoot at
            float moveAngle;
            int speed = 15;
			// whevether to render the movement/dislay the bullet
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
			// defines how the bullet moves based on where the player is looking.
            void move()
            {
                x += speed*cos(moveAngle);
                y += speed*sin(moveAngle);
                    
            }
    };
}
