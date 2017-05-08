#include <SFML/Graphics.hpp>
#include<iostream>
#include "Classes.h"

using namespace std;
using namespace sf;
	
int main()
{
	RenderWindow window(sf::VideoMode(336, 380), "MyGame", Style::Close);
	Menu menu;
	menu.draw_menu(window);//вызов меню
	
	return 0;
}
