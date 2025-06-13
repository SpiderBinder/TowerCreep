
#ifndef TOWERCREEP_ENTITY_H
#define TOWERCREEP_ENTITY_H

#include "GameObject.h"

class Entity : public GameObject
{
protected:
    sf::Vector2f velocity;

public:
    Entity(sf::Texture& texture, sf::Vector2f position = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f));
    ~Entity();

    virtual void update(float dt);

    sf::Vector2f get_velocity();
    void set_velocity(sf::Vector2f velocity);

};

#endif // TOWERCREEP_ENTITY_H