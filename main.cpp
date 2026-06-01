//g++ main.cpp -o app -IC:/msys64/ucrt64/include -LC:/msys64/ucrt64/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// ./app.exe

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>
#include <SFML/Audio.hpp>
#include <random>
#include "hf/P.hpp"
#include "hf/collisions.hpp"
#include "hf/Weapon.hpp"
#include "hf/Bullet.hpp"
using namespace Collision;
using namespace std;
using namespace PlayerCode;
using namespace W;
using namespace B;
    



int main()
{
    sf::Vector2i mousePos;
	sf::Clock clock;
    int frames = 0;
    float elapsed = 0.0f;
    sf::RenderWindow window(sf::VideoMode(800, 600), "window");
	window.setFramerateLimit(60);
    sf::RenderWindow* windowPointer = &window;

    Player first;
    first.x = window.getSize().x/2;
    first.y= window.getSize().y/2;
    Player* firstPointer = &first;

    Rifle r1;
    r1.x =0;
    r1.y =0;
    float dx;
    float dy;
    float angle;
    int speed=5;
    vector<BulletClass> bullets = {};
    BulletClass b1;
    b1.x = 400;
    b1.y = 300;
    b1.moveAngle = 45;
    BulletClass tempBullet;

    bool c;
    bool flag;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
            if(event.type == sf::Event::MouseButtonPressed)
            {
                tempBullet.x = first.x;
                tempBullet.y = first.y+r1.height;

                flag = true;
            }
            if (event.type == sf::Event::MouseButtonReleased && flag)
            {
                flag = false;
                cout << "mouse button pressed" << endl;
            }
		}
        bool c = isOutside(firstPointer, windowPointer);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !c)
		{
			first.y -= speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !c)
		{
			first.y+= speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !c)
		{
			first.x-= speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !c)
		{
			first.x+= speed;
		}
        window.clear();
        b1.draw(windowPointer);
        r1.draw(windowPointer);
        first.draw(windowPointer);
        r1.x = first.x;
        r1.y = first.y;
        mousePos = sf::Mouse::getPosition(window);
        dx = -(first.x-mousePos.x);
        dy = -(first.y-mousePos.y);
        angle = (atan2(dy, dx)* 180/3.14159);
        r1.rotation = angle;
       //cout << angle << endl;
        
        window.display();
    }
        
    return 0;
}