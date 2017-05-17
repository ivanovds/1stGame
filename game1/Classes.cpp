#include<iostream>
#include <SFML/Graphics.hpp>
#include"Classes.h"
#include <sstream> // работа со строками в потоке
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

// функции:
bool winnerDetected(int count1, int count2, int sizeOfField);
void comp(MyLines **arr_copy);

// ################## class Figure ##################
Figure & Figure::set_figure_i(int i) {
	figure_i = i;
	return *this;
};
Figure & Figure::set_figure_j(int j) {
	figure_j = j;
	return *this;
};

// ################## class Player ##################
Player & Player::operator ++() {
	++count;
	return *this;
};

// ################## class MYLines ##################
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
MyLines & MyLines::set_left_rectangle_i(int i) {
	left_rectangle_i = i;
	return *this;
};
MyLines & MyLines::set_left_rectangle_j(int j) {
	left_rectangle_j = j;
	return *this;
};
MyLines & MyLines::set_right_rectangle_i(int i) {
	right_rectangle_i = i;
	return *this;
};
MyLines & MyLines::set_right_rectangle_j(int j) {
	right_rectangle_j = j;
	return *this;
};
MyLines & MyLines::set_top_rectangle_i(int i) {
	top_rectangle_i = i;
	return *this;
};
MyLines & MyLines::set_top_rectangle_j(int j) {
	top_rectangle_j = j;
	return *this;
};
MyLines & MyLines::set_bottom_rectangle_i(int i) {
	bottom_rectangle_i = i;
	return *this;
};
MyLines & MyLines::set_bottom_rectangle_j(int j) {
	bottom_rectangle_j = j;
	return *this;
};


// Mouse position 
int gt_ms_position(int ms_position, RenderWindow & window, int sizeOfField) {
	// vertical
	
		if (IntRect(24, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 1; }
		if (IntRect(24, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 2; }
		if (IntRect(24, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 3; }
		if (IntRect(24, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 4; }
		if (IntRect(24, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 5; }
		if (IntRect(24, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 6; }
		if (IntRect(24, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 7; }
		if (IntRect(24, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 8; }
		if (IntRect(24, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 9; }
		if (IntRect(24, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 10; }
		
		if (IntRect(58, 0, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 11; }
		if (IntRect(58, 34, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 12; }
		if (IntRect(58, 68, 16, 34).contains(Mouse::getPosition(window))) { ms_position = 13; }
		if (IntRect(58, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 14; }
		if (IntRect(58, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 15; }
		if (IntRect(58, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 16; }
		if (IntRect(58, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 17; }
		if (IntRect(58, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 18; }
		if (IntRect(58, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 19; }
		if (IntRect(58, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 20; }

		if (IntRect(92, 0, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 21; }
		if (IntRect(92, 34, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 22; }
		if (IntRect(92, 68, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 23; }
		if (IntRect(92, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 24; }
		if (IntRect(92, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 25; }
		if (IntRect(92, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 26; }
		if (IntRect(92, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 27; }
		if (IntRect(92, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 28; }
		if (IntRect(92, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 29; }
		if (IntRect(92, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 30; }


		if (IntRect(126, 0, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 31; }
		if (IntRect(126, 34, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 32; }
		if (IntRect(126, 68, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 33; }
		if (IntRect(126, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 34; }
		if (IntRect(126, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 35; }
		if (IntRect(126, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 36; }
		if (IntRect(126, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 37; }
		if (IntRect(126, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 38; }
		if (IntRect(126, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 39; }
		if (IntRect(126, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 40; }


		if (IntRect(160, 0, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 41; }
		if (IntRect(160, 34, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 42; }
		if (IntRect(160, 68, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 43; }
		if (IntRect(160, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 44; }
		if (IntRect(160, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 45; }
		if (IntRect(160, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 46; }
		if (IntRect(160, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 47; }
		if (IntRect(160, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 48; }
		if (IntRect(160, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 49; }
		if (IntRect(160, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 50; }


		if (IntRect(194, 0, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 51; }
		if (IntRect(194, 34, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 52; }
		if (IntRect(194, 68, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 53; }
		if (IntRect(194, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 54; }
		if (IntRect(194, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 55; }
		if (IntRect(194, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 56; }
		if (IntRect(194, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 57; }
		if (IntRect(194, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 58; }
		if (IntRect(194, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 59; }
		if (IntRect(194, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 60; }


		if (IntRect(228, 0, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 61; }
		if (IntRect(228, 34, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 62; }
		if (IntRect(228, 68, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 63; }
		if (IntRect(228, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 64; }
		if (IntRect(228, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 65; }
		if (IntRect(228, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 66; }
		if (IntRect(228, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 67; }
		if (IntRect(228, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 68; }
		if (IntRect(228, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 69; }
		if (IntRect(228, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 70; }


		if (IntRect(262, 0, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 71; }
		if (IntRect(262, 34, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 72; }
		if (IntRect(262, 68, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 73; }
		if (IntRect(262, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 74; }
		if (IntRect(262, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 75; }
		if (IntRect(262, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 76; }
		if (IntRect(262, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 77; }
		if (IntRect(262, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 78; }
		if (IntRect(262, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 79; }
		if (IntRect(262, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 80; }


		if (IntRect(296, 0, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 81; }
		if (IntRect(296, 34, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 82; }
		if (IntRect(296, 68, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 83; }
		if (IntRect(296, 102, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 84; }
		if (IntRect(296, 136, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 85; }
		if (IntRect(296, 170, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 86; }
		if (IntRect(296, 204, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 87; }
		if (IntRect(296, 238, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 88; }
		if (IntRect(296, 272, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 89; }
		if (IntRect(296, 306, 16, 34).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 90; }

	// horisontal
		if (IntRect(0, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 91; }
		if (IntRect(34, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 92; }
		if (IntRect(68, 24, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 93; }
		if (IntRect(102, 24, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 94; }
		if (IntRect(136, 24, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 95; }
		if (IntRect(170, 24, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 96; }
		if (IntRect(204, 24, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 97; }
		if (IntRect(238, 24, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 98; }
		if (IntRect(272, 24, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 99; }
		if (IntRect(306, 24, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 100; }

		if (IntRect(0, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 101; }
		if (IntRect(34, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 102; }
		if (IntRect(68, 58, 30, 16).contains(Mouse::getPosition(window))) { ms_position = 103; }
		if (IntRect(102, 58, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 104; }
		if (IntRect(136, 58, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 105; }
		if (IntRect(170, 58, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 106; }
		if (IntRect(204, 58, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 107; }
		if (IntRect(238, 58, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 108; }
		if (IntRect(272, 58, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 109; }
		if (IntRect(306, 58, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 110; }

		if (IntRect(0, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 111; }
		if (IntRect(34, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 112; }
		if (IntRect(68, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 113; }
		if (IntRect(102, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 114; }
		if (IntRect(136, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 115; }
		if (IntRect(170, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 116; }
		if (IntRect(204, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 117; }
		if (IntRect(238, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 118; }
		if (IntRect(272, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 119; }
		if (IntRect(306, 92, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 120; }

		if (IntRect(0, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 121; }
		if (IntRect(34, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 122; }
		if (IntRect(68, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 123; }
		if (IntRect(102, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 124; }
		if (IntRect(136, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 1) { ms_position = 125; }
		if (IntRect(170, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 126; }
		if (IntRect(204, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 127; }
		if (IntRect(238, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 128; }
		if (IntRect(272, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 129; }
		if (IntRect(306, 126, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 130; }

		if (IntRect(0, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 131; }
		if (IntRect(34, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 132; }
		if (IntRect(68, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 133; }
		if (IntRect(102, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 134; }
		if (IntRect(136, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 135; }
		if (IntRect(170, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 136; }
		if (IntRect(204, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 137; }
		if (IntRect(238, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 138; }
		if (IntRect(272, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 139; }
		if (IntRect(306, 160, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 140; }

		if (IntRect(0, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 141; }
		if (IntRect(34, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 142; }
		if (IntRect(68, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 143; }
		if (IntRect(102, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 144; }
		if (IntRect(136, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 145; }
		if (IntRect(170, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 146; }
		if (IntRect(204, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 147; }
		if (IntRect(238, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 148; }
		if (IntRect(272, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 149; }
		if (IntRect(306, 194, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 150; }

		if (IntRect(0, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 151; }
		if (IntRect(34, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 152; }
		if (IntRect(68, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 153; }
		if (IntRect(102, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 154; }
		if (IntRect(136, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 155; }
		if (IntRect(170, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 156; }
		if (IntRect(204, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 157; }
		if (IntRect(238, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 158; }
		if (IntRect(272, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 159; }
		if (IntRect(306, 228, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 160; }

		if (IntRect(0, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 161; }
		if (IntRect(34, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 162; }
		if (IntRect(68, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 163; }
		if (IntRect(102, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 164; }
		if (IntRect(136, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 165; }
		if (IntRect(170, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 166; }
		if (IntRect(204, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 167; }
		if (IntRect(238, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 168; }
		if (IntRect(272, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 169; }
		if (IntRect(306, 262, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 170; }

		if (IntRect(0, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 171; }
		if (IntRect(34, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 172; }
		if (IntRect(68, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 173; }
		if (IntRect(102, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 174; }
		if (IntRect(136, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 175; }
		if (IntRect(170, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 176; }
		if (IntRect(204, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 177; }
		if (IntRect(238, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 178; }
		if (IntRect(272, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 179; }
		if (IntRect(306, 296, 30, 16).contains(Mouse::getPosition(window)) && sizeOfField > 2) { ms_position = 180; }

		if (IntRect(0, 333, 340, 84).contains(Mouse::getPosition(window))) { ms_position = 0; } // нижняя часть поля(инфоблок)
		
	return ms_position;
}

// ################## class Game ##################
void Game::draw_game(RenderWindow & window, int sizeOfField, int game_mode ) {
	// ############## задаем координаты палочек
	float x = 30, y = 0;
	RectangleShape rectangle[20][20];
	for (int i = 0; i < 9; i++) {				// vertical
		for (int j = 0; j < 10; j++) {
			rectangle[i][j].setSize(Vector2f(4, 34));
			rectangle[i][j].setPosition(x, y);
			rectangle[i][j].setFillColor(Color(128, 128, 128));
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
			rectangle[i][j].setFillColor(Color(128, 128, 128));
			rectangle[i][j].setRotation(-90);
			x += 34;
		}
		x = 0;
		y += 34;

	}//задали координаты палочек ###############
	
	 // цвет для крайних неактивных палочек:
	if(sizeOfField == 3){							//10x10
	for (int j = 10; j < 20; j++) {					
		rectangle[18][j].setFillColor(Color::Black);
	}
	}
	if (sizeOfField == 2) {							//5x5
		for (int i = 0; i < 5; i++) {
			rectangle[4][i].setFillColor(Color::Black);
		}
		for (int j = 10; j < 15; j++) {
			rectangle[13][j].setFillColor(Color::Black);
		}
	}
	if (sizeOfField == 1) {							//3x3
		for (int i = 0; i < 3; i++) {
			rectangle[2][i].setFillColor(Color::Black);
		}
		for (int j = 10; j < 13; j++) {
			rectangle[11][j].setFillColor(Color::Black);
		}
	}
	//  начальные значения для крайних квадратиков:
	MyLines arr[10][10];
	for (int i = 0; i < 10; i++) {
		arr[i][0].set_left(1);
		++arr[i][0];
	};
	for (int i = 0; i < 10; i++) {
		arr[i][9].set_right(1);
		++arr[i][9];
	};
	for (int i = 0; i < 10; i++) {
		arr[0][i].set_top(1);
		++arr[0][i];
	};
	for (int i = 0; i < 10; i++) {
		arr[9][i].set_bottom(1);
		++arr[9][i];
	};  
	//5x5:
	if (sizeOfField == 2) {
		for (int i = 0; i < 5; i++) {
			arr[4][i].set_bottom(1);
			++arr[4][i];
		};
		for (int i = 0; i < 5; i++) {
			arr[i][4].set_bottom(1);
			++arr[i][4];
		};
	}
	//3x3:
	if (sizeOfField == 1) {
		for (int i = 0; i < 3; i++) {
			arr[2][i].set_bottom(1);
			++arr[2][i];
		};
		for (int i = 0; i < 3; i++) {
			arr[i][2].set_bottom(1);
			++arr[i][2];
		};
	}
	// номера палочек для каждой клетки(для компа): 
	// вертикальные:
	for (int j = 1; j < 9; j++) {
		for (int i = 0; i < 10; i++) {
			arr[i][j].set_left_rectangle_i(j-1).set_left_rectangle_j(i).
				set_right_rectangle_i(j).set_right_rectangle_j(i);
		}
	}
	for (int i = 0; i < 10; i++) { // для крайних столбиков:
		arr[i][0].set_right_rectangle_i(0).set_right_rectangle_j(i);
		arr[i][9].set_left_rectangle_i(8).set_left_rectangle_j(i);
	}
	// горизонтальные:
	for (int i = 0; i < 10; i++) {
		for (int j = 1; j < 9; j++){
			arr[i][j].set_top_rectangle_i(9+i).set_top_rectangle_j(9+j).
				set_bottom_rectangle_i(10+i).set_bottom_rectangle_j(9 + j);
		}
	}
	for (int i = 0; i < 10; i++) { // для крайних строчек:
		arr[0][i].set_top_rectangle_i(9).set_top_rectangle_j(i+10);
		arr[9][i].set_bottom_rectangle_i(18).set_bottom_rectangle_j(i+10);
	}
	// делаем копию массива arr для ИИ:
	MyLines **arr_copy = new MyLines *[10];
	for (int i = 0; i < 10; i++) {
		arr_copy[i] = new MyLines[10];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr_copy[i][j] = arr[i][j];
		}
	}

	// задаём координаты для спрайтов:
	float temp_x = 0, temp_y = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j].set_coord(temp_x, temp_y);
			temp_x += 34;
		}
		temp_x = 0;
		temp_y += 34;
	} 
	// Рисование текста:
	Font font;
	font.loadFromFile("Capture_it.ttf");
	Text text0("", font, 25);
	Text text("", font, 25);
	Text text1("", font, 25);
	Text text2("", font, 25);
	Text text3("press Esc to go to menu ", font, 10);
	text1.setFillColor(Color::Blue);
	text2.setFillColor(Color::Red);
	text3.setFillColor(Color::Black);
	text0.setPosition(155,345);
	text.setPosition(155, 345);
	text1.setPosition(10, 345);
	text2.setPosition(80, 345);
	text3.setPosition(5, 375);
	//  создаем оъекты
	MyLines xx[10][10], oo[10][10]; // массивы для спрайтов
	int size_krestik = 0 , size_nolik = 0; //количество крестиков и ноликов, которые нужно рисовать
	Figure fig1[101], fig2[101];  // массивы для координат клеток, в которых нужно рисовать фигуры
	int ms_position = 0; // позиция курсора
	Player player_x, player_o; 
	Comp player_comp;
	
	int sensor_klick[20][20];  // предотвращает повторный клик по палочке 
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			sensor_klick[i][j] = 0;
		}
	}
	bool first_klick = true;// начинаем ставить палочки со 
						    //второго клика(1-й клик - клик по "New Game")
	int queue(1); // 0 - ходит нолик, 1 - ходит крестик, 2 - ходит компьютер(ноликом)
	if (game_mode == 1) {
		queue = 2;
	}
	Music music;//создаем объект музыки
	music.openFromFile("music.ogg");//загружаем файл
	bool music_sensor = true;
	
	//############################################## game loop ##############################################
	while (!Keyboard::isKeyPressed(Keyboard::Escape))
	{
		int queue_2 = 0; // увеличивыется при закрывании квадратика
		window.clear(Color::White);
		ms_position = gt_ms_position(ms_position, window, sizeOfField); //получаем положение курсора
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) { window.close(); }
		if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
		{	if(!first_klick){
			switch (ms_position) {
						// vertical
					case 1:
					{		if (sensor_klick[0][0] == 0) {
							arr[0][0].set_right(1);
							arr[0][1].set_left(1);
							++arr[0][0];
							++arr[0][1];
							if (queue == 1) { rectangle[0][0].setFillColor(Color::Blue); }
							else { rectangle[0][0].setFillColor(Color::Red); }
						}
					else { ms_position = 0; };
					sensor_klick[0][0] = 1;
						break;
					}
					case 2:
					{	if (sensor_klick[0][1] == 0) {
						arr[1][0].set_right(1);
						arr[1][1].set_left(1);
						++arr[1][0];
						++arr[1][1];
						if (queue == 1) { rectangle[0][1].setFillColor(Color::Blue); }
						else { rectangle[0][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][1] = 1;
					break;
					}
					case 3:
					{	if (sensor_klick[0][2] == 0) {
						arr[2][0].set_right(1);
						arr[2][1].set_left(1);
						++arr[2][0];
						++arr[2][1];
						if (queue == 1) { rectangle[0][2].setFillColor(Color::Blue); }
						else { rectangle[0][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][2] = 1;
					break;
					}
					case 4:
					{	if (sensor_klick[0][3] == 0) {
						arr[3][0].set_right(1);
						arr[3][1].set_left(1);
						++arr[3][0];
						++arr[3][1];
						if (queue == 1) { rectangle[0][3].setFillColor(Color::Blue); }
						else { rectangle[0][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][3] = 1;
					break;
					}
					case 5:
					{	if (sensor_klick[0][4] == 0) {
						arr[4][0].set_right(1);
						arr[4][1].set_left(1);
						++arr[4][0];
						++arr[4][1];
						if (queue == 1) { rectangle[0][4].setFillColor(Color::Blue); }
						else { rectangle[0][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][4] = 1;
					break;
					}
					case 6:
					{	if (sensor_klick[0][5] == 0) {
						arr[5][0].set_right(1);
						arr[5][1].set_left(1);
						++arr[5][0];
						++arr[5][1];
						if (queue == 1) { rectangle[0][5].setFillColor(Color::Blue); }
						else { rectangle[0][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][5] = 1;
					break;
					}
					case 7:
					{	if (sensor_klick[0][6] == 0) {
						arr[6][0].set_right(1);
						arr[6][1].set_left(1);
						++arr[6][0];
						++arr[6][1];
						if (queue == 1) { rectangle[0][6].setFillColor(Color::Blue); }
						else { rectangle[0][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][6] = 1;
					break;
					}
					case 8:
					{	if (sensor_klick[0][7] == 0) {
						arr[7][0].set_right(1);
						arr[7][1].set_left(1);
						++arr[7][0];
						++arr[7][1];
						if (queue == 1) { rectangle[0][7].setFillColor(Color::Blue); }
						else { rectangle[0][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][7] = 1;
					break;
					}
					case 9:
					{	if (sensor_klick[0][8] == 0) {
						arr[8][0].set_right(1);
						arr[8][1].set_left(1);
						++arr[8][0];
						++arr[8][1];
						if (queue == 1) { rectangle[0][8].setFillColor(Color::Blue); }
						else { rectangle[0][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][8] = 1;
					break;
					}
					case 10:
					{	if (sensor_klick[0][9] == 0) {
						arr[9][0].set_right(1);
						arr[9][1].set_left(1);
						++arr[9][0];
						++arr[9][1];
						if (queue == 1) { rectangle[0][9].setFillColor(Color::Blue); }
						else { rectangle[0][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[0][9] = 1;
					break;
					}
					case 11:
					{	if (sensor_klick[1][0] == 0) {
						arr[0][1].set_right(1);
						arr[0][2].set_left(1);
						++arr[0][1];
						++arr[0][2];
						if (queue == 1) { rectangle[1][0].setFillColor(Color::Blue); }
						else { rectangle[1][0].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][0] = 1;
					break;
					}
					case 12:
					{	if (sensor_klick[1][1] == 0) {
						arr[1][1].set_right(1);
						arr[1][2].set_left(1);
						++arr[1][1];
						++arr[1][2];
						if (queue == 1) { rectangle[1][1].setFillColor(Color::Blue); }
						else { rectangle[1][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][1] = 1;
					break;
					}
					case 13:
					{	if (sensor_klick[1][2] == 0) {
						arr[2][1].set_right(1);
						arr[2][2].set_left(1);
						++arr[2][1];
						++arr[2][2];
						if (queue == 1) { rectangle[1][2].setFillColor(Color::Blue); }
						else { rectangle[1][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][2] = 1;
					break;
					}
					case 14:
					{	if (sensor_klick[1][3] == 0) {
						arr[3][1].set_right(1);
						arr[3][2].set_left(1);
						++arr[3][1];
						++arr[3][2];
						if (queue == 1) { rectangle[1][3].setFillColor(Color::Blue); }
						else { rectangle[1][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][3] = 1;
					break;
					}
					case 15:
					{	if (sensor_klick[1][4] == 0) {
						arr[4][1].set_right(1);
						arr[4][2].set_left(1);
						++arr[4][1];
						++arr[4][2];
						if (queue == 1) { rectangle[1][4].setFillColor(Color::Blue); }
						else { rectangle[1][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][4] = 1;
					break;
					}
					case 16:
					{	if (sensor_klick[1][5] == 0) {
						arr[5][1].set_right(1);
						arr[5][2].set_left(1);
						++arr[5][1];
						++arr[5][2];
						if (queue == 1) { rectangle[1][5].setFillColor(Color::Blue); }
						else { rectangle[1][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][5] = 1;
					break;
					}
					case 17:
					{	if (sensor_klick[1][6] == 0) {
						arr[6][1].set_right(1);
						arr[6][2].set_left(1);
						++arr[6][1];
						++arr[6][2];
						if (queue == 1) { rectangle[1][6].setFillColor(Color::Blue); }
						else { rectangle[1][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][6] = 1;
					break;
					}
					case 18:
					{	if (sensor_klick[1][7] == 0) {
						arr[7][1].set_right(1);
						arr[7][2].set_left(1);
						++arr[7][1];
						++arr[7][2];
						if (queue == 1) { rectangle[1][7].setFillColor(Color::Blue); }
						else { rectangle[1][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][7] = 1;
					break;
					}
					case 19:
					{	if (sensor_klick[1][8] == 0) {
						arr[8][1].set_right(1);
						arr[8][2].set_left(1);
						++arr[8][1];
						++arr[8][2];
						if (queue == 1) { rectangle[1][8].setFillColor(Color::Blue); }
						else { rectangle[1][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][8] = 1;
					break;
					}
					case 20:
					{	if (sensor_klick[1][9] == 0) {
						arr[9][1].set_right(1);
						arr[9][2].set_left(1);
						++arr[9][1];
						++arr[9][2];
						if (queue == 1) { rectangle[1][9].setFillColor(Color::Blue); }
						else { rectangle[1][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[1][9] = 1;
					break;
					}
					case 21:
					{	if (sensor_klick[2][0] == 0) {
						arr[0][2].set_right(1);
						arr[0][3].set_left(1);
						++arr[0][2];
						++arr[0][3];
						if (queue == 1) { rectangle[2][0].setFillColor(Color::Blue); }
						else { rectangle[2][0].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][0] = 1;
					break;
					}
					case 22:
					{	if (sensor_klick[2][1] == 0) {
						arr[1][2].set_right(1);
						arr[1][3].set_left(1);
						++arr[1][2];
						++arr[1][3];
						if (queue == 1) { rectangle[2][1].setFillColor(Color::Blue); }
						else { rectangle[2][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][1] = 1;
					break;
					}
					case 23:
					{	if (sensor_klick[2][2] == 0) {
						arr[2][2].set_right(1);
						arr[2][3].set_left(1);
						++arr[2][2];
						++arr[2][3];
						if (queue == 1) { rectangle[2][2].setFillColor(Color::Blue); }
						else { rectangle[2][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][2] = 1;
					break;
					}
					case 24:
					{	if (sensor_klick[2][3] == 0) {
						arr[3][2].set_right(1);
						arr[3][3].set_left(1);
						++arr[3][2];
						++arr[3][3];
						if (queue == 1) { rectangle[2][3].setFillColor(Color::Blue); }
						else { rectangle[2][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][3] = 1;
					break;
					}
					case 25:
					{	if (sensor_klick[2][4] == 0) {
						arr[4][2].set_right(1);
						arr[4][3].set_left(1);
						++arr[4][2];
						++arr[4][3];
						if (queue == 1) { rectangle[2][4].setFillColor(Color::Blue); }
						else { rectangle[2][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][4] = 1;
					break;
					}
					case 26:
					{	if (sensor_klick[2][5] == 0) {
						arr[5][2].set_right(1);
						arr[5][3].set_left(1);
						++arr[5][2];
						++arr[5][3];
						if (queue == 1) { rectangle[2][5].setFillColor(Color::Blue); }
						else { rectangle[2][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][5] = 1;
					break;
					}
					case 27:
					{	if (sensor_klick[2][6] == 0) {
						arr[6][2].set_right(1);
						arr[6][3].set_left(1);
						++arr[6][2];
						++arr[6][3];
						if (queue == 1) { rectangle[2][6].setFillColor(Color::Blue); }
						else { rectangle[2][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][6] = 1;
					break;
					}
					case 28:
					{	if (sensor_klick[2][7] == 0) {
						arr[7][2].set_right(1);
						arr[7][3].set_left(1);
						++arr[7][2];
						++arr[7][3];
						if (queue == 1) { rectangle[2][7].setFillColor(Color::Blue); }
						else { rectangle[2][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][7] = 1;
					break;
					}
					case 29:
					{	if (sensor_klick[2][8] == 0) {
						arr[8][2].set_right(1);
						arr[8][3].set_left(1);
						++arr[8][2];
						++arr[8][3];
						if (queue == 1) { rectangle[2][8].setFillColor(Color::Blue); }
						else { rectangle[2][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][8] = 1;
					break;
					}
					case 30:
					{	if (sensor_klick[2][9] == 0) {
						arr[9][2].set_right(1);
						arr[9][3].set_left(1);
						++arr[9][2];
						++arr[9][3];
						if (queue == 1) { rectangle[2][9].setFillColor(Color::Blue); }
						else { rectangle[2][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[2][9] = 1;
					break;
					}
					case 31:
					{	if (sensor_klick[3][0] == 0) {
						arr[0][3].set_right(1);
						arr[0][4].set_left(1);
						++arr[0][3];
						++arr[0][4];
						if (queue == 1) { rectangle[3][0].setFillColor(Color::Blue); }
						else { rectangle[3][0].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][0] = 1;
					break;
					}
					case 32:
					{	if (sensor_klick[3][1] == 0) {
						arr[1][3].set_right(1);
						arr[1][4].set_left(1);
						++arr[1][3];
						++arr[1][4];
						if (queue == 1) { rectangle[3][1].setFillColor(Color::Blue); }
						else { rectangle[3][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][1] = 1;
					break;
					}	
					case 33:
					{	if (sensor_klick[3][2] == 0) {
						arr[2][3].set_right(1);
						arr[2][4].set_left(1);
						++arr[2][3];
						++arr[2][4];
						if (queue == 1) { rectangle[3][2].setFillColor(Color::Blue); }
						else { rectangle[3][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][2] = 1;
					break;
					}
					case 34:
					{	if (sensor_klick[3][3] == 0) {
						arr[3][3].set_right(1);
						arr[3][4].set_left(1);
						++arr[3][3];
						++arr[3][4];
						if (queue == 1) { rectangle[3][3].setFillColor(Color::Blue); }
						else { rectangle[3][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][3] = 1;
					break;
					}
					case 35:
					{	if (sensor_klick[3][4] == 0) {
						arr[4][3].set_right(1);
						arr[4][4].set_left(1);
						++arr[4][3];
						++arr[4][4];
						if (queue == 1) { rectangle[3][4].setFillColor(Color::Blue); }
						else { rectangle[3][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][4] = 1;
					break;
					}
					case 36:
					{	if (sensor_klick[3][5] == 0) {
						arr[5][3].set_right(1);
						arr[5][4].set_left(1);
						++arr[5][4];
						++arr[5][3];
						if (queue == 1) { rectangle[3][5].setFillColor(Color::Blue); }
						else { rectangle[3][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][5] = 1;
					break;
					}
					case 37:
					{	if (sensor_klick[3][6] == 0) {
						arr[6][3].set_right(1);
						arr[6][4].set_left(1);
						++arr[6][4];
						++arr[6][3];
						if (queue == 1) { rectangle[3][6].setFillColor(Color::Blue); }
						else { rectangle[3][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][6] = 1;
					break;
					}
					case 38:
					{	if (sensor_klick[3][7] == 0) {
						arr[7][3].set_right(1);
						arr[7][4].set_left(1);
						++arr[7][4];
						++arr[7][3];
						if (queue == 1) { rectangle[3][7].setFillColor(Color::Blue); }
						else { rectangle[3][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][7] = 1;
					break;
					}
					case 39:
					{	if (sensor_klick[3][8] == 0) {
						arr[8][3].set_right(1);
						arr[8][4].set_left(1);
						++arr[8][4];
						++arr[8][3];
						if (queue == 1) { rectangle[3][8].setFillColor(Color::Blue); }
						else { rectangle[3][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][8] = 1;
					break;
					}
					case 40:
					{	if (sensor_klick[3][9] == 0) {
						arr[9][3].set_right(1);
						arr[9][4].set_left(1);
						++arr[9][4];
						++arr[9][3];
						if (queue == 1) { rectangle[3][9].setFillColor(Color::Blue); }
						else { rectangle[3][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[3][9] = 1;
					break;
					}
					case 41:
					{	if (sensor_klick[4][0] == 0) {
						arr[0][4].set_right(1);
						arr[0][5].set_left(1);
						++arr[0][5];
						++arr[0][4];
						if (queue == 1) { rectangle[4][0].setFillColor(Color::Blue); }
						else { rectangle[4][0].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][0] = 1;
					break;
					}
					case 42:
					{	if (sensor_klick[4][1] == 0) {
						arr[1][4].set_right(1);
						arr[1][5].set_left(1);
						++arr[1][5];
						++arr[1][4];
						if (queue == 1) { rectangle[4][1].setFillColor(Color::Blue); }
						else { rectangle[4][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][1] = 1;
					break;
					}
					case 43:
					{	if (sensor_klick[4][2] == 0) {
						arr[2][4].set_right(1);
						arr[2][5].set_left(1);
						++arr[2][5];
						++arr[2][4];
						if (queue == 1) { rectangle[4][2].setFillColor(Color::Blue); }
						else { rectangle[4][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][2] = 1;
					break;
					}
					case 44:
					{	if (sensor_klick[4][3] == 0) {
						arr[3][4].set_right(1);
						arr[3][5].set_left(1);
						++arr[3][4];
						++arr[3][5];
						if (queue == 1) { rectangle[4][3].setFillColor(Color::Blue); }
						else { rectangle[4][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][3] = 1;
					break;
					}
					case 45:
					{	if (sensor_klick[4][4] == 0) {
						arr[4][4].set_right(1);
						arr[4][5].set_left(1);
						++arr[4][5];
						++arr[4][4];
						if (queue == 1) { rectangle[4][4].setFillColor(Color::Blue); }
						else { rectangle[4][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][4] = 1;
					break;
					}
					case 46:
					{	if (sensor_klick[4][5] == 0) {
						arr[5][4].set_right(1);
						arr[5][5].set_left(1);
						++arr[5][4];
						++arr[5][5];
						if (queue == 1) { rectangle[4][5].setFillColor(Color::Blue); }
						else { rectangle[4][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][5] = 1;
					break;
					}
					case 47:
					{	if (sensor_klick[4][6] == 0) {
						arr[6][4].set_right(1);
						arr[6][5].set_left(1);
						++arr[6][4];
						++arr[6][5];
						if (queue == 1) { rectangle[4][6].setFillColor(Color::Blue); }
						else { rectangle[4][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][6] = 1;
					break;
					}
					case 48:
					{	if (sensor_klick[4][7] == 0) {
						arr[7][4].set_right(1);
						arr[7][5].set_left(1);
						++arr[7][4];
						++arr[7][5];
						if (queue == 1) { rectangle[4][7].setFillColor(Color::Blue); }
						else { rectangle[4][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][7] = 1;
					break;
					}
					case 49:
					{	if (sensor_klick[4][8] == 0) {
						arr[8][4].set_right(1);
						arr[8][5].set_left(1);
						++arr[8][4];
						++arr[8][5];
						if (queue == 1) { rectangle[4][8].setFillColor(Color::Blue); }
						else { rectangle[4][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][8] = 1;
					break;
					}
					case 50:
					{	if (sensor_klick[4][9] == 0) {
						arr[9][4].set_right(1);
						arr[9][5].set_left(1);
						++arr[9][4];
						++arr[9][5];
						if (queue == 1) { rectangle[4][9].setFillColor(Color::Blue); }
						else { rectangle[4][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[4][9] = 1;
					break;
					}
					case 51:
					{	if (sensor_klick[5][0] == 0) {
						arr[0][5].set_right(1);
						arr[0][6].set_left(1);
						++arr[0][5];
						++arr[0][6];
						if (queue == 1) { rectangle[5][0].setFillColor(Color::Blue); }
						else { rectangle[5][0].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][0] = 1;
					break;
					}
					case 52:
					{	if (sensor_klick[5][1] == 0) {
						arr[1][5].set_right(1);
						arr[1][6].set_left(1);
						++arr[1][5];
						++arr[1][6];
						if (queue == 1) { rectangle[5][1].setFillColor(Color::Blue); }
						else { rectangle[5][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][1] = 1;
					break;
					}
					case 53:
					{	if (sensor_klick[5][2] == 0) {
						arr[2][5].set_right(1);
						arr[2][6].set_left(1);
						++arr[2][5];
						++arr[2][6];
						if (queue == 1) { rectangle[5][2].setFillColor(Color::Blue); }
						else { rectangle[5][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][2] = 1;
					break;
					}
					case 54:
					{	if (sensor_klick[5][3] == 0) {
						arr[3][5].set_right(1);
						arr[3][6].set_left(1);
						++arr[3][6];
						++arr[3][5];
						if (queue == 1) { rectangle[5][3].setFillColor(Color::Blue); }
						else { rectangle[5][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][3] = 1;
					break;
					}
					case 55:
					{	if (sensor_klick[5][4] == 0) {
						arr[4][5].set_right(1);
						arr[4][6].set_left(1);
						++arr[4][5];
						++arr[4][6];
						if (queue == 1) { rectangle[5][4].setFillColor(Color::Blue); }
						else { rectangle[5][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][4] = 1;
					break;
					}
					case 56:
					{	if (sensor_klick[5][5] == 0) {
						arr[5][5].set_right(1);
						arr[5][6].set_left(1);
						++arr[5][6];
						++arr[5][5];
						if (queue == 1) { rectangle[5][5].setFillColor(Color::Blue); }
						else { rectangle[5][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][5] = 1;
					break;
					}
					case 57:
					{	if (sensor_klick[5][6] == 0) {
						arr[6][5].set_right(1);
						arr[6][6].set_left(1);
						++arr[6][6];
						++arr[6][5];
						if (queue == 1) { rectangle[5][6].setFillColor(Color::Blue); }
						else { rectangle[5][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][6] = 1;
					break;
					}
					case 58:
					{	if (sensor_klick[5][7] == 0) {
						arr[7][5].set_right(1);
						arr[7][6].set_left(1);
						++arr[7][6];
						++arr[7][5];
						if (queue == 1) { rectangle[5][7].setFillColor(Color::Blue); }
						else { rectangle[5][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][7] = 1;
					break;
					}
					case 59:
					{	if (sensor_klick[5][8] == 0) {
						arr[8][5].set_right(1);
						arr[8][6].set_left(1);
						++arr[8][6];
						++arr[8][5];
						if (queue == 1) { rectangle[5][8].setFillColor(Color::Blue); }
						else { rectangle[5][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][8] = 1;
					break;
					}
					case 60:
					{	if (sensor_klick[5][9] == 0) {
						arr[9][5].set_right(1);
						arr[9][6].set_left(1);
						++arr[9][6];
						++arr[9][5];
						if (queue == 1) { rectangle[5][9].setFillColor(Color::Blue); }
						else { rectangle[5][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[5][9] = 1;
					break;
					}
					case 61:
					{	if (sensor_klick[6][0] == 0) {
						arr[0][6].set_right(1);
						arr[0][7].set_left(1);
						++arr[0][7];
						++arr[0][6];
						if (queue == 1) { rectangle[6][0].setFillColor(Color::Blue); }
						else { rectangle[6][0].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][0] = 1;
					break;
					}
					case 62:
					{	if (sensor_klick[6][1] == 0) {
						arr[1][6].set_right(1);
						arr[1][7].set_left(1);
						++arr[1][7];
						++arr[1][6];
						if (queue == 1) { rectangle[6][1].setFillColor(Color::Blue); }
						else { rectangle[6][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][1] = 1;
					break;
					}
					case 63:
					{	if (sensor_klick[6][2] == 0) {
						arr[2][6].set_right(1);
						arr[2][7].set_left(1);
						++arr[2][6];
						++arr[2][7];
						if (queue == 1) { rectangle[6][2].setFillColor(Color::Blue); }
						else { rectangle[6][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][2] = 1;
					break;
					}
					case 64:
					{	if (sensor_klick[6][3] == 0) {
						arr[3][6].set_right(1);
						arr[3][7].set_left(1);
						++arr[3][6];
						++arr[3][7];
						if (queue == 1) { rectangle[6][3].setFillColor(Color::Blue); }
						else { rectangle[6][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][3] = 1;
					break;
					}
					case 65:
					{	if (sensor_klick[6][4] == 0) {
						arr[4][6].set_right(1);
						arr[4][7].set_left(1);
						++arr[4][7];
						++arr[4][6];
						if (queue == 1) { rectangle[6][4].setFillColor(Color::Blue); }
						else { rectangle[6][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][4] = 1;
					break;
					}
					case 66:
					{	if (sensor_klick[6][5] == 0) {
						arr[5][6].set_right(1);
						arr[5][7].set_left(1);
						++arr[5][6];
						++arr[5][7];
						if (queue == 1) { rectangle[6][5].setFillColor(Color::Blue); }
						else { rectangle[6][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][5] = 1;
					break;
					}
					case 67:
					{	if (sensor_klick[6][6] == 0) {
						arr[6][6].set_right(1);
						arr[6][7].set_left(1);
						++arr[6][6];
						++arr[6][7];
						if (queue == 1) { rectangle[6][6].setFillColor(Color::Blue); }
						else { rectangle[6][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][6] = 1;
					break;
					}
					case 68:
					{	if (sensor_klick[6][7] == 0) {
						arr[7][6].set_right(1);
						arr[7][7].set_left(1);
						++arr[7][6];
						++arr[7][7];
						if (queue == 1) { rectangle[6][7].setFillColor(Color::Blue); }
						else { rectangle[6][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][7] = 1;
					break;
					}
					case 69:
					{	if (sensor_klick[6][8] == 0) {
						arr[8][6].set_right(1);
						arr[8][7].set_left(1);
						++arr[8][6];
						++arr[8][7];
						if (queue == 1) { rectangle[6][8].setFillColor(Color::Blue); }
						else { rectangle[6][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][8] = 1;
					break;
					}
					case 70:
					{	if (sensor_klick[6][9] == 0) {
						arr[9][6].set_right(1);
						arr[9][7].set_left(1);
						++arr[9][6];
						++arr[9][7];
						if (queue == 1) { rectangle[6][9].setFillColor(Color::Blue); }
						else { rectangle[6][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[6][9] = 1;
					break;
					}
					case 71:
					{	if (sensor_klick[7][0] == 0) {
						arr[0][7].set_right(1);
						arr[0][8].set_left(1);
						++arr[0][7];
						++arr[0][8];
						if (queue == 1) { rectangle[7][0].setFillColor(Color::Blue); }
						else { rectangle[7][0].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][0] = 1;
					break;
					}
					case 72:
					{	if (sensor_klick[7][1] == 0) {
						arr[1][7].set_right(1);
						arr[1][8].set_left(1);
						++arr[1][7];
						++arr[1][8];
						if (queue == 1) { rectangle[7][1].setFillColor(Color::Blue); }
						else { rectangle[7][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][1] = 1;
					break;
					}
					case 73:
					{	if (sensor_klick[7][2] == 0) {
						arr[2][7].set_right(1);
						arr[2][8].set_left(1);
						++arr[2][8];
						++arr[2][7];
						if (queue == 1) { rectangle[7][2].setFillColor(Color::Blue); }
						else { rectangle[7][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][2] = 1;
					break;
					}
					case 74:
					{	if (sensor_klick[7][3] == 0) {
						arr[3][7].set_right(1);
						arr[3][8].set_left(1);
						++arr[3][7];
						++arr[3][8];
						if (queue == 1) { rectangle[7][3].setFillColor(Color::Blue); }
						else { rectangle[7][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][3] = 1;
					break;
					}
					case 75:
					{	if (sensor_klick[7][4] == 0) {
						arr[4][7].set_right(1);
						arr[4][8].set_left(1);
						++arr[4][7];
						++arr[4][8];
						if (queue == 1) { rectangle[7][4].setFillColor(Color::Blue); }
						else { rectangle[7][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][4] = 1;
					break;
					}
					case 76:
					{	if (sensor_klick[7][5] == 0) {
						arr[5][7].set_right(1);
						arr[5][8].set_left(1);
						++arr[5][8];
						++arr[5][7];
						if (queue == 1) { rectangle[7][5].setFillColor(Color::Blue); }
						else { rectangle[7][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][5] = 1;
					break;
					}
					case 77:
					{	if (sensor_klick[7][6] == 0) {
						arr[6][7].set_right(1);
						arr[6][8].set_left(1);
						++arr[6][8];
						++arr[6][7];
						if (queue == 1) { rectangle[7][6].setFillColor(Color::Blue); }
						else { rectangle[7][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][6] = 1;
					break;
					}
					case 78:
					{	if (sensor_klick[7][7] == 0) {
						arr[7][7].set_right(1);
						arr[7][8].set_left(1);
						++arr[7][8];
						++arr[7][7];
						if (queue == 1) { rectangle[7][7].setFillColor(Color::Blue); }
						else { rectangle[7][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][7] = 1;
					break;
					}
					case 79:
					{	if (sensor_klick[7][8] == 0) {
						arr[8][7].set_right(1);
						arr[8][8].set_left(1);
						++arr[8][8];
						++arr[8][7];
						if (queue == 1) { rectangle[7][8].setFillColor(Color::Blue); }
						else { rectangle[7][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][8] = 1;
					break;
					}
					case 80:
					{	if (sensor_klick[7][9] == 0) {
						arr[9][7].set_right(1);
						arr[9][8].set_left(1);
						++arr[9][7];
						++arr[9][8];
						if (queue == 1) { rectangle[7][9].setFillColor(Color::Blue); }
						else { rectangle[7][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[7][9] = 1;
					break;
					}
					case 81:
					{	if (sensor_klick[8][0] == 0) {
						arr[0][8].set_right(1);
						arr[0][9].set_left(1);
						++arr[0][9];
						++arr[0][8];
						if (queue == 1) { rectangle[8][0].setFillColor(Color::Blue); }
						else { rectangle[8][0].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][0] = 1;
					break;
					}
					case 82:
					{	if (sensor_klick[8][1] == 0) {
						arr[1][8].set_right(1);
						arr[1][9].set_left(1);
						++arr[1][9];
						++arr[1][8];
						if (queue == 1) { rectangle[8][1].setFillColor(Color::Blue); }
						else { rectangle[8][1].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][1] = 1;
					break;
					}
					case 83:
					{	if (sensor_klick[8][2] == 0) {
						arr[2][8].set_right(1);
						arr[2][9].set_left(1);
						++arr[2][8];
						++arr[2][9];
						if (queue == 1) { rectangle[8][2].setFillColor(Color::Blue); }
						else { rectangle[8][2].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][2] = 1;
					break;
					}
					case 84:
					{	if (sensor_klick[8][3] == 0) {
						arr[3][8].set_right(1);
						arr[3][9].set_left(1);
						++arr[3][9];
						++arr[3][8];
						if (queue == 1) { rectangle[8][3].setFillColor(Color::Blue); }
						else { rectangle[8][3].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][3] = 1;
					break;
					}
					case 85:
					{	if (sensor_klick[8][4] == 0) {
						arr[4][8].set_right(1);
						arr[4][9].set_left(1);
						++arr[4][9];
						++arr[4][8];
						if (queue == 1) { rectangle[8][4].setFillColor(Color::Blue); }
						else { rectangle[8][4].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][4] = 1;
					break;
					}
					case 86:
					{	if (sensor_klick[8][5] == 0) {
						arr[5][8].set_right(1);
						arr[5][9].set_left(1);
						++arr[5][8];
						++arr[5][9];
						if (queue == 1) { rectangle[8][5].setFillColor(Color::Blue); }
						else { rectangle[8][5].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][5] = 1;
					break;
					}
					case 87:
					{	if (sensor_klick[8][6] == 0) {
						arr[6][8].set_right(1);
						arr[6][9].set_left(1);
						++arr[6][8];
						++arr[6][9];
						if (queue == 1) { rectangle[8][6].setFillColor(Color::Blue); }
						else { rectangle[8][6].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][6] = 1;
					break;
					}
					case 88:
					{	if (sensor_klick[8][7] == 0) {
						arr[7][8].set_right(1);
						arr[7][9].set_left(1);
						++arr[7][8];
						++arr[7][9];
						if (queue == 1) { rectangle[8][7].setFillColor(Color::Blue); }
						else { rectangle[8][7].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][7] = 1;
					break;
					}
					case 89:
					{	if (sensor_klick[8][8] == 0) {
						arr[8][8].set_right(1);
						arr[8][9].set_left(1);
						++arr[8][8];
						++arr[8][9];
						if (queue == 1) { rectangle[8][8].setFillColor(Color::Blue); }
						else { rectangle[8][8].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][8] = 1;
					break;
					}
					case 90:
					{	if (sensor_klick[8][9] == 0) {
						arr[9][8].set_right(1);
						arr[9][9].set_left(1);
						++arr[9][9];
						++arr[9][8];
						if (queue == 1) { rectangle[8][9].setFillColor(Color::Blue); }
						else { rectangle[8][9].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[8][9] = 1;
					break;
					}
					// horizontal
					case 91:
					{	if (sensor_klick[9][10] == 0) {
						arr[0][0].set_bottom(1);
						arr[1][0].set_top(1);
						++arr[0][0];
						++arr[1][0];
						if (queue == 1) { rectangle[9][10].setFillColor(Color::Blue); }
						else { rectangle[9][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][10] = 1;
					break;
					}
					case 92:
					{	if (sensor_klick[9][11] == 0) {
						arr[0][1].set_bottom(1);
						arr[1][1].set_top(1);
						++arr[0][1];
						++arr[1][1];
						if (queue == 1) { rectangle[9][11].setFillColor(Color::Blue); }
						else { rectangle[9][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][11] = 1;
					break;
					}
					case 93:
					{	if (sensor_klick[9][12] == 0) {
						arr[0][2].set_bottom(1);
						arr[1][2].set_top(1);
						++arr[0][2];
						++arr[1][2];
						if (queue == 1) { rectangle[9][12].setFillColor(Color::Blue); }
						else { rectangle[9][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][12] = 1;
					break;
					}
					case 94:
					{	if (sensor_klick[9][13] == 0) {
						arr[0][3].set_bottom(1);
						arr[1][3].set_top(1);
						++arr[0][3];
						++arr[1][3];
						if (queue == 1) { rectangle[9][13].setFillColor(Color::Blue); }
						else { rectangle[9][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][13] = 1;
					break;
					}
					case 95:
					{	if (sensor_klick[9][14] == 0) {
						arr[0][4].set_bottom(1);
						arr[1][4].set_top(1);
						++arr[0][4];
						++arr[1][4];
						if (queue == 1) { rectangle[9][14].setFillColor(Color::Blue); }
						else { rectangle[9][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][14] = 1;
					break;
					}
					case 96:
					{	if (sensor_klick[9][15] == 0) {
						arr[0][5].set_bottom(1);
						arr[1][5].set_top(1);
						++arr[0][5];
						++arr[1][5];
						if (queue == 1) { rectangle[9][15].setFillColor(Color::Blue); }
						else { rectangle[9][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][15] = 1;
					break;
					}
					case 97:
					{	if (sensor_klick[9][16] == 0) {
						arr[0][6].set_bottom(1);
						arr[1][6].set_top(1);
						++arr[0][6];
						++arr[1][6];
						if (queue == 1) { rectangle[9][16].setFillColor(Color::Blue); }
						else { rectangle[9][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][16] = 1;
					break;
					}
					case 98:
					{	if (sensor_klick[9][17] == 0) {
						arr[0][7].set_bottom(1);
						arr[1][7].set_top(1);
						++arr[0][7];
						++arr[1][7];
						if (queue == 1) { rectangle[9][17].setFillColor(Color::Blue); }
						else { rectangle[9][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][17] = 1;
					break;
					}
					case 99:
					{	if (sensor_klick[9][18] == 0) {
						arr[0][8].set_bottom(1);
						arr[1][8].set_top(1);
						++arr[0][8];
						++arr[1][8];
						if (queue == 1) { rectangle[9][18].setFillColor(Color::Blue); }
						else { rectangle[9][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][18] = 1;
					break;
					}
					case 100:
					{	if (sensor_klick[9][19] == 0) {
						arr[0][9].set_bottom(1);
						arr[1][9].set_top(1);
						++arr[0][9];
						++arr[1][9];
						if (queue == 1) { rectangle[9][19].setFillColor(Color::Blue); }
						else { rectangle[9][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[9][19] = 1;
					break;
					}
					case 101:
					{	if (sensor_klick[10][10] == 0) {
						arr[1][0].set_bottom(1);
						arr[2][0].set_top(1);
						++arr[1][0];
						++arr[2][0];
						if (queue == 1) { rectangle[10][10].setFillColor(Color::Blue); }
						else { rectangle[10][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][10] = 1;
					break;
					}
					case 102:
					{	if (sensor_klick[10][11] == 0) {
						arr[1][1].set_bottom(1);
						arr[2][1].set_top(1);
						++arr[2][1];
						++arr[1][1];
						if (queue == 1) { rectangle[10][11].setFillColor(Color::Blue); }
						else { rectangle[10][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][11] = 1;
					break;
					}
					case 103:
					{	if (sensor_klick[10][12] == 0) {
						arr[1][2].set_bottom(1);
						arr[2][2].set_top(1);
						++arr[1][2];
						++arr[2][2];
						if (queue == 1) { rectangle[10][12].setFillColor(Color::Blue); }
						else { rectangle[10][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][12] = 1;
					break;
					}
					case 104:
					{	if (sensor_klick[10][13] == 0) {
						arr[1][3].set_bottom(1);
						arr[2][3].set_top(1);
						++arr[1][3];
						++arr[2][3];
						if (queue == 1) { rectangle[10][13].setFillColor(Color::Blue); }
						else { rectangle[10][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][13] = 1;
					break;
					}
					case 105:
					{	if (sensor_klick[10][14] == 0) {
						arr[1][4].set_bottom(1);
						arr[2][4].set_top(1);
						++arr[1][4];
						++arr[2][4];
						if (queue == 1) { rectangle[10][14].setFillColor(Color::Blue); }
						else { rectangle[10][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][14] = 1;
					break;
					}
					case 106:
					{	if (sensor_klick[10][15] == 0) {
						arr[1][5].set_bottom(1);
						arr[2][5].set_top(1);
						++arr[1][5];
						++arr[2][5];
						if (queue == 1) { rectangle[10][15].setFillColor(Color::Blue); }
						else { rectangle[10][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][15] = 1;
					break;
					}
					case 107:
					{	if (sensor_klick[10][16] == 0) {
						arr[1][6].set_bottom(1);
						arr[2][6].set_top(1);
						++arr[2][6];
						++arr[1][6];
						if (queue == 1) { rectangle[10][16].setFillColor(Color::Blue); }
						else { rectangle[10][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][16] = 1;
					break;
					}
					case 108:
					{	if (sensor_klick[10][17] == 0) {
						arr[1][7].set_bottom(1);
						arr[2][7].set_top(1);
						++arr[2][7];
						++arr[1][7];
						if (queue == 1) { rectangle[10][17].setFillColor(Color::Blue); }
						else { rectangle[10][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][17] = 1;
					break;
					}
					case 109:
					{	if (sensor_klick[10][18] == 0) {
						arr[1][8].set_bottom(1);
						arr[2][8].set_top(1);
						++arr[1][8];
						++arr[2][8];
						if (queue == 1) { rectangle[10][18].setFillColor(Color::Blue); }
						else { rectangle[10][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][18] = 1;
					break;
					}
					case 110:
					{	if (sensor_klick[10][19] == 0) {
						arr[1][9].set_bottom(1);
						arr[2][9].set_top(1);
						++arr[1][9];
						++arr[2][9];
						if (queue == 1) { rectangle[10][19].setFillColor(Color::Blue); }
						else { rectangle[10][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[10][19] = 1;
					break;
					}
					case 111:
					{	if (sensor_klick[11][10] == 0) {
						arr[2][0].set_bottom(1);
						arr[3][0].set_top(1);
						++arr[3][0];
						++arr[2][0];
						if (queue == 1) { rectangle[11][10].setFillColor(Color::Blue); }
						else { rectangle[11][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][10] = 1;
					break;
					}
					case 112:
					{	if (sensor_klick[11][11] == 0) {
						arr[2][1].set_bottom(1);
						arr[3][1].set_top(1);
						++arr[2][1];
						++arr[3][1];
						if (queue == 1) { rectangle[11][11].setFillColor(Color::Blue); }
						else { rectangle[11][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][11] = 1;
					break;
					}
					case 113:
					{	if (sensor_klick[11][12] == 0) {
						arr[2][2].set_bottom(1);
						arr[3][2].set_top(1);
						++arr[3][2];
						++arr[2][2];
						if (queue == 1) { rectangle[11][12].setFillColor(Color::Blue); }
						else { rectangle[11][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][12] = 1;
					break;
					}
					case 114:
					{	if (sensor_klick[11][13] == 0) {
						arr[2][3].set_bottom(1);
						arr[3][3].set_top(1);
						++arr[3][3];
						++arr[2][3];
						if (queue == 1) { rectangle[11][13].setFillColor(Color::Blue); }
						else { rectangle[11][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][13] = 1;
					break;
					}
					case 115:
					{	if (sensor_klick[11][14] == 0) {
						arr[2][4].set_bottom(1);
						arr[3][4].set_top(1);
						++arr[2][4];
						++arr[3][4];
						if (queue == 1) { rectangle[11][14].setFillColor(Color::Blue); }
						else { rectangle[11][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][14] = 1;
					break;
					}
					case 116:
					{	if (sensor_klick[11][15] == 0) {
						arr[2][5].set_bottom(1);
						arr[3][5].set_top(1);
						++arr[3][5];
						++arr[2][5];
						if (queue == 1) { rectangle[11][15].setFillColor(Color::Blue); }
						else { rectangle[11][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][15] = 1;
					break;
					}
					case 117:
					{	if (sensor_klick[11][16] == 0) {
						arr[2][6].set_bottom(1);
						arr[3][6].set_top(1);
						++arr[3][6];
						++arr[2][6];
						if (queue == 1) { rectangle[11][16].setFillColor(Color::Blue); }
						else { rectangle[11][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][16] = 1;
					break;
					}
					case 118:
					{	if (sensor_klick[11][17] == 0) {
						arr[2][7].set_bottom(1);
						arr[3][7].set_top(1);
						++arr[3][7];
						++arr[2][7];
						if (queue == 1) { rectangle[11][17].setFillColor(Color::Blue); }
						else { rectangle[11][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][17] = 1;
					break;
					}
					case 119:
					{	if (sensor_klick[11][18] == 0) {
						arr[2][8].set_bottom(1);
						arr[3][8].set_top(1);
						++arr[2][8];
						++arr[3][8];
						if (queue == 1) { rectangle[11][18].setFillColor(Color::Blue); }
						else { rectangle[11][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][18] = 1;
					break;
					}
					case 120:
					{	if (sensor_klick[11][19] == 0) {
						arr[2][9].set_bottom(1);
						arr[3][9].set_top(1);
						++arr[3][9];
						++arr[2][9];
						if (queue == 1) { rectangle[11][19].setFillColor(Color::Blue); }
						else { rectangle[11][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[11][19] = 1;
					break;
					}
					case 121:
					{	if (sensor_klick[12][10] == 0) {
						arr[3][0].set_bottom(1);
						arr[4][0].set_top(1);
						++arr[3][0];
						++arr[4][0];
						if (queue == 1) { rectangle[12][10].setFillColor(Color::Blue); }
						else { rectangle[12][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][10] = 1;
					break;
					}
					case 122:
					{	if (sensor_klick[12][11] == 0) {
						arr[3][1].set_bottom(1);
						arr[4][1].set_top(1);
						++arr[3][1];
						++arr[4][1];
						if (queue == 1) { rectangle[12][11].setFillColor(Color::Blue); }
						else { rectangle[12][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][11] = 1;
					break;
					}
					case 123:
					{	if (sensor_klick[12][12] == 0) {
						arr[3][2].set_bottom(1);
						arr[4][2].set_top(1);
						++arr[4][2];
						++arr[3][2];
						if (queue == 1) { rectangle[12][12].setFillColor(Color::Blue); }
						else { rectangle[12][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][12] = 1;
					break;
					}
					case 124:
					{	if (sensor_klick[12][13] == 0) {
						arr[3][3].set_bottom(1);
						arr[4][3].set_top(1);
						++arr[3][3];
						++arr[4][3];
						if (queue == 1) { rectangle[12][13].setFillColor(Color::Blue); }
						else { rectangle[12][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][13] = 1;
					break;
					}
					case 125:
					{	if (sensor_klick[12][14] == 0) {
						arr[3][4].set_bottom(1);
						arr[4][4].set_top(1);
						++arr[3][4];
						++arr[4][4];
						if (queue == 1) { rectangle[12][14].setFillColor(Color::Blue); }
						else { rectangle[12][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][14] = 1;
					break;
					}
					case 126:
					{	if (sensor_klick[12][15] == 0) {
						arr[3][5].set_bottom(1);
						arr[4][5].set_top(1);
						++arr[3][5];
						++arr[4][5];
						if (queue == 1) { rectangle[12][15].setFillColor(Color::Blue); }
						else { rectangle[12][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][15] = 1;
					break;
					}
					case 127:
					{	if (sensor_klick[12][16] == 0) {
						arr[3][6].set_bottom(1);
						arr[4][6].set_top(1);
						++arr[3][6];
						++arr[4][6];
						if (queue == 1) { rectangle[12][16].setFillColor(Color::Blue); }
						else { rectangle[12][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][16] = 1;
					break;
					}
					case 128:
					{	if (sensor_klick[12][17] == 0) {
						arr[3][7].set_bottom(1);
						arr[4][7].set_top(1);
						++arr[3][7];
						++arr[4][7];
						if (queue == 1) { rectangle[12][17].setFillColor(Color::Blue); }
						else { rectangle[12][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][17] = 1;
					break;
					}
					case 129:
					{	if (sensor_klick[12][18] == 0) {
						arr[3][8].set_bottom(1);
						arr[4][8].set_top(1);
						++arr[4][8];
						++arr[3][8];
						if (queue == 1) { rectangle[12][18].setFillColor(Color::Blue); }
						else { rectangle[12][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][18] = 1;
					break;
					}
					case 130:
					{	if (sensor_klick[12][19] == 0) {
						arr[3][9].set_bottom(1);
						arr[4][9].set_top(1);
						++arr[3][9];
						++arr[4][9];
						if (queue == 1) { rectangle[12][19].setFillColor(Color::Blue); }
						else { rectangle[12][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[12][19] = 1;
					break;
					}
					case 131:
					{	if (sensor_klick[13][10] == 0) {
						arr[4][0].set_bottom(1);
						arr[5][0].set_top(1);
						++arr[4][0];
						++arr[5][0];
						if (queue == 1) { rectangle[13][10].setFillColor(Color::Blue); }
						else { rectangle[13][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][10] = 1;
					break;
					}
					case 132:
					{	if (sensor_klick[13][11] == 0) {
						arr[4][1].set_bottom(1);
						arr[5][1].set_top(1);
						++arr[5][1];
						++arr[4][1];
						if (queue == 1) { rectangle[13][11].setFillColor(Color::Blue); }
						else { rectangle[13][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][11] = 1;
					break;
					}
					case 133:
					{	if (sensor_klick[13][12] == 0) {
						arr[4][2].set_bottom(1);
						arr[5][2].set_top(1);
						++arr[4][2];
						++arr[5][2];
						if (queue == 1) { rectangle[13][12].setFillColor(Color::Blue); }
						else { rectangle[13][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][12] = 1;
					break;
					}
					case 134:
					{	if (sensor_klick[13][13] == 0) {
						arr[4][3].set_bottom(1);
						arr[5][3].set_top(1);
						++arr[4][3];
						++arr[5][3];
						if (queue == 1) { rectangle[13][13].setFillColor(Color::Blue); }
						else { rectangle[13][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][13] = 1;
					break;
					}
					case 135:
					{	if (sensor_klick[13][14] == 0) {
						arr[4][4].set_bottom(1);
						arr[5][4].set_top(1);
						++arr[5][4];
						++arr[4][4];
						if (queue == 1) { rectangle[13][14].setFillColor(Color::Blue); }
						else { rectangle[13][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][14] = 1;
					break;
					}
					case 136:
					{	if (sensor_klick[13][15] == 0) {
						arr[4][5].set_bottom(1);
						arr[5][5].set_top(1);
						++arr[5][5];
						++arr[4][5];
						if (queue == 1) { rectangle[13][15].setFillColor(Color::Blue); }
						else { rectangle[13][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][15] = 1;
					break;
					}
					case 137:
					{	if (sensor_klick[13][16] == 0) {
						arr[4][6].set_bottom(1);
						arr[5][6].set_top(1);
						++arr[4][6];
						++arr[5][6];
						if (queue == 1) { rectangle[13][16].setFillColor(Color::Blue); }
						else { rectangle[13][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][16] = 1;
					break;
					}
					case 138:
					{	if (sensor_klick[13][17] == 0) {
						arr[4][7].set_bottom(1);
						arr[5][7].set_top(1);
						++arr[5][7];
						++arr[4][7];
						if (queue == 1) { rectangle[13][17].setFillColor(Color::Blue); }
						else { rectangle[13][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][17] = 1;
					break;
					}
					case 139:
					{	if (sensor_klick[13][18] == 0) {
						arr[4][8].set_bottom(1);
						arr[5][8].set_top(1);
						++arr[4][8];
						++arr[5][8];
						if (queue == 1) { rectangle[13][18].setFillColor(Color::Blue); }
						else { rectangle[13][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][18] = 1;
					break;
					}
					case 140:
					{	if (sensor_klick[13][19] == 0) {
						arr[4][9].set_bottom(1);
						arr[5][9].set_top(1);
						++arr[5][9];
						++arr[4][9];
						if (queue == 1) { rectangle[13][19].setFillColor(Color::Blue); }
						else { rectangle[13][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[13][19] = 1;
					break;
					}
					case 141:
					{	if (sensor_klick[14][10] == 0) {
						arr[5][0].set_bottom(1);
						arr[6][0].set_top(1);
						++arr[6][0];
						++arr[5][0];
						if (queue == 1) { rectangle[14][10].setFillColor(Color::Blue); }
						else { rectangle[14][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][10] = 1;
					break;
					}
					case 142:
					{	if (sensor_klick[14][11] == 0) {
						arr[5][1].set_bottom(1);
						arr[6][1].set_top(1);
						++arr[5][1];
						++arr[6][1];
						if (queue == 1) { rectangle[14][11].setFillColor(Color::Blue); }
						else { rectangle[14][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][11] = 1;
					break;
					}
					case 143:
					{	if (sensor_klick[14][12] == 0) {
						arr[5][2].set_bottom(1);
						arr[6][2].set_top(1);
						++arr[5][2];
						++arr[6][2];
						if (queue == 1) { rectangle[14][12].setFillColor(Color::Blue); }
						else { rectangle[14][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][12] = 1;
					break;
					}
					case 144:
					{	if (sensor_klick[14][13] == 0) {
						arr[5][3].set_bottom(1);
						arr[6][3].set_top(1);
						++arr[6][3];
						++arr[5][3];
						if (queue == 1) { rectangle[14][13].setFillColor(Color::Blue); }
						else { rectangle[14][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][13] = 1;
					break;
					}
					case 145:
					{	if (sensor_klick[14][14] == 0) {
						arr[5][4].set_bottom(1);
						arr[6][4].set_top(1);
						++arr[5][4];
						++arr[6][4];
						if (queue == 1) { rectangle[14][14].setFillColor(Color::Blue); }
						else { rectangle[14][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][14] = 1;
					break;
					}
					case 146:
					{	if (sensor_klick[14][15] == 0) {
						arr[5][5].set_bottom(1);
						arr[6][5].set_top(1);
						++arr[5][5];
						++arr[6][5];
						if (queue == 1) { rectangle[14][15].setFillColor(Color::Blue); }
						else { rectangle[14][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][15] = 1;
					break;
					}
					case 147:
					{	if (sensor_klick[14][16] == 0) {
						arr[5][6].set_bottom(1);
						arr[6][6].set_top(1);
						++arr[5][6];
						++arr[6][6];
						if (queue == 1) { rectangle[14][16].setFillColor(Color::Blue); }
						else { rectangle[14][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][16] = 1;
					break;
					}
					case 148:
					{	if (sensor_klick[14][17] == 0) {
						arr[5][7].set_bottom(1);
						arr[6][7].set_top(1);
						++arr[5][7];
						++arr[6][7];
						if (queue == 1) { rectangle[14][17].setFillColor(Color::Blue); }
						else { rectangle[14][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][17] = 1;
					break;
					}
					case 149:
					{	if (sensor_klick[14][18] == 0) {
						arr[5][8].set_bottom(1);
						arr[6][8].set_top(1);
						++arr[5][8];
						++arr[6][8];
						if (queue == 1) { rectangle[14][18].setFillColor(Color::Blue); }
						else { rectangle[14][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][18] = 1;
					break;
					}
					case 150:
					{	if (sensor_klick[14][19] == 0) {
						arr[5][9].set_bottom(1);
						arr[6][9].set_top(1);
						++arr[5][9];
						++arr[6][9];
						if (queue == 1) { rectangle[14][19].setFillColor(Color::Blue); }
						else { rectangle[14][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[14][19] = 1;
					break;
					}
					case 151:
					{	if (sensor_klick[15][10] == 0) {
						arr[6][0].set_bottom(1);
						arr[7][0].set_top(1);
						++arr[6][0];
						++arr[7][0];
						if (queue == 1) { rectangle[15][10].setFillColor(Color::Blue); }
						else { rectangle[15][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][10] = 1;
					break;
					}
					case 152:
					{	if (sensor_klick[15][11] == 0) {
						arr[6][1].set_bottom(1);
						arr[7][1].set_top(1);
						++arr[7][1];
						++arr[6][1];
						if (queue == 1) { rectangle[15][11].setFillColor(Color::Blue); }
						else { rectangle[15][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][11] = 1;
					break;
					}
					case 153:
					{	if (sensor_klick[15][12] == 0) {
						arr[6][2].set_bottom(1);
						arr[7][2].set_top(1);
						++arr[7][2];
						++arr[6][2];
						if (queue == 1) { rectangle[15][12].setFillColor(Color::Blue); }
						else { rectangle[15][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][12] = 1;
					break;
					}
					case 154:
					{	if (sensor_klick[15][13] == 0) {
						arr[6][3].set_bottom(1);
						arr[7][3].set_top(1);
						++arr[6][3];
						++arr[7][3];
						if (queue == 1) { rectangle[15][13].setFillColor(Color::Blue); }
						else { rectangle[15][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][13] = 1;
					break;
					}
					case 155:
					{	if (sensor_klick[15][14] == 0) {
						arr[6][4].set_bottom(1);
						arr[7][4].set_top(1);
						++arr[7][4];
						++arr[6][4];
						if (queue == 1) { rectangle[15][14].setFillColor(Color::Blue); }
						else { rectangle[15][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][14] = 1;
					break;
					}
					case 156:
					{	if (sensor_klick[15][15] == 0) {
						arr[6][5].set_bottom(1);
						arr[7][5].set_top(1);
						++arr[7][5];
						++arr[6][5];
						if (queue == 1) { rectangle[15][15].setFillColor(Color::Blue); }
						else { rectangle[15][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][15] = 1;
					break;
					}
					case 157:
					{	if (sensor_klick[15][16] == 0) {
						arr[6][6].set_bottom(1);
						arr[7][6].set_top(1);
						++arr[7][6];
						++arr[6][6];
						if (queue == 1) { rectangle[15][16].setFillColor(Color::Blue); }
						else { rectangle[15][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][16] = 1;
					break;
					}
					case 158:
					{	if (sensor_klick[15][17] == 0) {
						arr[6][7].set_bottom(1);
						arr[7][7].set_top(1);
						++arr[7][7];
						++arr[6][7];
						if (queue == 1) { rectangle[15][17].setFillColor(Color::Blue); }
						else { rectangle[15][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][17] = 1;
					break;
					}
					case 159:
					{	if (sensor_klick[15][18] == 0) {
						arr[6][8].set_bottom(1);
						arr[7][8].set_top(1);
						++arr[7][8];
						++arr[6][8];
						if (queue == 1) { rectangle[15][18].setFillColor(Color::Blue); }
						else { rectangle[15][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][18] = 1;
					break;
					}
					case 160:
					{	if (sensor_klick[15][19] == 0) {
						arr[6][9].set_bottom(1);
						arr[7][9].set_top(1);
						++arr[7][9];
						++arr[6][9];
						if (queue == 1) { rectangle[15][19].setFillColor(Color::Blue); }
						else { rectangle[15][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[15][19] = 1;
					break;
					}
					case 161:
					{	if (sensor_klick[16][10] == 0) {
						arr[7][0].set_bottom(1);
						arr[8][0].set_top(1);
						++arr[7][0];
						++arr[8][0];
						if (queue == 1) { rectangle[16][10].setFillColor(Color::Blue); }
						else { rectangle[16][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][10] = 1;
					break;
					}
					case 162:
					{	if (sensor_klick[16][11] == 0) {
						arr[7][1].set_bottom(1);
						arr[8][1].set_top(1);
						++arr[7][1];
						++arr[8][1];
						if (queue == 1) { rectangle[16][11].setFillColor(Color::Blue); }
						else { rectangle[16][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][11] = 1;
					break;
					}
					case 163:
					{	if (sensor_klick[16][12] == 0) {
						arr[7][2].set_bottom(1);
						arr[8][2].set_top(1);
						++arr[7][2];
						++arr[8][2];
						if (queue == 1) { rectangle[16][12].setFillColor(Color::Blue); }
						else { rectangle[16][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][12] = 1;
					break;
					}
					case 164:
					{	if (sensor_klick[16][13] == 0) {
						arr[7][3].set_bottom(1);
						arr[8][3].set_top(1);
						++arr[8][3];
						++arr[7][3];
						if (queue == 1) { rectangle[16][13].setFillColor(Color::Blue); }
						else { rectangle[16][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][13] = 1;
					break;
					}
					case 165:
					{	if (sensor_klick[16][14] == 0) {
						arr[7][4].set_bottom(1);
						arr[8][4].set_top(1);
						++arr[7][4];
						++arr[8][4];
						if (queue == 1) { rectangle[16][14].setFillColor(Color::Blue); }
						else { rectangle[16][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][14] = 1;
					break;
					}
					case 166:
					{	if (sensor_klick[16][15] == 0) {
						arr[7][5].set_bottom(1);
						arr[8][5].set_top(1);
						++arr[7][5];
						++arr[8][5];
						if (queue == 1) { rectangle[16][15].setFillColor(Color::Blue); }
						else { rectangle[16][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][15] = 1;
					break;
					}
					case 167:
					{	if (sensor_klick[16][16] == 0) {
						arr[7][6].set_bottom(1);
						arr[8][6].set_top(1);
						++arr[7][6];
						++arr[8][6];
						if (queue == 1) { rectangle[16][16].setFillColor(Color::Blue); }
						else { rectangle[16][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][16] = 1;
					break;
					}
					case 168:
					{	if (sensor_klick[16][17] == 0) {
						arr[7][7].set_bottom(1);
						arr[8][7].set_top(1);
						++arr[7][7];
						++arr[8][7];
						if (queue == 1) { rectangle[16][17].setFillColor(Color::Blue); }
						else { rectangle[16][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][17] = 1;
					break;
					}
					case 169:
					{	if (sensor_klick[16][18] == 0) {
						arr[7][8].set_bottom(1);
						arr[8][8].set_top(1);
						++arr[7][8];
						++arr[8][8];
						if (queue == 1) { rectangle[16][18].setFillColor(Color::Blue); }
						else { rectangle[16][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][18] = 1;
					break;
					}
					case 170:
					{	if (sensor_klick[16][19] == 0) {
						arr[7][9].set_bottom(1);
						arr[8][9].set_top(1);
						++arr[7][9];
						++arr[8][9];
						if (queue == 1) { rectangle[16][19].setFillColor(Color::Blue); }
						else { rectangle[16][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[16][19] = 1;
					break;
					}
					case 171:
					{	if (sensor_klick[17][10] == 0) {
						arr[8][0].set_bottom(1);
						arr[9][0].set_top(1);
						++arr[8][0];
						++arr[9][0];
						if (queue == 1) { rectangle[17][10].setFillColor(Color::Blue); }
						else { rectangle[17][10].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][10] = 1;
					break;
					}
					case 172:
					{	if (sensor_klick[17][11] == 0) {
						arr[8][1].set_bottom(1);
						arr[9][1].set_top(1);
						++arr[9][1];
						++arr[8][1];
						if (queue == 1) { rectangle[17][11].setFillColor(Color::Blue); }
						else { rectangle[17][11].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][11] = 1;
					break;
					}
					case 173:
					{	if (sensor_klick[17][12] == 0) {
						arr[8][2].set_bottom(1);
						arr[9][2].set_top(1);
						++arr[8][2];
						++arr[9][2];
						if (queue == 1) { rectangle[17][12].setFillColor(Color::Blue); }
						else { rectangle[17][12].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][12] = 1;
					break;
					}
					case 174:
					{	if (sensor_klick[17][13] == 0) {
						arr[8][3].set_bottom(1);
						arr[9][3].set_top(1);
						++arr[8][3];
						++arr[9][3];
						if (queue == 1) { rectangle[17][13].setFillColor(Color::Blue); }
						else { rectangle[17][13].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][13] = 1;
					break;
					}
					case 175:
					{	if (sensor_klick[17][14] == 0) {
						arr[8][4].set_bottom(1);
						arr[9][4].set_top(1);
						++arr[9][4];
						++arr[8][4];
						if (queue == 1) { rectangle[17][14].setFillColor(Color::Blue); }
						else { rectangle[17][14].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][14] = 1;
					break;
					}
					case 176:
					{	if (sensor_klick[17][15] == 0) {
						arr[8][5].set_bottom(1);
						arr[9][5].set_top(1);
						++arr[9][5];
						++arr[8][5];
						if (queue == 1) { rectangle[17][15].setFillColor(Color::Blue); }
						else { rectangle[17][15].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][15] = 1;
					break;
					}
					case 177:
					{	if (sensor_klick[17][16] == 0) {
						arr[8][6].set_bottom(1);
						arr[9][6].set_top(1);
						++arr[9][6];
						++arr[8][6];
						if (queue == 1) { rectangle[17][16].setFillColor(Color::Blue); }
						else { rectangle[17][16].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][16] = 1;
					break;
					}
					case 178:
					{	if (sensor_klick[17][17] == 0) {
						arr[8][7].set_bottom(1);
						arr[9][7].set_top(1);
						++arr[9][7];
						++arr[8][7];
						if (queue == 1) { rectangle[17][17].setFillColor(Color::Blue); }
						else { rectangle[17][17].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][17] = 1;
					break;
					}
					case 179:
					{	if (sensor_klick[17][18] == 0) {
						arr[8][8].set_bottom(1);
						arr[9][8].set_top(1);
						++arr[9][8];
						++arr[8][8];
						if (queue == 1) { rectangle[17][18].setFillColor(Color::Blue); }
						else { rectangle[17][18].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][18] = 1;
					break;
					}
					case 180:
					{	if (sensor_klick[17][19] == 0) {
						arr[8][9].set_bottom(1);
						arr[9][9].set_top(1);
						++arr[9][9];
						++arr[8][9];
						if (queue == 1) { rectangle[17][19].setFillColor(Color::Blue); }
						else { rectangle[17][19].setFillColor(Color::Red); }
					}
					else { ms_position = 0; };
					sensor_klick[17][19] = 1;
					break;
					}
					case 0: {
						break;
					}
					};
			//проход массива объектов(проверка на 4 палочки в квадрате):
			if(ms_position!=0){ //если клацнули на палочку
			if (queue == 1) {
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (arr[i][j].get_count() == 4)
						{
						xx[i][j].krestik_txt.loadFromFile("images/x.png");					//загрузили текстуру
						xx[i][j].krestik;													//объявили спрайт 
						xx[i][j].krestik.setTexture(xx[i][j].krestik_txt);					//загрузили текстуру в спрайт
						xx[i][j].krestik.setPosition(arr[i][j].get_coord_x(), arr[i][j].get_coord_y()); //задали позицию		
						// сохраняем координаты клеток, в которых нужно рисовать крестики:	
						size_krestik++;
						fig1[size_krestik - 1].set_figure_i(i).set_figure_j(j);
						queue_2++; 
						++player_x;
						++arr[i][j]; // чтоб count стало 5
						}
					}
				}
						if (queue_2 == 0){  // закрыли квадратик или нет
							queue = 0;
						}
					}
			else if(queue == 0) {
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (arr[i][j].get_count() == 4)
							{
							xx[i][j].nolik_txt.loadFromFile("images/o.png");					//загрузили текстуру
							xx[i][j].nolik;													//объявили спрайт 
							xx[i][j].nolik.setTexture(xx[i][j].nolik_txt);					//загрузили текстуру в спрайт
							xx[i][j].nolik.setPosition(arr[i][j].get_coord_x(), arr[i][j].get_coord_y()); //задали позицию		

						    // сохраняем координаты клеток, в которых нужно рисовать нолики:
							size_nolik++;
							fig2[size_nolik - 1].set_figure_i(i).set_figure_j(j);
							queue_2++;
							++player_o;
							++arr[i][j]; // чтоб count стало 5
									
								}
							}
						}
						if (queue_2 == 0) {  // закрыли квадратик или нет
							queue = 1;
						}
					}
				}
			}
					first_klick = false; // начинаем ставить палочки со 
										 //второго клика(1-й клик - клик по "New Game")
		}
				
			}//PollEvent
			
	//прорисовка объектов:

			if (sizeOfField == 3){						//10x10
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						window.draw(rectangle[i][j]);
					}
				}
			}
			else if (sizeOfField == 2) {					//5x5
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						window.draw(rectangle[i][j]);
					}
				}
				for (int i = 9; i < 14; i++) {
					for (int j = 10; j < 15; j++) {
						window.draw(rectangle[i][j]);
					}
				}
			}
			else if (sizeOfField == 1 ) {					//3x3
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						window.draw(rectangle[i][j]);
					}
				}
				for (int i = 9; i < 12; i++) {
					for (int j = 10; j < 13; j++) {
						window.draw(rectangle[i][j]);
					}
				}
			}

				for (int i = 0; i < size_krestik; i++)
				{
					window.draw(xx[fig1[i].get_figure_i()][fig1[i].get_figure_j()].krestik);
				}
				for (int i = 0; i < size_nolik; i++)
				{
					window.draw(xx[fig2[i].get_figure_i()][fig2[i].get_figure_j()].nolik);
				}
			
				// выводим текущее кол-во очков:
				ostringstream playerScoreString_x, playerScoreString_o;
				playerScoreString_x << player_x.get_count(); //занесли в переменную число очков(формируем строку)
				playerScoreString_o << player_o.get_count(); //занесли в переменную число очков(формируем строку)
								// задаем строку тексту и вызываем сформированную выше строку методом .str()
				text1.setString("X: " + playerScoreString_x.str());
				text2.setString("O: " + playerScoreString_o.str());
				window.draw(text1);
				window.draw(text2);
				// проверка на конец игры и выявление победителя:
				// выиграл крестик:
				if (winnerDetected(player_o.get_count(), player_x.get_count(), sizeOfField) 
					&& player_x.get_count() > player_o.get_count()) {
					text0.setString("Krestik won");
					text0.setFillColor(Color::Blue);
				    text0.setStyle(sf::Text::Bold | sf::Text::Underlined);
					queue = 100; // чтоб не отображалась в конце "инфа о том, кто ходит"
					window.draw(text0);
					// цикл - для одного воспроизведения музыки
					while (music_sensor) {
						music.play();//воспроизводим музыку
						music_sensor = false;
					}
				}
				// выиграл нолик:
				if (winnerDetected(player_o.get_count(), player_x.get_count(), sizeOfField)	
					&& player_x.get_count() < player_o.get_count()) {
					text0.setString("Nolik won");
					text0.setFillColor(Color::Red);
					text0.setStyle(sf::Text::Bold | sf::Text::Underlined);
					queue = 100; // чтоб не отображалась в конце "инфа о том, кто ходит"
					window.draw(text0);
					// цикл - для одного воспроизведения музыки
					while (music_sensor) {
						music.play();//воспроизводим музыку
						music_sensor = false;
					}
				}
				// выводим информацию, о том, кто сейчас ходит:
				if (queue == 1) {
					text0.setString("[X] moves");
					text0.setFillColor(Color::Blue);
					window.draw(text0);
				}	// krestik
				else if (queue == 0) {
					text0.setString("[O] moves");
					text0.setFillColor(Color::Red);
					window.draw(text0);
				} // nolik
				window.draw(text3);
				window.display();
			
		} //game loop ########
		  // удаление двумерного динамического массива
		for (int i = 0; i < 10; i++){
			delete[]arr_copy[i];
		};
};

//Функция, устанавливающая размер поля
Game & Game::set_FieldSize(int size) {
	field_size = size;
	return *this;
};


// ################## class Menu ##################
void Menu::draw_menu(RenderWindow & window) {
	Game gm_ob;
	Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4,
			menuTexture5, menuTexture6, menuTexture7, menuTexture8, 
			menuTexture9, menuTexture10, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/new.png");
	menuTexture2.loadFromFile("images/param.png");
	menuTexture3.loadFromFile("images/mode.png");
	menuTexture4.loadFromFile("images/about.png");
	menuTexture5.loadFromFile("images/exit.png");
	menuTexture6.loadFromFile("images/duel.png");
	menuTexture7.loadFromFile("images/comp.png");
	menuTexture8.loadFromFile("images/3x3.png");
	menuTexture9.loadFromFile("images/5x5.png");
	menuTexture10.loadFromFile("images/10x10.png");
	aboutTexture.loadFromFile("images/abt.png");
	menuBackground.loadFromFile("images/background.jpg");
	Sprite menu1, menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4),
		menu5(menuTexture5), menu6(menuTexture6), menu7(menuTexture7),
		menu8(menuTexture8), menu9(menuTexture9), menu10(menuTexture10),
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
	menu7.setPosition(25, 150);
	menu8.setPosition(115, 100);
	menu9.setPosition(115, 150);
	menu10.setPosition(85, 200);
	abt.setPosition(15, 0);
	menuBg.setPosition(0, 0);
	////////////////////////////// menu loop ////////////////////////
	while (isMenu)
	{
		menu1.setColor(Color::Black);
		menu2.setColor(Color::Black);
		menu3.setColor(Color::Black);
		menu4.setColor(Color::Black);
		menu5.setColor(Color::Black);
		menuNum = 0;
		window.clear(Color::White);

		if (IntRect(60, 30, 200, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(35, 90, 250, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
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
				// New Game:
				if (menuNum == 1) {
					gm_ob.draw_game(window, gm_ob.get_FieldSize(), game_mode);
				}
				// Field Parameters:
				if (menuNum == 2) {
					while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
						
						menu8.setColor(Color::Black);
						menu9.setColor(Color::Black);
						menu10.setColor(Color::Black);
						if (IntRect(110, 100, 120, 50).contains(Mouse::getPosition(window))) {
							menu8.setColor(Color::Red); menuNum = 8;
						}
						if (IntRect(110, 150, 120, 50).contains(Mouse::getPosition(window))) {
							menu9.setColor(Color::Blue); menuNum = 9;
						}
						if (IntRect(80, 200, 180, 50).contains(Mouse::getPosition(window))) {
							menu10.setColor(Color::Blue); menuNum = 10;
						}
						Event event;
						while (window.pollEvent(event)) {
							if (event.type == Event::Closed) { window.close(); }
							if (Mouse::isButtonPressed(Mouse::Left)) {
								if (menuNum == 8) {
									gm_ob.set_FieldSize(1); // 3x3
								}
								if (menuNum == 9) {
									gm_ob.set_FieldSize(2); // 5x5
								}
								if (menuNum == 10) {
									gm_ob.set_FieldSize(3); // 10x10
								}
							}
						}
						window.clear(Color::White);
						window.draw(menuBg);
						window.draw(menu8);
						window.draw(menu9);
						window.draw(menu10);
						window.display();
					}
				}
				//Game Mode:
				if (menuNum == 3) {
					while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
						menu6.setColor(Color::Black);
						menu7.setColor(Color::Black);
						if (IntRect(80, 80, 100, 50).contains(Mouse::getPosition(window))) {
							menu6.setColor(Color::Red); menuNum = 6;}
						if (IntRect(25, 180, 200, 50).contains(Mouse::getPosition(window))) {
							menu7.setColor(Color::Blue); menuNum = 7;}
						Event event;
						while (window.pollEvent(event)) {
							if (event.type == Event::Closed) { window.close(); }
							if (Mouse::isButtonPressed(Mouse::Left)) {
								if (menuNum == 6) { // Duel
									game_mode = 0; 
								}
								if (menuNum == 7) { // Game with computer
									game_mode = 1; 
								}
							}
						}
						window.clear(Color::White);
						window.draw(menuBg);
						window.draw(menu6);
						window.draw(menu7);
						window.display();
					}
				}
				// About:
				if (menuNum == 4) {
					while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
						Event event;
						while (window.pollEvent(event)) {
							if (event.type == Event::Closed) { window.close(); }
						}
						window.clear(Color::White);
						window.draw(abt);
						window.display();
					}
				}
				// Exit:
				if (menuNum == 5) {
					isMenu = false;
					window.close();
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

			// ############  функции:  #############
// проверка на конец игры
bool winnerDetected(int count1, int count2, int sizeOfField) {
	if(sizeOfField == 3){
	if (count1 + count2 == 100) return true;
	else return false;
	}
	if (sizeOfField == 2) {
		if (count1 + count2 == 25) return true;
		else return false;
	}
	if (sizeOfField == 1) {
		if (count1 + count2 == 9) return true;
		else return false;
	}
};

// очень искусственный интеллект:
void comp(MyLines **arr_copy) {
	bool isComp = true; 
	// обрабатываем клетки с 3-мя палочками:
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr_copy[i][j].get_count == 3) {


			}
		}
	}
	// обрабатываем клетки без палочек:
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr_copy[i][j].get_count == 0 && isComp == true ) {

				isComp = false;
			}
		}
	}
	// обрабатываем клетки с одной палочкой:
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr_copy[i][j].get_count == 1 && isComp == true) {

				isComp = false;
			}

		}
	}
	// обрабатываем клетки с 2-мя палочками:
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr_copy[i][j].get_count == 2 && isComp == true) {

				isComp = false;
			}

		}
	}
};