
#ifndef TOWERCREEP_GAMEOBJECT_H
#define TOWERCREEP_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject 
{
protected:
    sf::Sprite sprite;

    sf::Vector2f position;

public:
    GameObject(sf::Texture& texture, sf::Vector2f position = sf::Vector2f(0.f, 0.f));

    sf::Sprite& get_sprite();
    sf::Vector2f get_position();
    void set_position(sf::Vector2f new_position);
};

#endif // TOWERCREEP_GAMEOBJECT_H