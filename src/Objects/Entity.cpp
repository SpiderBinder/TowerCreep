
#include "Entity.h"

Entity::Entity(sf::Texture& texture, sf::Vector2f position, sf::Vector2f velocity)
    : GameObject(texture, position), velocity(velocity)
{
    
}

Entity::Entity(sf::Texture& texture, sf::FloatRect collider, sf::Vector2f velocity)
    : GameObject(texture, collider), velocity(velocity)
{
    
}

Entity::~Entity()
{
    
}


void Entity::update(float dt)
{
    grounded = false;

    collider.position += velocity * dt;

    sprite.setPosition(collider.position);
}

void Entity::resolve_collision(sf::FloatRect rect)
{
    sf::Vector2f side(0, 0);

    sf::Vector2f selfcorner = collider.position;
    sf::Vector2f othercorner = rect.position + rect.size;

    // Check for simple solves
    if (velocity == sf::Vector2f(0, 0))
    {
        side.y = -1;
    }
    else if (velocity.x == 0)
    {
        side.y = velocity.y > 0 ? -1 : 1;
    }
    else if (velocity.y == 0)
    {
        side.x = velocity.x > 0 ? -1 : 1;
    }
    else
    {
        side.y = velocity.y > 0 ? -1 : 1;
        side.x = velocity.x > 0 ? -1 : 1;

        // Determine velocity origin corners
        if (velocity.x > 0)
        {
            selfcorner.x += collider.size.x;
            othercorner.x -= rect.size.x;
        }
        if (velocity.y > 0)
        {
            selfcorner.y += collider.size.y;
            othercorner.y -= rect.size.y;
        }

        // Calculate fraction of velocity between each corner for each axis
        float fractionx = (selfcorner.x - othercorner.x) / velocity.x;
        float fractiony = (selfcorner.y - othercorner.y) / velocity.y;

        // Check which axis is closer accounting for velocity
        // (aka which side would be easiest to get to with the current velocity)
        if (fractiony > fractionx)
        {
            side.y = 0;
        }
        else
        {
            side.x = 0;
        }
    }

    // Correct position of Entity collider and reset correct velocity
    if (side.x == 1)
    {
        collider.position.x = rect.position.x + rect.size.x;
        velocity.x = 0;
    }
    if (side.x == -1)
    {
        collider.position.x = rect.position.x - collider.size.x;
        velocity.x = 0;
    }
    if (side.y == 1)
    {
        collider.position.y = rect.position.y + rect.size.y;
        velocity.y = 0;
    }
    if (side.y == -1)
    {
        collider.position.y = rect.position.y - collider.size.y;
        velocity.y = 0;
        grounded = true;
    }
}


sf::Vector2f Entity::get_velocity()
{
    return velocity;
}

bool Entity::get_grounded()
{
    return grounded;
}

void Entity::set_velocity(sf::Vector2f velocity)
{
    this->velocity = velocity;
}