
#ifndef TOWERCREEP_GAME_H
#define TOWERCREEP_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Environment/Level.h"
#include "Objects/Entity.h"

class Game
{
private:
    // Rendering
    sf::RenderWindow& window;
    // NOTE: For testing only
    sf::Texture test_texture;

    // Data
    // NOTE: For testing only
    Level* test_level = nullptr;
    Entity* test_entity = nullptr;
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