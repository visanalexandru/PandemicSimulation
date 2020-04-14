#include "Graph.h"
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	Graph graph(200,100,sf::Vector2f(30,90));

	const int samples=200;

	float values[samples];


	while (window.isOpen())
	{



		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(graph);
		window.display();
	}

	return 0;
}
