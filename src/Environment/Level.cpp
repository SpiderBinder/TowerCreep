
#include "Level.h"

Level::Level(sf::RenderWindow& game_window, sf::Texture tileset, int columns, int rows)
    : game_window(game_window), tileset(tileset), width(columns), height(rows)
{
    chunks = new Chunk*[columns * rows];

    // NOTE: Remove
    Chunk::Grid grid;
    grid.tiles[0] = Chunk::TileType::Full;
    chunks[0] = new Chunk(this->tileset, {0, 0}, grid);
}

Level::~Level()
{
    for (int i = 0; i < width * height; i++)
    {
        delete chunks[i];
    }
    delete[] chunks;
}


bool Level::init()
{
    bool success = true;

    // TODO: Create default chunk objects

    // TODO: Add code for loading gameobject textures
    // NOTE: May switch to loading tectures in Game class and passing them?
    
    return success;
}

void Level::update(float dt)
{
    // TODO: Run update for all level entities
}

void Level::render()
{
    // TODO: Only draw if chunk is intersecting with camera
    for (int i = 0; i < width * height; i++)
    {
        chunks[i]->render(game_window);
    }

    // TODO: Draw all gameobjects

}


int Level::get_width()
{
    return width;
}

int Level::get_height()
{
    return height;
}