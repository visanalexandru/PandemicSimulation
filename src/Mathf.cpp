#include "Mathf.h"

namespace Mathf{
    float magnitute(sf::Vector2f a){
        return sqrt(a.x * a.x + a.y * a.y);
    }
    float distance(sf::Vector2f a,sf::Vector2f b){
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
    sf::Vector2f normalize(sf::Vector2f a){
        return a / magnitute(a);
    }
    void normalized(sf::Vector2f &a){
        a /= magnitute(a);
    }
    sf::Vector2f cross(sf::Vector2f a,sf::Vector2f b){

    }

}
