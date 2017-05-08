#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class MyLines {
	int left, right, top, bottom, count;
	

public:
	float coord_x, coord_y;
	MyLines() { left = 0, right = 0, top = 0, bottom = 0, count = 2; };
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
	int count; // ���-�� ��������� ��� �������

protected:
public:
	bool step = false; // ��� ������ �����
	bool get_step() { return step; }
	int  get__count() { return count; }
	Player & set_step(bool step);
	Player & operator ++();
};
