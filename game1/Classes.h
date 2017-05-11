#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class MyLines {
	int left, right, top, bottom, count;
public:
	float coord_x, coord_y;
	MyLines() { left = 0, right = 0, top = 0, bottom = 0, count = 0; };
	float get_coord_x() {return coord_x;}
	float get_coord_y() {return coord_y;}
	int get_count() { return count; };
	MyLines & set_left(int left);
	MyLines & set_right(int right);
	MyLines & set_top(int top);
	MyLines & set_bottom(int bottom);
	MyLines & set_coord(float centre_x, float centre_y);
	MyLines & operator ++ ();
	Texture krestik_txt, nolik_txt;
	Sprite krestik, nolik;

};

class Game {
	int per = 0;
	MyLines ln;

public:
	void draw_game(RenderWindow & window);

};


class Menu {
	Game gm;
public:
	void draw_menu(RenderWindow & window);
	
};

class Player {
	int count = 0; // кол-во крестиков или ноликов

public:
	int get_count() { return count; };
	bool step = false; // кто сейчас ходит
	bool get_step() { return step; }
	int  get__count() { return count; }
	Player & set_step(bool step);
	Player & operator ++();
};

class Figure {
	int figure_i, figure_j;
public:
	~Figure(){ };
	Figure & set_figure_i(int i);
	Figure & set_figure_j(int j);
	int get_figure_i() { return figure_i; }
	int get_figure_j() { return figure_j; }
};

