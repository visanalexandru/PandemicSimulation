#include "Transformable.h"

Transformable::Transformable(sf::Vector2f pos,sf::Vector2f vel):
	position(pos),
	velocity(vel)
{

}

void Transformable::setPosition(sf::Vector2f other){
	position=other;
}
void Transformable::setVelocity(sf::Vector2f other){
	velocity=other;
}

sf::Vector2f Transformable::getPosition() const{
	return position;
}
sf::Vector2f Transformable::getVelocity() const{
	return velocity;
}
void Transformable::UpdatePhysics(float deltatime){
	setPosition(position+velocity*deltatime);
}

