
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

int main()
{
    //std::cout << "Hello World!" << std::endl;

    // Initialise window object
    sf::RenderWindow window(sf::VideoMode({1080, 720}), "TowerCreep");
    //window.setFrameRate(60);
    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            /* else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
            } */

            // Input code
        }

        window.clear(sf::Color::Cyan);
        
        

        window.display();
    }

    return 1;
}