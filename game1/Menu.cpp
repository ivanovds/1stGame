#include<iostream>
#include <SFML/Graphics.hpp>
#include"Menu.h"
using namespace std;
using namespace sf;

void Menu::draw_menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4,
		menuTexture5, menuTexture6, menuTexture7, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/new.png");
	menuTexture2.loadFromFile("images/param.png");
	menuTexture3.loadFromFile("images/mode.png");
	menuTexture4.loadFromFile("images/about.png");
	menuTexture5.loadFromFile("images/exit.png");
	menuTexture6.loadFromFile("images/duel.png");
	menuTexture7.loadFromFile("images/comp.png");
	aboutTexture.loadFromFile("images/abt.png");
	menuBackground.loadFromFile("images/background.jpg");
	Sprite menu1, menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4),
		menu5(menuTexture5), menu6(menuTexture6), menu7(menuTexture7),
		abt(aboutTexture), menuBg(menuBackground); //используем конструктор с параметрами 
	menu1.setTexture(menuTexture1); //используем функцию-модификатор
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(60, 30);
	menu2.setPosition(35, 90);
	menu3.setPosition(60, 140);
	menu4.setPosition(25, 190);
	menu5.setPosition(25, 240);
	menu6.setPosition(80, 80);
	menu7.setPosition(25, 180);
	menuBg.setPosition(0, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::Black);
		menu2.setColor(Color::Black);
		menu3.setColor(Color::Black);
		menu4.setColor(Color::Black);
		menu5.setColor(Color::Black);
		menu6.setColor(Color::Black);
		menu7.setColor(Color::Black);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(60, 30, 200, 50).contains(Mouse::getPosition(window)))  { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(35, 90, 250, 50).contains(Mouse::getPosition(window)))  { menu2.setColor(Color::Red); menuNum = 2; }
		if (IntRect(60, 140, 200, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		if (IntRect(90, 190, 150, 50).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Red); menuNum = 4; }
		if (IntRect(90, 240, 150, 50).contains(Mouse::getPosition(window))) { menu5.setColor(Color::Blue); menuNum = 5; }
		// цикл событий(в дополнение к обработке пользовательских событий, он даёт возможность 
		//окну обрабатывать и внутренние события, которые необходимы для реагирования на 
		//изменения размера окна и перемещения его)
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) {
					isMenu = false;

				}//если нажали первую кнопку, то выходим из меню 
				if (menuNum == 2) {
				}
				if (menuNum == 3) {
					window.draw(menu6);
					window.draw(menu7);
					window.display();
					while (!Keyboard::isKeyPressed(Keyboard::Escape));
					if (IntRect(80, 80, 100, 50).contains(Mouse::getPosition(window))) {
						menu6.setColor(Color::Red); menuNum = 6; }
					if (IntRect(25, 180, 200, 50).contains(Mouse::getPosition(window))) { 
						menu7.setColor(Color::Blue); menuNum = 7; }
				}
				if (menuNum == 4) {
					window.draw(abt);
					window.display();
					while (!Keyboard::isKeyPressed(Keyboard::Escape));
				}
				if (menuNum == 5) {
					window.close();
					isMenu = false;
				}
			}
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.draw(menu5);
		window.display();
	}
	////////////////////////////////////////////////////
}
