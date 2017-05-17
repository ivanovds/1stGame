#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class MyLines {

	int left, right, top, bottom, 
	count, // кол-во палочек в квадрате 
	// переменные для компютера(чтоб мог окрашивать палочки)
	left_rectangle_i, left_rectangle_j,
	right_rectangle_i, right_rectangle_j,
	top_rectangle_i, top_rectangle_j,
	bottom_rectangle_i, bottom_rectangle_j;
	float coord_x, coord_y; // для рисования крестиков и ноликов
public:
	MyLines() { left = 0, right = 0, top = 0, bottom = 0, count = 0; };
	float get_coord_x() { return coord_x; };
	float get_coord_y() { return coord_y; };
	int get_count() { return count; };
	MyLines & set_left(int left);
	MyLines & set_right(int right);
	MyLines & set_top(int top);
	MyLines & set_bottom(int bottom);
	MyLines & set_coord(float centre_x, float centre_y);
	MyLines & operator ++ ();
	Texture krestik_txt, nolik_txt;
	Sprite krestik, nolik;
	MyLines & set_left_rectangle_i(int i);
	MyLines & set_left_rectangle_j(int j);
	MyLines & set_right_rectangle_i(int i);
	MyLines & set_right_rectangle_j(int j);
	MyLines & set_top_rectangle_i(int i);
	MyLines & set_top_rectangle_j(int j);
	MyLines & set_bottom_rectangle_i(int i);
	MyLines & set_bottom_rectangle_j(int j);
};

class Game {
	int field_size = 3; // 10х10 по умолчанию
public:
	Game & set_FieldSize(int);
	int get_FieldSize() {return field_size;};
	void draw_game(RenderWindow & window, int, int);
};


class Menu {
	int game_mode = 0;
public:
	void draw_menu(RenderWindow & window);
};

class Player {
	int count = 0; // кол-во крестиков или ноликов
public:
	int get_count() { return count; };
	Player & operator ++();
};

class Figure {
	int figure_i, figure_j;
public:
	Figure & set_figure_i(int i);
	Figure & set_figure_j(int j);
	int get_figure_i() { return figure_i; }
	int get_figure_j() { return figure_j; }
};

class Comp : public Player {

public:

};