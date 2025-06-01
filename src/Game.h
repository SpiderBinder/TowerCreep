
#ifndef TOWERCREEP_GAME_H
#define TOWERCREEP_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
private:
    // Rendering
    sf::RenderWindow& window;

public:
    Game(sf::RenderWindow& game_window);

    bool init();
    void update(float dt);
    void render();

    // TODO: Figure out sf::Event stuff
    //void keyboard_input();
    //void mouse_input();

};

#endif // TOWERCREEP_GAME_H