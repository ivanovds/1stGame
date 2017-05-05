#include<iostream>
#include <SFML/Graphics.hpp>
#include"Game.h"
using namespace std;
using namespace sf;

void Game::draw_game(RenderWindow & window) {
	bool isGame = 1;
	while (isGame)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) { window.close(); }
		}
			//создаем массив точек, по которым будут рисоваться линии:
			sf::VertexArray lines(Lines, 40 /*количество точек*/);
			//далее для каждой из точек задаем свою позицию:
		
		int k = 41;
		for (int i = 0; i < 18; i++) {
			lines[i].position = sf::Vector2f(k, 0);
			i++;
			lines[i].position = sf::Vector2f(k, 300);
			k = k + 30;
	}
		k = 30;
		for (int i = 18; i < 37; i++) {
			lines[i].position = sf::Vector2f(11, k);
			i++;
			lines[i].position = sf::Vector2f(311, k);
			k = k + 30;
		}
		for (int i = 0; i < 40; i++) {
			lines[i].color = sf::Color::Black;
		}


		window.clear(Color::White);
		window.draw(lines);
		window.display();
	};
};