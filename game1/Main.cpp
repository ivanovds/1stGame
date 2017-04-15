#include <SFML/Graphics.hpp>
#include<iostream>
#include "Menu.h"
#include "Game.h"

using namespace std;
using namespace sf;
	
int main()
{
	RenderWindow window(sf::VideoMode(322, 345), "MyGame");
	//Menu menu;
	//menu.draw_menu(window);//вызов меню
	Game gm;
	gm.draw_field(window);
	return 0;
}