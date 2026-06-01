//g++ main.cpp -o app -IC:/msys64/ucrt64/include -LC:/msys64/ucrt64/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// ./app.exe

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <vector>
#include <SFML/Audio.hpp>
#include <random>

int main()
{
	sf::Clock clock;
    int frames = 0;
    float elapsed = 0.0f;
    sf::RenderWindow window(sf::VideoMode(800, 600), "window");
	window.setFramerateLimit(60);
    sf::RenderWindow* windowPointer = &window;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
            window.clear();
            window.display();
		}
    }
        
    return 0;
}