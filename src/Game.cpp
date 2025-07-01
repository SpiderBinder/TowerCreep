
#include "Game.h"

Game::Game(sf::RenderWindow& game_window)
    : window(game_window)
{
    
}

Game::~Game()
{
    delete test_level;
    delete test_entity;
    delete test_object;
}


bool Game::init()
{
    bool success = true;

    if (!test_texture.loadFromFile("../content/DefaultTile.png"))
    {
        success = false;
    }
    test_level = new Level(window, test_texture, 1, 1);
    test_entity = new Entity(test_texture, {{100.f, 100.f}, {16.f, 16.f}}, {5.f, 100.f});
    test_object = new GameObject(test_texture, {{100.f, 300.f}, {16.f, 16.f}});

    return success;
}

void Game::update(float dt)
{
    // NOTE: For testing only
    test_entity->update(dt);
    if (const std::optional rect = test_entity->get_collider().findIntersection(test_object->get_collider()))
    {
        test_entity->resolve_collision(test_object->get_collider());
    }
}

void Game::render()
{
    test_level->render();
    window.draw(test_entity->get_sprite());
    window.draw(test_object->get_sprite());
}