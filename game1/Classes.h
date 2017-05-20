#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class MyLines {

	int left, right, top, bottom,
		count; // кол-во палочек в квадрате 
	int 
		// координаты 4-х палочек(rectangle) для квадратов
		left_rectangle_i, left_rectangle_j,
		right_rectangle_i, right_rectangle_j,
		top_rectangle_i, top_rectangle_j,
		bottom_rectangle_i, bottom_rectangle_j,
		// номера 4-х палочек в каждом квадрате
		left_number,
		right_number,
		top_number,
		bottom_number;
	float coord_x, coord_y; // для рисования крестиков и ноликов
public:
	
	MyLines();
	float get_coord_x() { return coord_x; };
	float get_coord_y() { return coord_y; };
	int get_count() { return count; };
	int get_left_rectangle_i() { return left_rectangle_i; };
	int get_left_rectangle_j() { return left_rectangle_j; };
	int get_right_rectangle_i() { return right_rectangle_i; };
	int get_right_rectangle_j() { return right_rectangle_j; };
	int get_top_rectangle_i() { return top_rectangle_i; };
	int get_top_rectangle_j() { return top_rectangle_j; };
	int get_bottom_rectangle_i() { return bottom_rectangle_i; };
	int get_bottom_rectangle_j() { return bottom_rectangle_j; };
	int get_left_number() { return left_number; };
	int get_right_number() { return right_number; };
	int get_top_number() { return top_number; };
	int get_bottom_number() { return bottom_number; };
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
	MyLines & set_right_number(int num);
	MyLines & set_left_number(int num);
	MyLines & set_bottom_number(int num);
	MyLines & set_top_number(int num);
};

class Game {
	int field_size = 10; // 10х10 по умолчанию
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