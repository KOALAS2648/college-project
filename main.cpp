//g++ main.cpp -o app -IC:/msys64/ucrt64/include -LC:/msys64/ucrt64/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// ./app.exe


// laptop compile command: g++ main.cpp -std=c++17 -o ./app.exegit  -IC:/msys64/ucrt64/include -LC:/msys64/ucrt64/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// ./app.exe

// this file was made to make swure all the logic and code I have written will work 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>
//#include <SFML/Audio.hpp>
#include <random>
#include <algorithm>
#include "hf/P.hpp"
#include "hf/collisions.hpp"
#include "hf/Weapon.hpp"
#include "hf/Bullet.hpp"
#include "hf/box.hpp"
using namespace Collision;
using namespace std;
using namespace PlayerCode;
using namespace W;
using namespace B;
using namespace Bo;
    



int main()
{
    sf::Vector2i mousePos;
	sf::Clock clock;
    int frames = 0;
    float elapsed = 0.0f;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "window");
	window.setFramerateLimit(60);
    sf::RenderWindow* windowPointer = &window;

    Player first;
    first.x = window.getSize().x/2;
    first.y= window.getSize().y/2;
    Player* firstPointer = &first;

    Rifle r1;
    Rifle* riflePointer = &r1;
    r1.x =0;
    r1.y =0;

    float dx;
    float dy;
    sf::Angle angleP1;
    sf::Angle angleP2;
    int speed=5;

    Player second;
    second.x =300;
    second.y = 150;
    Player* secondPointer = &second;

    Rifle r2;
    Rifle* f2Pointer = &r2;
    r2.x = secondPointer->x;
    r2.y = secondPointer->y;

    r1.attachedPlayer = firstPointer;
    r2.attachedPlayer = secondPointer;
    
    Box box1;
    box1.x = 100;
    box1.y = 200;
    Box* box1Pointer = &box1;

    vector<BulletClass> bullets = {};
    BulletClass b1;
    b1.x = 400;
    b1.y = 300;
    b1.moveAngle = sf::degrees(45);
    BulletClass tempBullet;
    BulletClass* tempBulletPointer;

    bool c;
    bool flag;
    
    while(window.isOpen())
    {
        
        while(const auto event = window.pollEvent())
		{
			if(event->is<sf::Event::Closed>())
			{
				window.close();
			}
            if(const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if(mousePressed->button == sf::Mouse::Button::Left && riflePointer->magAmmo > 0)
                {
                
                    tempBullet.x = first.x+((first.raduis+r1.width)*cos(angleP1.asRadians()));
                    tempBullet.y = first.y+((first.raduis+r1.height)*sin(angleP1.asRadians()));
                    //cout << angle << endl;
                    tempBullet.moveAngle = angleP1;
                    bullets.push_back(tempBullet);
                    riflePointer->magAmmo -= 1;
                    riflePointer->diffrence = 30-riflePointer->magAmmo;
                    flag = true;
                }

            }
            if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>())
            {
                flag = false;
                cout << riflePointer->magAmmo << endl;
            }
            if (const auto* keyPressed =event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::R)
                {
                    riflePointer->magAmmo += max(riflePointer->diffrence, riflePointer->ammo);
                    riflePointer->ammo -=max(riflePointer->diffrence, riflePointer->ammo);
                    cout << "rifle ammo left " << riflePointer->ammo << endl;
                }
            }
		}
        
        c = isPlayerOutside(firstPointer, windowPointer) && firstPointer->alive;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !c)
        {
            first.y -= speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !c)
        {
            first.y+= speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && !c)
        {
            first.x-= speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !c)
        {
            first.x+= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            box1.x += speed;
        }
        window.clear();
        // where all the bullet logic is checked
        for(BulletClass &bullet: bullets)
        {
            // if the bullet is not needed to be shown don't display and waste calulation time.
            if(bullet.show)
            {
                tempBulletPointer = &bullet;
                if(bulletPlayerCollision(firstPointer, tempBulletPointer)&& firstPointer->alive)
                {
                    firstPointer-> health-=10;
                }
                if (bulletPlayerCollision(secondPointer, tempBulletPointer)&&secondPointer->alive)
                {
                    secondPointer->health = secondPointer->health-10;
                }
                bullet.draw(windowPointer);
                bullet.move();
                bullet.show = !isBulletOutside(tempBulletPointer, windowPointer);
            }
            
        }
        // draw the players and the rifles.
        b1.draw(windowPointer);
        r2.draw(windowPointer);
        r1.draw(windowPointer);
        first.draw(windowPointer);
        second.draw(windowPointer);
        box1.draw(windowPointer);

        // set the rifle positions to the first players x, y
        r1.x = first.x;
        r1.y = first.y;
        // calculates the rotation based on the mouse position for both of the weaponss
        mousePos = sf::Mouse::getPosition(window);
        dx = -(first.x-mousePos.x);
        dy = -(first.y-mousePos.y);
        angleP1 = sf::degrees(atan2(dy, dx));
        r1.rotation = angleP1* 180/3.14159;
        
        dx = -(second.x-mousePos.x);
        dy = -(second.y-mousePos.y);
        angleP2 = sf::degrees(atan2(dy, dx));
        r2.rotation = angleP2* 180/3.14159;
        
        window.display();
    }
        
    return 0;
}
// tetsing