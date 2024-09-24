#ifndef MOLECULE_H
#define MOLECULE_H

#include <SFML/Graphics.hpp>

class Molecule {
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float radius;
    float temperatue;
    sf::CircleShape shape;

    Molecule(float x, float y, float temp)
    {
        position = sf::Vector2f(x, y);
        velocity = sf::Vector2f(0.f, 0.f);
        temperatue = temp;
        radius = 5.f;

        shape.setRadius(radius);
        shape.setPosition(position);
        shape.setFillColor(sf::Color::White);
    }

};


#endif //MOLECULE_H
