
#ifndef TOWERCREEP_LEVEL_H
#define TOWERCREEP_LEVEL_H

#include <SFML/Graphics.hpp>

#include "Chunk.h"

#include "../Objects/Entity.h"
#include "../Objects/Player.h"

class Level
{
protected:
    // Rendering
    sf::RenderWindow& game_window;

    sf::Texture tileset;

    // Data
    int width;
    int height;

    Chunk** chunks = nullptr;

    // Objects
    //Player player;

    // TODO: Add list of enemies when implemented
    // TODO: Add list of items when implemented

public:
    Level(sf::RenderWindow& game_window, sf::Texture tileset, int columns = 0, int rows = 0);
    ~Level();

    virtual bool init();
    virtual void update(float dt);
    void render();

    int get_width();
    int get_height();

};

#endif // TOWERCREEP_LEVEL_H