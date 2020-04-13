#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

#include <SFML/System/Vector2.hpp>
class Transformable{
	protected:
		sf::Vector2f position;
		sf::Vector2f velocity;
	public:
		virtual void setPosition(sf::Vector2f other);
		virtual void setVelocity(sf::Vector2f other);
		sf::Vector2f getPosition() const;
		sf::Vector2f getVelocity() const;
		void UpdatePhysics(float time);

		Transformable(sf::Vector2f pos=sf::Vector2f(0,0),sf::Vector2f vel=sf::Vector2f(0,0));
};


#endif
