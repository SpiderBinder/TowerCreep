
#ifndef TOWERCREEP_GAME_H
#define TOWERCREEP_GAME_H

#include <SFML/Graphics.hpp>

#include "Objects/GameObject.h"

class Game
{
private:
    // Rendering
    sf::RenderWindow& window;
    sf::Texture test_texture;

    GameObject* test_object = nullptr;

public:
    Game(sf::RenderWindow& game_window);
    ~Game();

    bool init();
    void update(float dt);
    void render();

    // TODO: Figure out sf::Event stuff
    //void keyboard_input();
    //void mouse_input();

};

#endif // TOWERCREEP_GAME_H