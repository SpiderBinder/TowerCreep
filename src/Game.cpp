
#include "Game.h"

Game::Game(sf::RenderWindow& game_window)
    : window(game_window)
{
    
}

Game::~Game()
{
    delete test_object;
}


bool Game::init()
{
    bool success = true;

    if (!test_texture.loadFromFile("../content/DefaultTile.png"))
    {

    }
    test_object = new GameObject(test_texture);

    return success;
}

void Game::update(float dt)
{

}

void Game::render()
{
    window.draw(test_object->get_sprite());
}