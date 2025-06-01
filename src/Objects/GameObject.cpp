
#include "GameObject.h"

GameObject::GameObject(sf::Texture& texture, sf::Vector2f position)
    : sprite(sf::Sprite(texture)), position(position)
{
    sprite.setPosition(position);
}


sf::Sprite& GameObject::get_sprite()
{
    return sprite;
}

sf::Vector2f GameObject::get_position()
{
    return position;
}

void GameObject::set_position(sf::Vector2f new_position)
{
    position = new_position;
    sprite.setPosition(position);
}