
#ifndef TOWERCREEP_ENTITY_H
#define TOWERCREEP_ENTITY_H

#include "GameObject.h"

class Entity : public GameObject
{
protected:
    sf::Vector2f velocity;
    bool grounded = false;

public:
    Entity(sf::Texture& texture, sf::Vector2f position = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f));
    Entity(sf::Texture& texture, sf::FloatRect collider, sf::Vector2f velocity = sf::Vector2f(0.f, 0.f));
    ~Entity();

    virtual void update(float dt);
    void resolve_collision(sf::FloatRect rect);

    sf::Vector2f get_velocity();
    bool get_grounded();
    void set_velocity(sf::Vector2f velocity);

};

#endif // TOWERCREEP_ENTITY_H