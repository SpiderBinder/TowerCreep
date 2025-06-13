
#include "Entity.h"

Entity::Entity(sf::Texture& texture, sf::Vector2f position, sf::Vector2f velocity)
    : GameObject(texture, position), velocity(velocity)
{
    
}

Entity::~Entity()
{
    
}


void Entity::update(float dt)
{
    position += velocity * dt;

    sprite.setPosition(position);
}


sf::Vector2f Entity::get_velocity()
{
    return velocity;
}

void Entity::set_velocity(sf::Vector2f velocity)
{
    this->velocity = velocity;
}