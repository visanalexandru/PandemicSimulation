#include"Physics.h"

namespace Physics{


	sf::Vector2f repulsion(const Transformable&a,const Transformable&b,float coeficient){//cum il respinge b pe a
		float dist=Mathf::distance(a.getPosition(),b.getPosition())+0.001f;//adaug epsilon ca sa nu fie 0 pt ca impart la dist

		sf::Vector2f inv=Mathf::normalize(a.getPosition()-b.getPosition());

		return inv*(coeficient/dist);
	}
}
