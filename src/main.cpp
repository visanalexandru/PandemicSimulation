#include "Graph.h"
#include "Simulation.h"
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	Graph graph(500,100,sf::Vector2f(30,90));

	const int samples=200;

	float values[samples];

	for(int i=0;i<samples;i++){
		values[i]=sin(i);
	}

	graph.setData(&values[0],samples);
	Simulation simulation(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		simulation.Update();
		window.draw(graph);
		window.display();
	}

	return 0;
}
