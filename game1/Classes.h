#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// ����� ��� �������� ����(������ ����, �������� � ���� ��� ������ ����)
class Game {
	int gameMode; // 0 - Duel; 1 - with computer
	int queue; // 0 - ����� �����, 1 - ����� �������, 2 - ����� ���������(�������)
	int field_size; // 10�10 �� ���������
	bool first_klick;// �������� ������� ������� �� 
					 //������� �����(1-� ���� - ���� �� "New Game")
	bool music_sensor; // ������������� ������������ ������
	bool isComp; // ��������� ����� ���� isComp = true
	int square_closed; // ������������� ��� ���������� ����������
public:
	Game();
	Game & set_FieldSize(int);
	Game &  set_queue(int);
	Game &  set_gameMode(int);
	int get_gameMode() { return gameMode; }
	int get_queue() { return queue; };
	int get_FieldSize() {return field_size;};
	void start_game(RenderWindow & window, int);
	bool winnerDetected(int count1, int count2, int sizeOfField);
	int gt_ms_position(RenderWindow & window, int sizeOfField);
};

// ���� ��� ����������� ����
class Menu {
	bool isMenu; // ���� ���� �������
	int menuNum; // ����� �������� � ����
	Game gm_ob;
public:
	Menu(){
		isMenu = 1; menuNum = 0;
	}
	void draw_menu(RenderWindow & window);
};

// ����� ���������� ��� ���������� ��� ������� � ����������:
class MyLines {
	int left, right, top, bottom, // 0 - ������� �� ����������, 1 - ����������
		count; // ���-�� ������� � �������� 
	int
		// ���������� 4-� �������(rectangle) ��� ���������
		left_rectangle_i, left_rectangle_j,
		right_rectangle_i, right_rectangle_j,
		top_rectangle_i, top_rectangle_j,
		bottom_rectangle_i, bottom_rectangle_j,
		// ������ 4-� ������� � ������ ��������
		left_number,
		right_number,
		top_number,
		bottom_number;
	float coord_x, coord_y; // ��� ��������� ��������� � �������
public:
	MyLines();
	int get_left() { return left; }
	int get_right() { return right; }
	int get_top() { return top; }
	int get_bottom() { return bottom; }
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
	MyLines & operator ++ (); // ����������� count(���-�� ������� � ��������)
	Texture krestik_txt, nolik_txt;
	Sprite krestik, nolik; // ��� ������� ���������� ��������� �������� �������� � ������
};

// ����� ��� ����� �����
class Player {
	int count ; // ���-�� ��������� ��� �������(��� ������� ������)
public:
	Player() { count = 0; }
	int get_count() { return count; };
	Player & operator ++(); // ����������� count(���-�� ��������� ��� �������(��� ������� ������))
};

// ����� ��� ��������� �����(��������� � �������), ������� ��������� �� ������ ������
class Figure {
	int figure_i, figure_j; // ���������� ������, � ������� ����� �������� ������
public:
	Figure & set_figure_i(int i);
	Figure & set_figure_j(int j);
	int get_figure_i() { return figure_i; }
	int get_figure_j() { return figure_j; }
};

