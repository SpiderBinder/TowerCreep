
#include "Game.h"

Game::Game(sf::RenderWindow& game_window)
    : window(game_window)
{
    
}

Game::~Game()
{
    delete test_level;
}


bool Game::init()
{
    bool success = true;

    if (!test_texture.loadFromFile("../content/DefaultTile.png"))
    {
        success = false;
    }
    test_level = new Level(window, test_texture, 1, 1);

    return success;
}

void Game::update(float dt)
{
    // NOTE: Remove
    //std::cout << Chunk::TileType::Full << std::endl;
}

void Game::render()
{
    test_level->render();;
}