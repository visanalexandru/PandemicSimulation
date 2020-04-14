#include "Graph.h"
#include "Simulation.h"
#include<cmath>
#include<vector>

using namespace std;

const int max_samples=50;
float values[max_samples];
Graph graph(200,20,sf::Vector2f(100,300));


void add_sample(float value){
	for(int i=0;i<max_samples-1;i++)
		values[i]=values[i+1];
	values[max_samples-1]=value;
	graph.setData(values,max_samples);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(600,600), "SFML works!");
	window.setFramerateLimit(120);
	Simulation simulation(window,500,1,2,30);
	simulation.SetCommunities(4 ,4);
	add_sample(0);
	add_sample(simulation.getNumInfected());

	sf::Clock clock;

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
		//window.draw(graph);
		window.display();

		if(clock.getElapsedTime().asSeconds()>2.f){
			add_sample(simulation.getNumInfected());
			clock.restart();
		}
	}

	return 0;
}
