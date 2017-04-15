#include<iostream>
#include <SFML/Graphics.hpp>
#include"Game.h"
using namespace std;
using namespace sf;

void Game::draw_field(RenderWindow & window) {
	bool isMenu = 1;
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) { window.close(); }
		}
		//Vertex line[] =
		//{
		//	Vertex(Vector2f(10, 10)),
		//	Vertex(Vector2f(150, 150))
		//};
			//создаем массив точек, по которым будут рисоваться линии:
			sf::VertexArray lines(Lines, 20 /*количество точек*/);

		//далее для каждой из точек задаем свою позицию:
		lines[0].position = sf::Vector2f(41, 0);
		lines[1].position = sf::Vector2f(41, 300);
		lines[2].position = sf::Vector2f(71, 0);
		lines[3].position = sf::Vector2f(71, 300);
		lines[4].position = sf::Vector2f(101, 0);
		lines[5].position = sf::Vector2f(101, 300);
		lines[6].position = sf::Vector2f(131, 0);
		lines[7].position = sf::Vector2f(131, 300);
		lines[8].position = sf::Vector2f(161, 0);
		lines[9].position = sf::Vector2f(161, 300);
		lines[10].position = sf::Vector2f(191, 0);
		lines[11].position = sf::Vector2f(191, 300);
		lines[12].position = sf::Vector2f(221, 0);
		lines[13].position = sf::Vector2f(221, 300);
		lines[14].position = sf::Vector2f(251, 0);
		lines[15].position = sf::Vector2f(251, 300);
		lines[16].position = sf::Vector2f(281, 0);
		lines[17].position = sf::Vector2f(281, 300);
	

		window.clear(Color::Blue);
		window.draw(lines);
		window.display();
	};
};