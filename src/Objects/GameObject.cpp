
#include "GameObject.h"

GameObject::GameObject(sf::Texture& texture, sf::Vector2f position)
    : sprite(sf::Sprite(texture))
{
    // NOTE: Change default size to that of the texture?
    collider = sf::FloatRect(position, {0, 0});

    sprite.setPosition(this->collider.position);
}

GameObject::GameObject(sf::Texture& texture, sf::FloatRect collider)
    : sprite(sf::Sprite(texture)), collider(collider)
{
    sprite.setPosition(this->collider.position);
}


sf::Sprite& GameObject::get_sprite()
{
    sprite.setPosition(collider.position);

    return sprite;
}

sf::Vector2f GameObject::get_position()
{
    return collider.position;
}

sf::FloatRect GameObject::get_collider()
{
    return collider;
}

void GameObject::set_position(sf::Vector2f new_position)
{
    collider.position = new_position;
    sprite.setPosition(collider.position);
}