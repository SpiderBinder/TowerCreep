
#ifndef TOWERCREEP_GAMEOBJECT_H
#define TOWERCREEP_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject 
{
protected:
    // Rendering
    sf::Sprite sprite;

    // Data
    sf::FloatRect collider;

public:
    bool is_loaded = false;

    GameObject(sf::Texture& texture, sf::Vector2f position = sf::Vector2f(0.f, 0.f));
    GameObject(sf::Texture& texture, sf::FloatRect collider);

    sf::Sprite& get_sprite();
    sf::Vector2f get_position();
    sf::FloatRect get_collider();
    void set_position(sf::Vector2f new_position);
};

#endif // TOWERCREEP_GAMEOBJECT_H