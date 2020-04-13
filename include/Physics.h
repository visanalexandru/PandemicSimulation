#ifndef PHYSICS_H
#define PHYSICS_H

#include<cmath>
#include"Transformable.h"

namespace Physics{
	float magnitude(sf::Vector2f vec);
	float distance(sf::Vector2f a,sf::Vector2f b);
	sf::Vector2f normalize(sf::Vector2f vec);
	sf::Vector2f repulsion(const Transformable&a,const Transformable&b,float coeficient);
	
}



#endif
