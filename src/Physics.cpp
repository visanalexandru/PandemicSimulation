#include"Physics.h"

namespace Physics{
	float magnitude(sf::Vector2f vec){
		return sqrt(vec.x*vec.x+vec.y*vec.y);
	}
	float distance(sf::Vector2f a,sf::Vector2f b){
		
		float diffx=a.x-b.x;
		float diffy=a.y-b.y;
		return sqrt(diffx*diffx+diffy*diffy);
	}

	sf::Vector2f normalize(sf::Vector2f vec){
		return vec/magnitude(vec);
	}


	sf::Vector2f repulsion(const Transformable&a,const Transformable&b,float coeficient){//cum il respinge b pe a
		float dist=distance(a.getPosition(),b.getPosition())+0.001f;//adaug epsilon ca sa nu fie 0 pt ca impart la dist	

		sf::Vector2f inv=normalize(a.getPosition()-b.getPosition());

		return inv*(coeficient/dist); 
	}
}
