#ifndef MATHF_H
#define MATHF_H
#include <cmath>
#include <SFML/Graphics.hpp>


namespace Mathf{
    float magnitute(sf::Vector2f a);
    float distance(sf::Vector2f a,sf::Vector2f b);
    sf::Vector2f normalize(sf::Vector2f a);
    void normalized(sf::Vector2f &a);
}

#endif // MATHF_H
