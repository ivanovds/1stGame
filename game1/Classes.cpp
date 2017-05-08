#include<iostream>
#include <SFML/Graphics.hpp>
#include"Classes.h"
#include"Stuff.h"
using namespace std;
using namespace sf;


// ################## class Player ##################
Player & Player::set_step(bool stp) {
	step = stp;
	return *this;
};
Player & Player::operator ++() {
	++count;
	return *this;
};


// ################## class Lines ##################
MyLines & MyLines::set_left(int left) {
	this->left = left;
	return *this;
};
MyLines & MyLines::set_right(int right) {
	this->right = right;
	return *this;
};
MyLines & MyLines::set_top(int top) {
	this->top = top;
	return *this;
};
MyLines & MyLines::set_bottom(int bottom) {
	this->bottom = bottom;
	return *this;
};
MyLines & MyLines::operator++() {
	++count;
	return *this;
};
MyLines & MyLines::set_coord(float coord_x, float coord_y) {
	this->coord_x = coord_x;
	this->coord_y = coord_y;
	return *this;
};

// Mouse position 
int gt_ms_position(int ms_position, RenderWindow & window) {
	// vertical
		if (IntRect(24, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 1; }
		if (IntRect(24, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 2; }
		if (IntRect(24, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 3; }
		if (IntRect(24, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 4; }
		if (IntRect(24, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 5; }
		if (IntRect(24, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 6; }
		if (IntRect(24, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 7; }
		if (IntRect(24, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 8; }
		if (IntRect(24, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 9; }
		if (IntRect(24, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 10; }
		
		if (IntRect(58, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 11; }
		if (IntRect(58, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 12; }
		if (IntRect(58, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 13; }
		if (IntRect(58, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 14; }
		if (IntRect(58, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 15; }
		if (IntRect(58, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 16; }
		if (IntRect(58, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 17; }
		if (IntRect(58, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 18; }
		if (IntRect(58, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 19; }
		if (IntRect(58, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 20; }

		if (IntRect(92, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 21; }
		if (IntRect(92, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 22; }
		if (IntRect(92, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 23; }
		if (IntRect(92, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 24; }
		if (IntRect(92, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 25; }
		if (IntRect(92, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 26; }
		if (IntRect(92, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 27; }
		if (IntRect(92, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 28; }
		if (IntRect(92, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 29; }
		if (IntRect(92, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 30; }


		if (IntRect(126, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 31; }
		if (IntRect(126, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 32; }
		if (IntRect(126, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 33; }
		if (IntRect(126, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 34; }
		if (IntRect(126, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 35; }
		if (IntRect(126, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 36; }
		if (IntRect(126, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 37; }
		if (IntRect(126, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 38; }
		if (IntRect(126, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 39; }
		if (IntRect(126, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 40; }


		if (IntRect(160, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 41; }
		if (IntRect(160, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 42; }
		if (IntRect(160, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 43; }
		if (IntRect(160, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 44; }
		if (IntRect(160, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 45; }
		if (IntRect(160, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 46; }
		if (IntRect(160, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 47; }
		if (IntRect(160, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 48; }
		if (IntRect(160, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 49; }
		if (IntRect(160, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 50; }


		if (IntRect(194, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 51; }
		if (IntRect(194, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 52; }
		if (IntRect(194, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 53; }
		if (IntRect(194, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 54; }
		if (IntRect(194, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 55; }
		if (IntRect(194, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 56; }
		if (IntRect(194, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 57; }
		if (IntRect(194, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 58; }
		if (IntRect(194, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 59; }
		if (IntRect(194, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 60; }


		if (IntRect(228, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 61; }
		if (IntRect(228, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 62; }
		if (IntRect(228, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 63; }
		if (IntRect(228, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 64; }
		if (IntRect(228, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 65; }
		if (IntRect(228, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 66; }
		if (IntRect(228, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 67; }
		if (IntRect(228, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 68; }
		if (IntRect(228, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 69; }
		if (IntRect(228, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 70; }


		if (IntRect(262, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 71; }
		if (IntRect(262, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 72; }
		if (IntRect(262, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 73; }
		if (IntRect(262, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 74; }
		if (IntRect(262, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 75; }
		if (IntRect(262, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 76; }
		if (IntRect(262, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 77; }
		if (IntRect(262, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 78; }
		if (IntRect(262, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 79; }
		if (IntRect(262, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 80; }


		if (IntRect(296, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 81; }
		if (IntRect(296, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 82; }
		if (IntRect(296, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 83; }
		if (IntRect(296, 102, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 84; }
		if (IntRect(296, 136, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 85; }
		if (IntRect(296, 170, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 86; }
		if (IntRect(296, 204, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 87; }
		if (IntRect(296, 238, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 88; }
		if (IntRect(296, 272, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 89; }
		if (IntRect(296, 306, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 90; }

	// horisontal
		if (IntRect(0, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 91; }
		if (IntRect(34, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 92; }
		if (IntRect(68, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 93; }
		if (IntRect(102, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 94; }
		if (IntRect(136, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 95; }
		if (IntRect(170, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 96; }
		if (IntRect(204, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 97; }
		if (IntRect(238, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 98; }
		if (IntRect(272, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 99; }
		if (IntRect(306, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 100; }

		if (IntRect(0, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 101; }
		if (IntRect(34, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 102; }
		if (IntRect(68, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 103; }
		if (IntRect(102, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 104; }
		if (IntRect(136, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 105; }
		if (IntRect(170, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 106; }
		if (IntRect(204, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 107; }
		if (IntRect(238, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 108; }
		if (IntRect(272, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 109; }
		if (IntRect(306, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 110; }

		if (IntRect(0, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 111; }
		if (IntRect(34, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 112; }
		if (IntRect(68, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 113; }
		if (IntRect(102, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 114; }
		if (IntRect(136, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 115; }
		if (IntRect(170, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 116; }
		if (IntRect(204, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 117; }
		if (IntRect(238, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 118; }
		if (IntRect(272, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 119; }
		if (IntRect(306, 92, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 120; }

		if (IntRect(0, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 121; }
		if (IntRect(34, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 122; }
		if (IntRect(68, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 123; }
		if (IntRect(102, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 124; }
		if (IntRect(136, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 125; }
		if (IntRect(170, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 126; }
		if (IntRect(204, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 127; }
		if (IntRect(238, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 128; }
		if (IntRect(272, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 129; }
		if (IntRect(306, 126, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 130; }

		if (IntRect(0, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 131; }
		if (IntRect(34, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 132; }
		if (IntRect(68, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 133; }
		if (IntRect(102, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 134; }
		if (IntRect(136, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 135; }
		if (IntRect(170, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 136; }
		if (IntRect(204, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 137; }
		if (IntRect(238, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 138; }
		if (IntRect(272, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 139; }
		if (IntRect(306, 160, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 140; }





	return ms_position;
}

// ################## class Game ##################
void Game::draw_game(RenderWindow & window) {
	// ############## draw field
	float x = 30, y = 0;
	const int size_rect_x = 30, size_rect_y = 30;
	RectangleShape rectangle[size_rect_x][size_rect_y];
	for (int i = 0; i < 9; i++) {				// vertical
		for (int j = 0; j < 10; j++) {
			rectangle[i][j].setSize(Vector2f(4, 34));
			rectangle[i][j].setPosition(x, y);
			rectangle[i][j].setFillColor(Color::Black);
			rectangle[i][j].setRotation(0);
			y += 34;
		}
		x += 34;
		y = 0;
	}
	x = 0;
	y = 34;
	for (int i = 9; i < 19; i++) {			// horisontal
		for (int j = 10; j < 20; j++) {
			rectangle[i][j].setSize(Vector2f(4, 30));
			rectangle[i][j].setPosition(x, y);
			rectangle[i][j].setFillColor(Color::Black);
			rectangle[i][j].setRotation(-90);
			x += 34;
		}
		x = 0;
		y += 34;
	} //draw field ###############

	const int xindex = 10, yindex = 10;
	MyLines arr[xindex][yindex];
	for (int i = 0; i < 10; i++) {
		arr[i][0].set_left(1);
	};
	for (int i = 0; i < 10; i++) {
		arr[i][9].set_right(1);
	};
	for (int i = 0; i < 10; i++) {
		arr[0][i].set_top(1);
	};
	for (int i = 0; i < 10; i++) {
		arr[9][i].set_bottom(1);
	}; // задали начальные значени€ дл€ крайних квадратиков 
	float temp_x = 0, temp_y = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j].set_coord(temp_x, temp_y);
			temp_x += 34;
		}
		temp_x = 0;
		temp_y += 34;
	} // задали координаты дл€ спрайтов

	MyLines xx[10][10], oo[10][10];
	int i = 0, j = 0;
	for(int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) {
			xx[i][j].krestik_txt.loadFromFile("images/x.png");					//загрузили текстуру
			xx[i][j].krestik;													//объ€вили спрайт 
			xx[i][j].krestik.setTexture(xx[i][j].krestik_txt);					//загрузили текстуру в спрайт
			//xx[i][j].krestik.setPosition(arr[i][j].coord_x, arr[i][j].coord_y); //задали позицию
		}
	}
			
	
	int ms_position = 0;
	Player player_x, player_o;
	player_x.set_step(true);
				//######## game loop
	while (!Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.clear(Color::White);
		ms_position = gt_ms_position(ms_position, window);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) { window.close(); }
			
			while (player_x.step)
			{
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
				{
				switch (ms_position) {
					// vertical
				case 1:
				{
					arr[0][0].set_right(1);
					arr[0][1].set_left(1);
					++arr[0][0];
					++arr[0][1];
					rectangle[0][0].setFillColor(Color::Blue);
					break;
				}
				case 2:
				{
					arr[1][0].set_right(1);
					arr[1][1].set_left(1);
					++arr[1][0];
					++arr[1][1];
					rectangle[0][1].setFillColor(Color::Blue);
					break;
				}
				case 3:
				{
					arr[2][0].set_right(1);
					arr[2][1].set_left(1);
					++arr[2][0];
					++arr[2][1];
					rectangle[0][2].setFillColor(Color::Blue);
					break;
				}
				case 4:
				{
					arr[3][0].set_right(1);
					arr[3][1].set_left(1);
					++arr[3][0];
					++arr[3][1];
					rectangle[0][3].setFillColor(Color::Blue);
					break;
				}
				case 5:
				{
					arr[4][0].set_right(1);
					arr[4][1].set_left(1);
					++arr[4][0];
					++arr[4][1];
					rectangle[0][4].setFillColor(Color::Blue);
					break;
				}
				case 6:
				{
					arr[5][0].set_right(1);
					arr[5][1].set_left(1);
					++arr[5][0];
					++arr[5][1];
					rectangle[0][5].setFillColor(Color::Blue);
					break;
				}
				case 7:
				{
					arr[6][0].set_right(1);
					arr[6][1].set_left(1);
					++arr[6][0];
					++arr[6][1];
					rectangle[0][6].setFillColor(Color::Blue);
					break;
				}
				case 8:
				{
					arr[7][0].set_right(1);
					arr[7][1].set_left(1);
					++arr[7][0];
					++arr[7][1];
					rectangle[0][7].setFillColor(Color::Blue);
					break;
				}
				case 9:
				{
					arr[8][0].set_right(1);
					arr[8][1].set_left(1);
					++arr[8][0];
					++arr[8][1];
					rectangle[0][8].setFillColor(Color::Blue);
					break;
				}
				case 10:
				{
					arr[9][0].set_right(1);
					arr[9][1].set_left(1);
					++arr[9][0];
					++arr[9][1];
					rectangle[0][9].setFillColor(Color::Blue);
					break;
				}
				case 11:
				{
					arr[0][1].set_right(1);
					arr[0][2].set_left(1);
					++arr[0][1];
					++arr[0][2];
					rectangle[1][0].setFillColor(Color::Blue);
					break;
				}
				case 12:
				{
					arr[1][1].set_right(1);
					arr[1][2].set_left(1);
					++arr[1][1];
					++arr[1][2];
					rectangle[1][1].setFillColor(Color::Blue);
					break;
				}
				case 13:
				{
					arr[2][1].set_right(1);
					arr[2][2].set_left(1);
					++arr[2][1];
					++arr[2][2];
					rectangle[1][2].setFillColor(Color::Blue);
					break;
				}
				case 14:
				{
					arr[3][1].set_right(1);
					arr[3][2].set_left(1);
					++arr[3][1];
					++arr[3][2];
					rectangle[1][3].setFillColor(Color::Blue);
					break;
				}
				case 15:
				{
					arr[4][1].set_right(1);
					arr[4][2].set_left(1);
					++arr[4][1];
					++arr[4][2];
					rectangle[1][4].setFillColor(Color::Blue);
					break;
				}
				case 16:
				{
					arr[5][1].set_right(1);
					arr[5][2].set_left(1);
					++arr[5][1];
					++arr[5][2];
					rectangle[1][5].setFillColor(Color::Blue);
					break;
				}
				case 17:
				{
					arr[6][1].set_right(1);
					arr[6][2].set_left(1);
					++arr[6][1];
					++arr[6][2];
					rectangle[1][6].setFillColor(Color::Blue);
					break;
				}
				case 18:
				{
					arr[7][1].set_right(1);
					arr[7][2].set_left(1);
					++arr[7][1];
					++arr[7][2];
					rectangle[1][7].setFillColor(Color::Blue);
					break;
				}
				case 19:
				{
					arr[8][1].set_right(1);
					arr[8][2].set_left(1);
					++arr[8][1];
					++arr[8][2];
					rectangle[1][8].setFillColor(Color::Blue);
					break;
				}
				case 20:
				{
					arr[9][1].set_right(1);
					arr[9][2].set_left(1);
					++arr[9][1];
					++arr[9][2];
					rectangle[1][9].setFillColor(Color::Blue);
					break;
				}
				case 21:
				{
					arr[0][2].set_right(1);
					arr[0][3].set_left(1);
					++arr[0][2];
					++arr[0][3];
					rectangle[2][0].setFillColor(Color::Blue);
					break;
				}
				case 22:
				{
					arr[1][2].set_right(1);
					arr[1][3].set_left(1);
					++arr[1][2];
					++arr[1][3];
					rectangle[2][1].setFillColor(Color::Blue);
					break;
				}
				case 23:
				{
					arr[2][2].set_right(1);
					arr[2][3].set_left(1);
					++arr[2][2];
					++arr[2][3];
					rectangle[2][2].setFillColor(Color::Blue);
					break;
				}
				case 24:
				{
					arr[3][2].set_right(1);
					arr[3][3].set_left(1);
					++arr[3][2];
					++arr[3][3];
					rectangle[2][3].setFillColor(Color::Blue);
					break;
				}
				case 25:
				{
					arr[4][2].set_right(1);
					arr[4][3].set_left(1);
					++arr[4][2];
					++arr[4][3];
					rectangle[2][4].setFillColor(Color::Blue);
					break;
				}
				case 26:
				{
					arr[5][2].set_right(1);
					arr[5][3].set_left(1);
					++arr[5][2];
					++arr[5][3];
					rectangle[2][5].setFillColor(Color::Blue);
					break;
				}
				case 27:
				{
					arr[6][2].set_right(1);
					arr[6][3].set_left(1);
					++arr[6][2];
					++arr[6][3];
					rectangle[2][6].setFillColor(Color::Blue);
					break;
				}
				case 28:
				{
					arr[7][2].set_right(1);
					arr[7][3].set_left(1);
					++arr[7][2];
					++arr[7][3];
					rectangle[2][7].setFillColor(Color::Blue);
					break;
				}
				case 29:
				{
					arr[8][2].set_right(1);
					arr[8][3].set_left(1);
					++arr[8][2];
					++arr[8][3];
					rectangle[2][8].setFillColor(Color::Blue);
					break;
				}
				case 30:
				{
					arr[9][2].set_right(1);
					arr[9][3].set_left(1);
					++arr[9][2];
					++arr[9][3];
					rectangle[2][9].setFillColor(Color::Blue);
					break;
				}
				case 31:
				{
					arr[0][3].set_right(1);
					arr[0][4].set_left(1);
					++arr[0][3];
					++arr[0][4];
					rectangle[3][0].setFillColor(Color::Blue);
					break;
				}
				case 32:
				{
					arr[1][3].set_right(1);
					arr[1][4].set_left(1);
					++arr[1][3];
					++arr[1][4];
					rectangle[3][1].setFillColor(Color::Blue);
					break;
				}
				case 33:
				{
					arr[2][3].set_right(1);
					arr[2][4].set_left(1);
					++arr[2][3];
					++arr[2][4];
					rectangle[3][2].setFillColor(Color::Blue);
					break;
				}
				case 34:
				{
					arr[3][3].set_right(1);
					arr[3][4].set_left(1);
					++arr[3][3];
					++arr[3][4];
					rectangle[3][3].setFillColor(Color::Blue);
					break;
				}
				case 35:
				{
					arr[4][3].set_right(1);
					arr[4][4].set_left(1);
					++arr[4][3];
					++arr[4][4];
					rectangle[3][4].setFillColor(Color::Blue);
					break;
				}
				case 36:
				{
					arr[5][3].set_right(1);
					arr[5][4].set_left(1);
					++arr[5][4];
					++arr[5][3];
					rectangle[3][5].setFillColor(Color::Blue);
					break;
				}
				case 37:
				{
					arr[6][3].set_right(1);
					arr[6][4].set_left(1);
					++arr[6][4];
					++arr[6][3];
					rectangle[3][6].setFillColor(Color::Blue);
					break;
				}
				case 38:
				{
					arr[7][3].set_right(1);
					arr[7][4].set_left(1);
					++arr[7][4];
					++arr[7][3];
					rectangle[3][7].setFillColor(Color::Blue);
					break;
				}
				case 39:
				{
					arr[8][3].set_right(1);
					arr[8][4].set_left(1);
					++arr[8][4];
					++arr[8][3];
					rectangle[3][8].setFillColor(Color::Blue);
					break;
				}
				case 40:
				{
					arr[9][3].set_right(1);
					arr[9][4].set_left(1);
					++arr[9][4];
					++arr[9][3];
					rectangle[3][9].setFillColor(Color::Blue);
					break;
				}
				case 41:
				{
					arr[0][4].set_right(1);
					arr[0][5].set_left(1);
					++arr[0][5];
					++arr[0][4];
					rectangle[4][0].setFillColor(Color::Blue);
					break;
				}
				case 42:
				{
					arr[1][4].set_right(1);
					arr[1][5].set_left(1);
					++arr[1][5];
					++arr[1][4];
					rectangle[4][1].setFillColor(Color::Blue);
					break;
				}
				case 43:
				{
					arr[2][4].set_right(1);
					arr[2][5].set_left(1);
					++arr[2][5];
					++arr[2][4];
					rectangle[4][2].setFillColor(Color::Blue);
					break;
				}
				case 44:
				{
					arr[3][4].set_right(1);
					arr[3][5].set_left(1);
					++arr[3][4];
					++arr[3][5];
					rectangle[4][3].setFillColor(Color::Blue);
					break;
				}
				case 45:
				{
					arr[4][4].set_right(1);
					arr[4][5].set_left(1);
					++arr[4][5];
					++arr[4][4];
					rectangle[4][4].setFillColor(Color::Blue);
					break;
				}
				case 46:
				{
					arr[5][4].set_right(1);
					arr[5][5].set_left(1);
					++arr[5][4];
					++arr[5][5];
					rectangle[4][5].setFillColor(Color::Blue);
					break;
				}
				case 47:
				{
					arr[6][4].set_right(1);
					arr[6][5].set_left(1);
					++arr[6][4];
					++arr[6][5];
					rectangle[4][6].setFillColor(Color::Blue);
					break;
				}
				case 48:
				{
					arr[7][4].set_right(1);
					arr[7][5].set_left(1);
					++arr[7][4];
					++arr[7][5];
					rectangle[4][7].setFillColor(Color::Blue);
					break;
				}
				case 49:
				{
					arr[8][4].set_right(1);
					arr[8][5].set_left(1);
					++arr[8][4];
					++arr[8][5];
					rectangle[4][8].setFillColor(Color::Blue);
					break;
				}
				case 50:
				{
					arr[9][4].set_right(1);
					arr[9][5].set_left(1);
					++arr[9][4];
					++arr[9][5];
					rectangle[4][9].setFillColor(Color::Blue);
					break;
				}
				// horizontal
				case 91:
				{
					arr[0][0].set_bottom(1);
					arr[1][0].set_top(1);
					++arr[0][0];
					++arr[1][0];
					rectangle[9][10].setFillColor(Color::Blue);
					break;
				}
				case 92:
				{
					arr[0][1].set_bottom(1);
					arr[1][1].set_top(1);
					++arr[0][1];
					++arr[1][1];
					rectangle[9][11].setFillColor(Color::Blue);
					break;
				}
				case 93:
				{
					arr[0][2].set_bottom(1);
					arr[1][2].set_top(1);
					++arr[0][2];
					++arr[1][2];
					rectangle[9][12].setFillColor(Color::Blue);
					break;
				}
				case 94:
				{
					arr[0][3].set_bottom(1);
					arr[1][3].set_top(1);
					++arr[0][3];
					++arr[1][3];
					rectangle[9][13].setFillColor(Color::Blue);
					break;
				}
				case 95:
				{
					arr[0][4].set_bottom(1);
					arr[1][4].set_top(1);
					++arr[0][4];
					++arr[1][4];
					rectangle[9][14].setFillColor(Color::Blue);
					break;
				}
				case 96:
				{
					arr[0][5].set_bottom(1);
					arr[1][5].set_top(1);
					++arr[0][5];
					++arr[1][5];
					rectangle[9][15].setFillColor(Color::Blue);
					break;
				}
				case 97:
				{
					arr[0][6].set_bottom(1);
					arr[1][6].set_top(1);
					++arr[0][6];
					++arr[1][6];
					rectangle[9][16].setFillColor(Color::Blue);
					break;
				}
				case 98:
				{
					arr[0][7].set_bottom(1);
					arr[1][7].set_top(1);
					++arr[0][7];
					++arr[1][7];
					rectangle[9][17].setFillColor(Color::Blue);
					break;
				}
				case 99:
				{
					arr[0][8].set_bottom(1);
					arr[1][8].set_top(1);
					++arr[0][8];
					++arr[1][8];
					rectangle[9][18].setFillColor(Color::Blue);
					break;
				}
				case 100:
				{
					arr[0][9].set_bottom(1);
					arr[1][9].set_top(1);
					++arr[0][9];
					++arr[1][9];
					rectangle[9][19].setFillColor(Color::Blue);
					break;
				}
				case 101:
				{
					arr[1][0].set_bottom(1);
					arr[2][0].set_top(1);
					++arr[1][0];
					++arr[2][0];
					rectangle[10][10].setFillColor(Color::Blue);
					break;
				}
				case 102:
				{
					arr[1][1].set_bottom(1);
					arr[2][1].set_top(1);
					++arr[2][1];
					++arr[1][1];
					rectangle[10][11].setFillColor(Color::Blue);
					break;
				}
				case 103:
				{
					arr[1][2].set_bottom(1);
					arr[2][2].set_top(1);
					++arr[1][2];
					++arr[2][2];
					rectangle[10][12].setFillColor(Color::Blue);
					break;
				}
				case 104:
				{
					arr[1][3].set_bottom(1);
					arr[2][3].set_top(1);
					++arr[1][3];
					++arr[2][3];
					rectangle[10][13].setFillColor(Color::Blue);
					break;
				}
				case 105:
				{
					arr[1][4].set_bottom(1);
					arr[2][4].set_top(1);
					++arr[1][4];
					++arr[2][4];
					rectangle[10][14].setFillColor(Color::Blue);
					break;
				}
				case 106:
				{
					arr[1][5].set_bottom(1);
					arr[2][5].set_top(1);
					++arr[1][5];
					++arr[2][5];
					rectangle[10][15].setFillColor(Color::Blue);
					break;
				}
				case 107:
				{
					arr[1][6].set_bottom(1);
					arr[2][6].set_top(1);
					++arr[2][6];
					++arr[1][6];
					rectangle[10][16].setFillColor(Color::Blue);
					break;
				}
				case 108:
				{
					arr[1][7].set_bottom(1);
					arr[2][7].set_top(1);
					++arr[2][7];
					++arr[1][7];
					rectangle[10][17].setFillColor(Color::Blue);
					break;
				}
				case 109:
				{
					arr[1][8].set_bottom(1);
					arr[2][8].set_top(1);
					++arr[1][8];
					++arr[2][8];
					rectangle[10][18].setFillColor(Color::Blue);
					break;
				}
				case 110:
				{
					arr[1][9].set_bottom(1);
					arr[2][9].set_top(1);
					++arr[1][9];
					++arr[2][9];
					rectangle[10][19].setFillColor(Color::Blue);
					break;
				}
				case 111:
				{
					arr[2][0].set_bottom(1);
					arr[3][0].set_top(1);
					++arr[3][0];
					++arr[2][0];
					rectangle[11][10].setFillColor(Color::Blue);
					break;
				}
				case 112:
				{
					arr[2][1].set_bottom(1);
					arr[3][1].set_top(1);
					++arr[2][1];
					++arr[3][1];
					rectangle[11][11].setFillColor(Color::Blue);
					break;
				}
				case 113:
				{
					arr[2][2].set_bottom(1);
					arr[3][2].set_top(1);
					++arr[3][2];
					++arr[2][2];
					rectangle[11][12].setFillColor(Color::Blue);
					break;
				}
				case 114:
				{
					arr[2][3].set_bottom(1);
					arr[3][3].set_top(1);
					++arr[3][3];
					++arr[2][3];
					rectangle[11][13].setFillColor(Color::Blue);
					break;
				}
				case 115:
				{
					arr[2][4].set_bottom(1);
					arr[3][4].set_top(1);
					++arr[2][4];
					++arr[3][4];
					rectangle[11][14].setFillColor(Color::Blue);
					break;
				}
				case 116:
				{
					arr[2][5].set_bottom(1);
					arr[3][5].set_top(1);
					++arr[3][5];
					++arr[2][5];
					rectangle[11][15].setFillColor(Color::Blue);
					break;
				}
				case 117:
				{
					arr[2][6].set_bottom(1);
					arr[3][6].set_top(1);
					++arr[3][6];
					++arr[2][6];
					rectangle[11][16].setFillColor(Color::Blue);
					break;
				}
				case 118:
				{
					arr[2][7].set_bottom(1);
					arr[3][7].set_top(1);
					++arr[3][7];
					++arr[2][7];
					rectangle[11][17].setFillColor(Color::Blue);
					break;
				}
				case 119:
				{
					arr[2][8].set_bottom(1);
					arr[3][8].set_top(1);
					++arr[2][8];
					++arr[3][8];
					rectangle[11][18].setFillColor(Color::Blue);
					break;
				}
				case 120:
				{
					arr[2][9].set_bottom(1);
					arr[3][9].set_top(1);
					++arr[3][9];
					++arr[2][9];
					rectangle[11][19].setFillColor(Color::Blue);
					break;
				}
				case 121:
				{
					arr[3][0].set_bottom(1);
					arr[4][0].set_top(1);
					++arr[3][0];
					++arr[4][0];
					rectangle[12][10].setFillColor(Color::Blue);
					break;
				}
				case 122:
				{
					arr[3][1].set_bottom(1);
					arr[4][1].set_top(1);
					++arr[3][1];
					++arr[4][1];
					rectangle[12][11].setFillColor(Color::Blue);
					break;
				}
				case 123:
				{
					arr[3][2].set_bottom(1);
					arr[4][2].set_top(1);
					++arr[4][2];
					++arr[3][2];
					rectangle[12][12].setFillColor(Color::Blue);
					break;
				}
				case 124:
				{
					arr[3][3].set_bottom(1);
					arr[4][3].set_top(1);
					++arr[3][3];
					++arr[4][3];
					rectangle[12][13].setFillColor(Color::Blue);
					break;
				}
				case 125:
				{
					arr[3][4].set_bottom(1);
					arr[4][4].set_top(1);
					++arr[3][4];
					++arr[4][4];
					rectangle[12][14].setFillColor(Color::Blue);
					break;
				}
				case 126:
				{
					arr[3][5].set_bottom(1);
					arr[4][5].set_top(1);
					++arr[3][5];
					++arr[4][5];
					rectangle[12][15].setFillColor(Color::Blue);
					break;
				}
				case 127:
				{
					arr[3][6].set_bottom(1);
					arr[4][6].set_top(1);
					++arr[3][6];
					++arr[4][6];
					rectangle[12][16].setFillColor(Color::Blue);
					break;
				}
				case 128:
				{
					arr[3][7].set_bottom(1);
					arr[4][7].set_top(1);
					++arr[3][7];
					++arr[4][7];
					rectangle[12][17].setFillColor(Color::Blue);
					break;
				}
				case 129:
				{
					arr[3][8].set_bottom(1);
					arr[4][8].set_top(1);
					++arr[4][8];
					++arr[3][8];
					rectangle[12][18].setFillColor(Color::Blue);
					break;
				}
				case 130:
				{
					arr[3][9].set_bottom(1);
					arr[4][9].set_top(1);
					++arr[3][9];
					++arr[4][9];
					rectangle[12][19].setFillColor(Color::Blue);
					break;
				}
				case 131:
				{
					arr[4][0].set_bottom(1);
					arr[5][0].set_top(1);
					++arr[4][0];
					++arr[5][0];
					rectangle[13][10].setFillColor(Color::Blue);
					break;
				}
				case 132:
				{
					arr[4][1].set_bottom(1);
					arr[5][1].set_top(1);
					++arr[5][1];
					++arr[4][1];
					rectangle[13][11].setFillColor(Color::Blue);
					break;
				}
				case 133:
				{
					arr[4][2].set_bottom(1);
					arr[5][2].set_top(1);
					++arr[4][2];
					++arr[5][2];
					rectangle[13][12].setFillColor(Color::Blue);
					break;
				}
				case 134:
				{
					arr[4][3].set_bottom(1);
					arr[5][3].set_top(1);
					++arr[4][3];
					++arr[5][3];
					rectangle[13][13].setFillColor(Color::Blue);
					break;
				}
				case 135:
				{
					arr[4][4].set_bottom(1);
					arr[5][4].set_top(1);
					++arr[5][4];
					++arr[4][4];
					rectangle[13][14].setFillColor(Color::Blue);
					break;
				}
				case 136:
				{
					arr[4][5].set_bottom(1);
					arr[5][5].set_top(1);
					++arr[5][5];
					++arr[4][5];
					rectangle[13][15].setFillColor(Color::Blue);
					break;
				}
				case 137:
				{
					arr[4][6].set_bottom(1);
					arr[5][6].set_top(1);
					++arr[4][6];
					++arr[5][6];
					rectangle[13][16].setFillColor(Color::Blue);
					break;
				}
				case 138:
				{
					arr[4][7].set_bottom(1);
					arr[5][7].set_top(1);
					++arr[5][7];
					++arr[4][7];
					rectangle[13][17].setFillColor(Color::Blue);
					break;
				}
				case 139:
				{
					arr[4][8].set_bottom(1);
					arr[5][8].set_top(1);
					++arr[4][8];
					++arr[5][8];
					rectangle[13][18].setFillColor(Color::Blue);
					break;
				}
				case 140:
				{
					arr[4][9].set_bottom(1);
					arr[5][9].set_top(1);
					++arr[5][9];
					++arr[4][9];
					rectangle[13][19].setFillColor(Color::Blue);
					break;
				}
				};
				}
				//проход массива объектов(проверка на 4 палочки в квадрате):
				for (int i = 0; i < 10; i++) 
				{
					for (int j = 0; j < 10; j++)
					{
						if (arr[i][j].get_count() == 4) 
						{	
							xx[i][j].krestik_txt.loadFromFile("images/x.png");					//загрузили текстуру
							xx[i][j].krestik;													//объ€вили спрайт 
							xx[i][j].krestik.setTexture(xx[i][j].krestik_txt);					//загрузили текстуру в спрайт
							xx[i][j].krestik.setPosition(arr[i][j].coord_x, arr[i][j].coord_y); //задали позицию		
							window.draw(xx[i][j].krestik);
							++player_x;
							++arr[i][j];
						}
						else {
							player_x.set_step(false);
							player_o.set_step(true);
						}
					}
				}
			}

			while (player_o.step) {
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
				{
					switch (ms_position) {
						// vertical
					case 1:
					{
						arr[0][0].set_right(1);
						arr[0][1].set_left(1);
						++arr[0][0];
						++arr[0][1];
						rectangle[0][0].setFillColor(Color::Red);
						break;
					}
					case 2:
					{
						arr[1][0].set_right(1);
						arr[1][1].set_left(1);
						++arr[1][0];
						++arr[1][1];
						rectangle[0][1].setFillColor(Color::Red);
						break;
					}
					case 3:
					{
						arr[2][0].set_right(1);
						arr[2][1].set_left(1);
						++arr[2][0];
						++arr[2][1];
						rectangle[0][2].setFillColor(Color::Red);
						break;
					}
					case 4:
					{
						arr[3][0].set_right(1);
						arr[3][1].set_left(1);
						++arr[3][0];
						++arr[3][1];
						rectangle[0][3].setFillColor(Color::Red);
						break;
					}
					case 5:
					{
						arr[4][0].set_right(1);
						arr[4][1].set_left(1);
						++arr[4][0];
						++arr[4][1];
						rectangle[0][4].setFillColor(Color::Red);
						break;
					}
					case 6:
					{
						arr[5][0].set_right(1);
						arr[5][1].set_left(1);
						++arr[5][0];
						++arr[5][1];
						rectangle[0][5].setFillColor(Color::Red);
						break;
					}
					case 7:
					{
						arr[6][0].set_right(1);
						arr[6][1].set_left(1);
						++arr[6][0];
						++arr[6][1];
						rectangle[0][6].setFillColor(Color::Red);
						break;
					}
					case 8:
					{
						arr[7][0].set_right(1);
						arr[7][1].set_left(1);
						++arr[7][0];
						++arr[7][1];
						rectangle[0][7].setFillColor(Color::Red);
						break;
					}
					case 9:
					{
						arr[8][0].set_right(1);
						arr[8][1].set_left(1);
						++arr[8][0];
						++arr[8][1];
						rectangle[0][8].setFillColor(Color::Red);
						break;
					}
					case 10:
					{
						arr[9][0].set_right(1);
						arr[9][1].set_left(1);
						++arr[9][0];
						++arr[9][1];
						rectangle[0][9].setFillColor(Color::Red);
						break;
					}
					case 11:
					{
						arr[0][1].set_right(1);
						arr[0][2].set_left(1);
						++arr[0][1];
						++arr[0][2];
						rectangle[1][0].setFillColor(Color::Red);
						break;
					}
					case 12:
					{
						arr[1][1].set_right(1);
						arr[1][2].set_left(1);
						++arr[1][1];
						++arr[1][2];
						rectangle[1][1].setFillColor(Color::Red);
						break;
					}
					case 13:
					{
						arr[2][1].set_right(1);
						arr[2][2].set_left(1);
						++arr[2][1];
						++arr[2][2];
						rectangle[1][2].setFillColor(Color::Red);
						break;
					}
					case 14:
					{
						arr[3][1].set_right(1);
						arr[3][2].set_left(1);
						++arr[3][1];
						++arr[3][2];
						rectangle[1][3].setFillColor(Color::Red);
						break;
					}
					case 15:
					{
						arr[4][1].set_right(1);
						arr[4][2].set_left(1);
						++arr[4][1];
						++arr[4][2];
						rectangle[1][4].setFillColor(Color::Red);
						break;
					}
					case 16:
					{
						arr[5][1].set_right(1);
						arr[5][2].set_left(1);
						++arr[5][1];
						++arr[5][2];
						rectangle[1][5].setFillColor(Color::Red);
						break;
					}
					case 17:
					{
						arr[6][1].set_right(1);
						arr[6][2].set_left(1);
						++arr[6][1];
						++arr[6][2];
						rectangle[1][6].setFillColor(Color::Red);
						break;
					}
					case 18:
					{
						arr[7][1].set_right(1);
						arr[7][2].set_left(1);
						++arr[7][1];
						++arr[7][2];
						rectangle[1][7].setFillColor(Color::Red);
						break;
					}
					case 19:
					{
						arr[8][1].set_right(1);
						arr[8][2].set_left(1);
						++arr[8][1];
						++arr[8][2];
						rectangle[1][8].setFillColor(Color::Red);
						break;
					}
					case 20:
					{
						arr[9][1].set_right(1);
						arr[9][2].set_left(1);
						++arr[9][1];
						++arr[9][2];
						rectangle[1][9].setFillColor(Color::Red);
						break;
					}
					case 21:
					{
						arr[0][2].set_right(1);
						arr[0][3].set_left(1);
						++arr[0][2];
						++arr[0][3];
						rectangle[2][0].setFillColor(Color::Red);
						break;
					}
					case 22:
					{
						arr[1][2].set_right(1);
						arr[1][3].set_left(1);
						++arr[1][2];
						++arr[1][3];
						rectangle[2][1].setFillColor(Color::Red);
						break;
					}
					case 23:
					{
						arr[2][2].set_right(1);
						arr[2][3].set_left(1);
						++arr[2][2];
						++arr[2][3];
						rectangle[2][2].setFillColor(Color::Red);
						break;
					}
					case 24:
					{
						arr[3][2].set_right(1);
						arr[3][3].set_left(1);
						++arr[3][2];
						++arr[3][3];
						rectangle[2][3].setFillColor(Color::Red);
						break;
					}
					case 25:
					{
						arr[4][2].set_right(1);
						arr[4][3].set_left(1);
						++arr[4][2];
						++arr[4][3];
						rectangle[2][4].setFillColor(Color::Red);
						break;
					}
					case 26:
					{
						arr[5][2].set_right(1);
						arr[5][3].set_left(1);
						++arr[5][2];
						++arr[5][3];
						rectangle[2][5].setFillColor(Color::Red);
						break;
					}
					case 27:
					{
						arr[6][2].set_right(1);
						arr[6][3].set_left(1);
						++arr[6][2];
						++arr[6][3];
						rectangle[2][6].setFillColor(Color::Red);
						break;
					}
					case 28:
					{
						arr[7][2].set_right(1);
						arr[7][3].set_left(1);
						++arr[7][2];
						++arr[7][3];
						rectangle[2][7].setFillColor(Color::Red);
						break;
					}
					case 29:
					{
						arr[8][2].set_right(1);
						arr[8][3].set_left(1);
						++arr[8][2];
						++arr[8][3];
						rectangle[2][8].setFillColor(Color::Red);
						break;
					}
					case 30:
					{
						arr[9][2].set_right(1);
						arr[9][3].set_left(1);
						++arr[9][2];
						++arr[9][3];
						rectangle[2][9].setFillColor(Color::Red);
						break;
					}
					case 31:
					{
						arr[0][3].set_right(1);
						arr[0][4].set_left(1);
						++arr[0][3];
						++arr[0][4];
						rectangle[3][0].setFillColor(Color::Red);
						break;
					}
					case 32:
					{
						arr[1][3].set_right(1);
						arr[1][4].set_left(1);
						++arr[1][3];
						++arr[1][4];
						rectangle[3][1].setFillColor(Color::Red);
						break;
					}
					case 33:
					{
						arr[2][3].set_right(1);
						arr[2][4].set_left(1);
						++arr[2][3];
						++arr[2][4];
						rectangle[3][2].setFillColor(Color::Red);
						break;
					}
					case 34:
					{
						arr[3][3].set_right(1);
						arr[3][4].set_left(1);
						++arr[3][3];
						++arr[3][4];
						rectangle[3][3].setFillColor(Color::Red);
						break;
					}
					case 35:
					{
						arr[4][3].set_right(1);
						arr[4][4].set_left(1);
						++arr[4][3];
						++arr[4][4];
						rectangle[3][4].setFillColor(Color::Red);
						break;
					}
					case 36:
					{
						arr[5][3].set_right(1);
						arr[5][4].set_left(1);
						++arr[5][4];
						++arr[5][3];
						rectangle[3][5].setFillColor(Color::Red);
						break;
					}
					case 37:
					{
						arr[6][3].set_right(1);
						arr[6][4].set_left(1);
						++arr[6][4];
						++arr[6][3];
						rectangle[3][6].setFillColor(Color::Red);
						break;
					}
					case 38:
					{
						arr[7][3].set_right(1);
						arr[7][4].set_left(1);
						++arr[7][4];
						++arr[7][3];
						rectangle[3][7].setFillColor(Color::Red);
						break;
					}
					case 39:
					{
						arr[8][3].set_right(1);
						arr[8][4].set_left(1);
						++arr[8][4];
						++arr[8][3];
						rectangle[3][8].setFillColor(Color::Red);
						break;
					}
					case 40:
					{
						arr[9][3].set_right(1);
						arr[9][4].set_left(1);
						++arr[9][4];
						++arr[9][3];
						rectangle[3][9].setFillColor(Color::Red);
						break;
					}
					case 41:
					{
						arr[0][4].set_right(1);
						arr[0][5].set_left(1);
						++arr[0][5];
						++arr[0][4];
						rectangle[4][0].setFillColor(Color::Red);
						break;
					}
					case 42:
					{
						arr[1][4].set_right(1);
						arr[1][5].set_left(1);
						++arr[1][5];
						++arr[1][4];
						rectangle[4][1].setFillColor(Color::Red);
						break;
					}
					case 43:
					{
						arr[2][4].set_right(1);
						arr[2][5].set_left(1);
						++arr[2][5];
						++arr[2][4];
						rectangle[4][2].setFillColor(Color::Red);
						break;
					}
					case 44:
					{
						arr[3][4].set_right(1);
						arr[3][5].set_left(1);
						++arr[3][4];
						++arr[3][5];
						rectangle[4][3].setFillColor(Color::Red);
						break;
					}
					case 45:
					{
						arr[4][4].set_right(1);
						arr[4][5].set_left(1);
						++arr[4][5];
						++arr[4][4];
						rectangle[4][4].setFillColor(Color::Red);
						break;
					}
					case 46:
					{
						arr[5][4].set_right(1);
						arr[5][5].set_left(1);
						++arr[5][4];
						++arr[5][5];
						rectangle[4][5].setFillColor(Color::Red);
						break;
					}
					case 47:
					{
						arr[6][4].set_right(1);
						arr[6][5].set_left(1);
						++arr[6][4];
						++arr[6][5];
						rectangle[4][6].setFillColor(Color::Red);
						break;
					}
					case 48:
					{
						arr[7][4].set_right(1);
						arr[7][5].set_left(1);
						++arr[7][4];
						++arr[7][5];
						rectangle[4][7].setFillColor(Color::Red);
						break;
					}
					case 49:
					{
						arr[8][4].set_right(1);
						arr[8][5].set_left(1);
						++arr[8][4];
						++arr[8][5];
						rectangle[4][8].setFillColor(Color::Red);
						break;
					}
					case 50:
					{
						arr[9][4].set_right(1);
						arr[9][5].set_left(1);
						++arr[9][4];
						++arr[9][5];
						rectangle[4][9].setFillColor(Color::Red);
						break;
					}
					// horizontal
					case 91:
					{
						arr[0][0].set_bottom(1);
						arr[1][0].set_top(1);
						++arr[0][0];
						++arr[1][0];
						rectangle[9][10].setFillColor(Color::Red);
						break;
					}
					case 92:
					{
						arr[0][1].set_bottom(1);
						arr[1][1].set_top(1);
						++arr[0][1];
						++arr[1][1];
						rectangle[9][11].setFillColor(Color::Red);
						break;
					}
					case 93:
					{
						arr[0][2].set_bottom(1);
						arr[1][2].set_top(1);
						++arr[0][2];
						++arr[1][2];
						rectangle[9][12].setFillColor(Color::Red);
						break;
					}
					case 94:
					{
						arr[0][3].set_bottom(1);
						arr[1][3].set_top(1);
						++arr[0][3];
						++arr[1][3];
						rectangle[9][13].setFillColor(Color::Red);
						break;
					}
					case 95:
					{
						arr[0][4].set_bottom(1);
						arr[1][4].set_top(1);
						++arr[0][4];
						++arr[1][4];
						rectangle[9][14].setFillColor(Color::Red);
						break;
					}
					case 96:
					{
						arr[0][5].set_bottom(1);
						arr[1][5].set_top(1);
						++arr[0][5];
						++arr[1][5];
						rectangle[9][15].setFillColor(Color::Red);
						break;
					}
					case 97:
					{
						arr[0][6].set_bottom(1);
						arr[1][6].set_top(1);
						++arr[0][6];
						++arr[1][6];
						rectangle[9][16].setFillColor(Color::Red);
						break;
					}
					case 98:
					{
						arr[0][7].set_bottom(1);
						arr[1][7].set_top(1);
						++arr[0][7];
						++arr[1][7];
						rectangle[9][17].setFillColor(Color::Red);
						break;
					}
					case 99:
					{
						arr[0][8].set_bottom(1);
						arr[1][8].set_top(1);
						++arr[0][8];
						++arr[1][8];
						rectangle[9][18].setFillColor(Color::Red);
						break;
					}
					case 100:
					{
						arr[0][9].set_bottom(1);
						arr[1][9].set_top(1);
						++arr[0][9];
						++arr[1][9];
						rectangle[9][19].setFillColor(Color::Red);
						break;
					}
					case 101:
					{
						arr[1][0].set_bottom(1);
						arr[2][0].set_top(1);
						++arr[1][0];
						++arr[2][0];
						rectangle[10][10].setFillColor(Color::Red);
						break;
					}
					case 102:
					{
						arr[1][1].set_bottom(1);
						arr[2][1].set_top(1);
						++arr[2][1];
						++arr[1][1];
						rectangle[10][11].setFillColor(Color::Red);
						break;
					}
					case 103:
					{
						arr[1][2].set_bottom(1);
						arr[2][2].set_top(1);
						++arr[1][2];
						++arr[2][2];
						rectangle[10][12].setFillColor(Color::Red);
						break;
					}
					case 104:
					{
						arr[1][3].set_bottom(1);
						arr[2][3].set_top(1);
						++arr[1][3];
						++arr[2][3];
						rectangle[10][13].setFillColor(Color::Red);
						break;
					}
					case 105:
					{
						arr[1][4].set_bottom(1);
						arr[2][4].set_top(1);
						++arr[1][4];
						++arr[2][4];
						rectangle[10][14].setFillColor(Color::Red);
						break;
					}
					case 106:
					{
						arr[1][5].set_bottom(1);
						arr[2][5].set_top(1);
						++arr[1][5];
						++arr[2][5];
						rectangle[10][15].setFillColor(Color::Red);
						break;
					}
					case 107:
					{
						arr[1][6].set_bottom(1);
						arr[2][6].set_top(1);
						++arr[2][6];
						++arr[1][6];
						rectangle[10][16].setFillColor(Color::Red);
						break;
					}
					case 108:
					{
						arr[1][7].set_bottom(1);
						arr[2][7].set_top(1);
						++arr[2][7];
						++arr[1][7];
						rectangle[10][17].setFillColor(Color::Red);
						break;
					}
					case 109:
					{
						arr[1][8].set_bottom(1);
						arr[2][8].set_top(1);
						++arr[1][8];
						++arr[2][8];
						rectangle[10][18].setFillColor(Color::Red);
						break;
					}
					case 110:
					{
						arr[1][9].set_bottom(1);
						arr[2][9].set_top(1);
						++arr[1][9];
						++arr[2][9];
						rectangle[10][19].setFillColor(Color::Red);
						break;
					}
					case 111:
					{
						arr[2][0].set_bottom(1);
						arr[3][0].set_top(1);
						++arr[3][0];
						++arr[2][0];
						rectangle[11][10].setFillColor(Color::Red);
						break;
					}
					case 112:
					{
						arr[2][1].set_bottom(1);
						arr[3][1].set_top(1);
						++arr[2][1];
						++arr[3][1];
						rectangle[11][11].setFillColor(Color::Red);
						break;
					}
					case 113:
					{
						arr[2][2].set_bottom(1);
						arr[3][2].set_top(1);
						++arr[3][2];
						++arr[2][2];
						rectangle[11][12].setFillColor(Color::Red);
						break;
					}
					case 114:
					{
						arr[2][3].set_bottom(1);
						arr[3][3].set_top(1);
						++arr[3][3];
						++arr[2][3];
						rectangle[11][13].setFillColor(Color::Red);
						break;
					}
					case 115:
					{
						arr[2][4].set_bottom(1);
						arr[3][4].set_top(1);
						++arr[2][4];
						++arr[3][4];
						rectangle[11][14].setFillColor(Color::Red);
						break;
					}
					case 116:
					{
						arr[2][5].set_bottom(1);
						arr[3][5].set_top(1);
						++arr[3][5];
						++arr[2][5];
						rectangle[11][15].setFillColor(Color::Red);
						break;
					}
					case 117:
					{
						arr[2][6].set_bottom(1);
						arr[3][6].set_top(1);
						++arr[3][6];
						++arr[2][6];
						rectangle[11][16].setFillColor(Color::Red);
						break;
					}
					case 118:
					{
						arr[2][7].set_bottom(1);
						arr[3][7].set_top(1);
						++arr[3][7];
						++arr[2][7];
						rectangle[11][17].setFillColor(Color::Red);
						break;
					}
					case 119:
					{
						arr[2][8].set_bottom(1);
						arr[3][8].set_top(1);
						++arr[2][8];
						++arr[3][8];
						rectangle[11][18].setFillColor(Color::Red);
						break;
					}
					case 120:
					{
						arr[2][9].set_bottom(1);
						arr[3][9].set_top(1);
						++arr[3][9];
						++arr[2][9];
						rectangle[11][19].setFillColor(Color::Red);
						break;
					}
					case 121:
					{
						arr[3][0].set_bottom(1);
						arr[4][0].set_top(1);
						++arr[3][0];
						++arr[4][0];
						rectangle[12][10].setFillColor(Color::Red);
						break;
					}
					case 122:
					{
						arr[3][1].set_bottom(1);
						arr[4][1].set_top(1);
						++arr[3][1];
						++arr[4][1];
						rectangle[12][11].setFillColor(Color::Red);
						break;
					}
					case 123:
					{
						arr[3][2].set_bottom(1);
						arr[4][2].set_top(1);
						++arr[4][2];
						++arr[3][2];
						rectangle[12][12].setFillColor(Color::Red);
						break;
					}
					case 124:
					{
						arr[3][3].set_bottom(1);
						arr[4][3].set_top(1);
						++arr[3][3];
						++arr[4][3];
						rectangle[12][13].setFillColor(Color::Red);
						break;
					}
					case 125:
					{
						arr[3][4].set_bottom(1);
						arr[4][4].set_top(1);
						++arr[3][4];
						++arr[4][4];
						rectangle[12][14].setFillColor(Color::Red);
						break;
					}
					case 126:
					{
						arr[3][5].set_bottom(1);
						arr[4][5].set_top(1);
						++arr[3][5];
						++arr[4][5];
						rectangle[12][15].setFillColor(Color::Red);
						break;
					}
					case 127:
					{
						arr[3][6].set_bottom(1);
						arr[4][6].set_top(1);
						++arr[3][6];
						++arr[4][6];
						rectangle[12][16].setFillColor(Color::Red);
						break;
					}
					case 128:
					{
						arr[3][7].set_bottom(1);
						arr[4][7].set_top(1);
						++arr[3][7];
						++arr[4][7];
						rectangle[12][17].setFillColor(Color::Red);
						break;
					}
					case 129:
					{
						arr[3][8].set_bottom(1);
						arr[4][8].set_top(1);
						++arr[4][8];
						++arr[3][8];
						rectangle[12][18].setFillColor(Color::Red);
						break;
					}
					case 130:
					{
						arr[3][9].set_bottom(1);
						arr[4][9].set_top(1);
						++arr[3][9];
						++arr[4][9];
						rectangle[12][19].setFillColor(Color::Red);
						break;
					}
					case 131:
					{
						arr[4][0].set_bottom(1);
						arr[5][0].set_top(1);
						++arr[4][0];
						++arr[5][0];
						rectangle[13][10].setFillColor(Color::Red);
						break;
					}
					case 132:
					{
						arr[4][1].set_bottom(1);
						arr[5][1].set_top(1);
						++arr[5][1];
						++arr[4][1];
						rectangle[13][11].setFillColor(Color::Red);
						break;
					}
					case 133:
					{
						arr[4][2].set_bottom(1);
						arr[5][2].set_top(1);
						++arr[4][2];
						++arr[5][2];
						rectangle[13][12].setFillColor(Color::Red);
						break;
					}
					case 134:
					{
						arr[4][3].set_bottom(1);
						arr[5][3].set_top(1);
						++arr[4][3];
						++arr[5][3];
						rectangle[13][13].setFillColor(Color::Red);
						break;
					}
					case 135:
					{
						arr[4][4].set_bottom(1);
						arr[5][4].set_top(1);
						++arr[5][4];
						++arr[4][4];
						rectangle[13][14].setFillColor(Color::Red);
						break;
					}
					case 136:
					{
						arr[4][5].set_bottom(1);
						arr[5][5].set_top(1);
						++arr[5][5];
						++arr[4][5];
						rectangle[13][15].setFillColor(Color::Red);
						break;
					}
					case 137:
					{
						arr[4][6].set_bottom(1);
						arr[5][6].set_top(1);
						++arr[4][6];
						++arr[5][6];
						rectangle[13][16].setFillColor(Color::Red);
						break;
					}
					case 138:
					{
						arr[4][7].set_bottom(1);
						arr[5][7].set_top(1);
						++arr[5][7];
						++arr[4][7];
						rectangle[13][17].setFillColor(Color::Red);
						break;
					}
					case 139:
					{
						arr[4][8].set_bottom(1);
						arr[5][8].set_top(1);
						++arr[4][8];
						++arr[5][8];
						rectangle[13][18].setFillColor(Color::Red);
						break;
					}
					case 140:
					{
						arr[4][9].set_bottom(1);
						arr[5][9].set_top(1);
						++arr[5][9];
						++arr[4][9];
						rectangle[13][19].setFillColor(Color::Red);
						break;
					}
					};
				}
				//проход массива объектов(проверка на 4 палочки в квадрате):
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (arr[i][j].get_count() == 4)
						{

							xx[i][j].nolik_txt.loadFromFile("images/o.png");					//загрузили текстуру
							xx[i][j].nolik;													//объ€вили спрайт 
							xx[i][j].nolik.setTexture(xx[i][j].nolik_txt);					//загрузили текстуру в спрайт
							xx[i][j].nolik.setPosition(arr[i][j].coord_x, arr[i][j].coord_y); //задали позицию		
							window.draw(xx[i][j].nolik);										//test
							++player_o;
							++arr[i][j];
						}
						else { 
							player_o.set_step(false);
							player_x.set_step(true);
						}
					}
				}
			}
		
			

			
			for (int i = 0; i < size_rect_x; i++) {
				for (int j = 0; j < size_rect_y; j++) {
					window.draw(rectangle[i][j]);
				}
			}
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					
				}
			}
			window.display();
		};//game loop ########
	}
};


// ################## class Menu ##################
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

	//////////////////////////////ћ≈Ќё///////////////////
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
		window.clear(Color::White);

		if (IntRect(60, 30, 200, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(35, 90, 250, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
		if (IntRect(60, 140, 200, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		if (IntRect(90, 190, 150, 50).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Red); menuNum = 4; }
		if (IntRect(90, 240, 150, 50).contains(Mouse::getPosition(window))) { menu5.setColor(Color::Blue); menuNum = 5; }
		// цикл событий(в дополнение к обработке пользовательских событий, он даЄт возможность 
		//окну обрабатывать и внутренние событи€, которые необходимы дл€ реагировани€ на 
		//изменени€ размера окна и перемещени€ его)
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) {
					Game gm_ob;
					gm_ob.draw_game(window);

				}//если нажали первую кнопку, то рисуем поле 
				if (menuNum == 2) {
				}
				if (menuNum == 3) {
					window.draw(menu6);
					window.draw(menu7);
					window.display();
					while (!Keyboard::isKeyPressed(Keyboard::Escape));
					if (IntRect(80, 80, 100, 50).contains(Mouse::getPosition(window))) {
						menu6.setColor(Color::Red); menuNum = 6;
					}
					if (IntRect(25, 180, 200, 50).contains(Mouse::getPosition(window))) {
						menu7.setColor(Color::Blue); menuNum = 7;
					}
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



