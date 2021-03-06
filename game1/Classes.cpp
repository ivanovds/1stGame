#include<iostream>
#include <SFML/Graphics.hpp>
#include"Classes.h"
#include <sstream> // ������ �� �������� � ������
#include <SFML/Audio.hpp>
using namespace sf;

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
MyLines::MyLines() {
	left = 0, right = 0, top = 0, bottom = 0, count = 0,
	left_rectangle_i = -1, left_rectangle_j = -1,
	right_rectangle_i = -1, right_rectangle_j = -1,
	top_rectangle_i = -1, top_rectangle_j = -1,
	bottom_rectangle_i = -1, bottom_rectangle_j = -1,
	left_number = 0, right_number = 0,
	top_number = 0, bottom_number = 0;
};
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

MyLines & MyLines::set_right_number(int num) {
	right_number = num;
	return *this;
};
MyLines & MyLines::set_left_number(int num) {
	left_number = num;
	return *this;
};
MyLines & MyLines::set_bottom_number(int num) {
	bottom_number = num;
	return *this;
};
MyLines & MyLines::set_top_number(int num) {
	top_number = num;
	return *this;
};



// ################## class Game ##################
void Game::start_game(RenderWindow & window, int sizeOfField) {
	// ############## ������ ���������� �������
	srand(time(0)); // ��������� ����������� �������

	float x, y, rec_size_x, rec_size_y;
	if (sizeOfField == 10) { // 10x10
		x = 30;
		y = 0;
		rec_size_x = 4;
		rec_size_y = 34;
	}
	else if(sizeOfField == 5){ // 5x5
		x = 60;
		y = 0;
		rec_size_x = 8;
		rec_size_y = 69;
	}
	else{ // 3x3
		x = 103;
		y = 0;
		rec_size_x = 13;
		rec_size_y = 116;
	}
	RectangleShape rectangle[20][20];
	for (int i = 0; i < 9; i++) {				// vertical
		for (int j = 0; j < 10; j++) {
			rectangle[i][j].setSize(Vector2f(rec_size_x, rec_size_y));
			rectangle[i][j].setPosition(x, y);
			rectangle[i][j].setFillColor(Color(128, 128, 128));
			rectangle[i][j].setRotation(0);
			y += rec_size_y;
		}
		x += rec_size_y;
		y = 0;
	}
	x = 0;
	y = rec_size_y;
	for (int i = 9; i < 19; i++) {			// horisontal
		for (int j = 10; j < 20; j++) {
			rectangle[i][j].setSize(Vector2f(rec_size_x, rec_size_y));
			rectangle[i][j].setPosition(x, y);
			rectangle[i][j].setFillColor(Color(128, 128, 128));
			rectangle[i][j].setRotation(-90);
			x += rec_size_y;
		}
		x = 0;
		y += rec_size_y;

	}
	if (sizeOfField == 3) { // ��������� ������� ������ �����:
		for (int j = 10; j < 13; j++) {
			rectangle[11][j].setSize(Vector2f(3, rec_size_y));
		}
	}
	//������ ���������� ������� ###############
	
	 // ���� ��� ������� ���������� �������:
	if(sizeOfField == 10){							//10x10
	for (int j = 10; j < 20; j++) {					
		rectangle[18][j].setFillColor(Color::Black);
	}
	}
	if (sizeOfField == 5) {							//5x5
		for (int i = 0; i < 5; i++) {
			rectangle[4][i].setFillColor(Color::Black);
		}
		for (int j = 10; j < 15; j++) {
			rectangle[13][j].setFillColor(Color::Black);
		}
	}
	if (sizeOfField == 3) {							//3x3
		for (int i = 0; i < 3; i++) {
			rectangle[2][i].setFillColor(Color::Black);
		}
		for (int j = 10; j < 13; j++) {
			rectangle[11][j].setFillColor(Color::Black);
		}
	}
	//  ��������� �������� ��� ������� �����������:
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
	if (sizeOfField == 5) {
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
	if (sizeOfField == 3) {
		for (int i = 0; i < 3; i++) {
			arr[2][i].set_bottom(1);
			++arr[2][i];
		};
		for (int i = 0; i < 3; i++) {
			arr[i][2].set_bottom(1);
			++arr[i][2];
		};
	}
	//���������� ������� ��� ������ ������(��� �����������): 
	// ������������:
	for (int j = 1; j < 9; j++) {
		for (int i = 0; i < 10; i++) {
			arr[i][j].set_left_rectangle_i(j-1).set_left_rectangle_j(i).
				set_right_rectangle_i(j).set_right_rectangle_j(i);
		}
	}
	// ��� ������� ���������:
	for (int i = 0; i < 10; i++) { 
		arr[i][0].set_right_rectangle_i(0).set_right_rectangle_j(i);
		arr[i][9].set_left_rectangle_i(8).set_left_rectangle_j(i);
	}
	// ��������������:
	for (int i = 1; i < 9; i++) {
		for (int j = 0; j < 10; j++){
			arr[i][j].set_top_rectangle_i(8+i).set_top_rectangle_j(10 + j).
				set_bottom_rectangle_i(9+i).set_bottom_rectangle_j(10 + j);
		}
	}
	// ��� ������� �������:
	for (int j = 0; j < 10; j++) { 
		arr[0][j].set_bottom_rectangle_i(9).set_bottom_rectangle_j(j+10);
		arr[9][j].set_top_rectangle_i(17).set_top_rectangle_j(j+10);
	}
	// ������ ������� ��� ������ ������: 
	// ������������:
	int rec_number = 1;
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 10; i++) {
			arr[i][j].set_right_number(rec_number);
			rec_number++;
		}
	}
	rec_number = 1;
	for (int j = 1; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			arr[i][j].set_left_number(rec_number);
			rec_number++;
		}
	}
	// ��������������:
	rec_number = 91;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j].set_bottom_number(rec_number);
			rec_number++;
		}
	}
	rec_number = 91;
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j].set_top_number(rec_number);
			rec_number++;
		}
	}

	// ����� ���������� ��� ��������:
	float temp_x = 0, temp_y = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j].set_coord(temp_x, temp_y);
			temp_x += rec_size_y;
		}
		temp_x = 0;
		temp_y += rec_size_y;
	} 
	// ��������� ������:
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
	text0.setPosition(155,348);
	text.setPosition(155, 348);
	text1.setPosition(10, 343);
	text2.setPosition(80, 343);
	text3.setPosition(5, 368);
	//  ������� �������
	MyLines xx[10][10], oo[10][10]; // ������� ��� ��������
	int size_krestik = 0 , size_nolik = 0; //���������� ��������� � �������, ������� ����� ��������
	Figure fig1[101], fig2[101];  // ������� ��� ��������� ������, � ������� ����� �������� ������
	Player player_x, player_o; 
	
	int sensor_klick[20][20];  // ������������� ��������� ���� �� ������� 
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			sensor_klick[i][j] = 0;
		}
	}
	first_klick = true;
	Music music;//������� ������ ������
	music.openFromFile("music.ogg");//��������� ����
	music_sensor = true;
	//############################################## game loop ##############################################
	while (!Keyboard::isKeyPressed(Keyboard::Escape))
	{
		square_closed = 0; // ������������� ��� ���������� ����������
		window.clear(Color::White);
	Event event;
	while (window.pollEvent(event)) {
		int klick = 0; // ������������� ����� ����������� ����, ����� ����� �� ������������ �������
		if (event.type == Event::Closed) { window.close(); }
		if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
		{	if(!first_klick){
			if (gt_ms_position(window, sizeOfField) <= 90) {
				for (int i = 0; i < sizeOfField ; i++) {
					for (int j = 0; j < sizeOfField - 1; j++) {
							if (arr[i][j].get_right_number() == gt_ms_position(window, sizeOfField)) {
								if (sensor_klick[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()] == 0) {
								arr[i][j].set_right(1);
								arr[i][j + 1].set_left(1);
								++arr[i][j];
								++arr[i][j+1];
								if (queue == 1) {
									rectangle[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()].
										setFillColor(Color::Blue);
								}
								else {
									rectangle[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()].
										setFillColor(Color::Red);
								}
								sensor_klick[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()] = 1;
								klick = 1;
								break;
					}
				}
			}
		}
	}
			else {
				for (int i = 0; i < sizeOfField - 1; i++) {
					for (int j = 0; j < sizeOfField ; j++) {
					if (arr[i][j].get_bottom_number() == gt_ms_position(window, sizeOfField)) {
						if (sensor_klick[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()] == 0) {
						arr[i][j].set_bottom(1);
						arr[i+1][j].set_top(1);
						++arr[i][j];
						++arr[i+1][j];
						if (queue == 1) {
							rectangle[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()].
								setFillColor(Color::Blue);
						}
						else {
							rectangle[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()].
								setFillColor(Color::Red);
						}
						sensor_klick[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()] = 1;
						klick = 1;
						break;
					}
				}
			}
		}
	}
			
			//������ ������� ��������(�������� �� 4 ������� � ��������):
			if(gt_ms_position(window, sizeOfField) !=0 && klick==1){ //���� (������ ���!) �������� �� �������
			if (queue == 1) { // ���� ������� �������
				for (int i = 0; i < sizeOfField; i++)
				{
					for (int j = 0; j < sizeOfField; j++)
					{
						if (arr[i][j].get_count() == 4)
						{
							if (sizeOfField == 10) {
								xx[i][j].krestik_txt.loadFromFile("images/x.png"); //��������� ��������
							}
							else if (sizeOfField == 5) {
								xx[i][j].krestik_txt.loadFromFile("images/x_5x5.png"); //��������� ��������
							}
							else {
								xx[i][j].krestik_txt.loadFromFile("images/x_3x3.png"); //��������� ��������
							}
						xx[i][j].krestik;													//�������� ������ 
						xx[i][j].krestik.setTexture(xx[i][j].krestik_txt);					//��������� �������� � ������
						xx[i][j].krestik.setPosition(arr[i][j].get_coord_x(), arr[i][j].get_coord_y()); //������ �������		
						// ��������� ���������� ������, � ������� ����� �������� ��������:	
						size_krestik++;
						fig1[size_krestik - 1].set_figure_i(i).set_figure_j(j);
						square_closed++;
						++player_x;
						++arr[i][j]; // ���� count ����� 5
						}
					}
				}
						if (square_closed == 0){  // ���� �� ������� ���������
							if (get_gameMode() == 0) { queue = 0; } // ���� �����, �� �������� ��� ������
							else{ queue = 2; isComp = true; } // ���� ���� ������������ - �������� ���������
						}
					}
			else if(queue == 0) { // ���� ������� �����
					for (int i = 0; i < sizeOfField; i++)
					{
						for (int j = 0; j < sizeOfField; j++)
						{
							if (arr[i][j].get_count() == 4)
							{
								if(sizeOfField == 10){
								xx[i][j].nolik_txt.loadFromFile("images/o.png"); //��������� ��������
								}
								else if(sizeOfField == 5){
									xx[i][j].nolik_txt.loadFromFile("images/o_5x5.png"); //��������� ��������
								}
								else{
									xx[i][j].nolik_txt.loadFromFile("images/o_3x3.png"); //��������� ��������
								}
							xx[i][j].nolik;													//�������� ������ 
							xx[i][j].nolik.setTexture(xx[i][j].nolik_txt);					//��������� �������� � ������
							xx[i][j].nolik.setPosition(arr[i][j].get_coord_x(), arr[i][j].get_coord_y()); //������ �������		

						    // ��������� ���������� ������, � ������� ����� �������� ������:
							size_nolik++;
							fig2[size_nolik - 1].set_figure_i(i).set_figure_j(j);
							square_closed++;
							++player_o;
							++arr[i][j]; // ���� count(���������� ������� � ��������) ����� 5
								}
							}
						}
						if (square_closed == 0) {  // ���� �� ������� ���������
							set_queue(1);
						}
					}
				}
			}
					first_klick = false; // �������� ������� ������� �� 
										 //������� �����(1-� ���� - ���� �� "New Game")
		}
				
			}//PollEvent
	
			 // ����� ������������� ���������:
			if(queue == 2){
	// ������������ ������ � 3-�� ���������:
			for (int i = 0; i < sizeOfField; i++) {
				for (int j = 0; j < sizeOfField; j++) {
					if (arr[i][j].get_count() == 3) {
						if (arr[i][j].get_left() == 0 && j > 0) {
							arr[i][j].set_left(1);
							++arr[i][j];
							arr[i][j-1].set_right(1);
							++arr[i][j-1];
							sensor_klick[arr[i][j].get_left_rectangle_i()][arr[i][j].get_left_rectangle_j()] = 1;
							rectangle[arr[i][j].get_left_rectangle_i()][arr[i][j].get_left_rectangle_j()].
							setFillColor(Color::Red);
						}
						else if (arr[i][j].get_right() == 0 && j < sizeOfField - 1) {
							arr[i][j].set_right(1);
							++arr[i][j];
							arr[i][j+1].set_left(1);
							++arr[i][j+1];
							sensor_klick[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()] = 1;
							rectangle[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()].
								setFillColor(Color::Red);
						}
						else if (arr[i][j].get_top() == 0 && i > 0) {
							arr[i][j].set_top(1);
							++arr[i][j];
							arr[i-1][j].set_bottom(1);
							++arr[i-1][j];
							sensor_klick[arr[i][j].get_top_rectangle_i()][arr[i][j].get_top_rectangle_j()] = 1;
							rectangle[arr[i][j].get_top_rectangle_i()][arr[i][j].get_top_rectangle_j()].
								setFillColor(Color::Red);
						}
						else if(arr[i][j].get_bottom() == 0 && i < sizeOfField - 1) {
							arr[i][j].set_bottom(1);
							++arr[i][j];
							arr[i+1][j].set_top(1);
							++arr[i+1][j];
							sensor_klick[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()] = 1;
							rectangle[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()].
								setFillColor(Color::Red);
						}

					}
				}
			}
			//��������� ������� ��������� ��� ���
			for (int i = 0; i < sizeOfField; i++)
			{
				for (int j = 0; j < sizeOfField; j++)
				{
					if (arr[i][j].get_count() == 4)
					{
						if (sizeOfField == 10) {
							xx[i][j].nolik_txt.loadFromFile("images/o.png"); //��������� ��������
						}
						else if (sizeOfField == 5) {
							xx[i][j].nolik_txt.loadFromFile("images/o_5x5.png"); //��������� ��������
						}
						else {
							xx[i][j].nolik_txt.loadFromFile("images/o_3x3.png"); //��������� ��������
						}
						xx[i][j].nolik;													//�������� ������ 
						xx[i][j].nolik.setTexture(xx[i][j].nolik_txt);					//��������� �������� � ������
						xx[i][j].nolik.setPosition(arr[i][j].get_coord_x(), arr[i][j].get_coord_y()); //������ �������		

						// ��������� ���������� ������, � ������� ����� �������� ������:
						size_nolik++;
						fig2[size_nolik - 1].set_figure_i(i).set_figure_j(j);
						square_closed++;
						++player_o;
						++arr[i][j]; // ���� count(���������� ������� � ��������) ����� 5

					}
				}
			}
			if (square_closed == 0) {  // ���� �� ������� ���������
				int rand_rectangle = 0;
				// ������������ ������ ��� �������:
				for (int i = sizeOfField-1; i >= 0; i--) {
					for (int j = sizeOfField-1; j >= 0; j--) {
						if (arr[i][j].get_count() == 0 && isComp == true) {
							rand_rectangle = rand() % 4;
							if (rand_rectangle == 0 && j > 0) {
								arr[i][j].set_left(1);
								++arr[i][j];
								arr[i][j - 1].set_right(1);
								++arr[i][j - 1];
								sensor_klick[arr[i][j].get_left_rectangle_i()][arr[i][j].get_left_rectangle_j()] = 1;
								rectangle[arr[i][j].get_left_rectangle_i()][arr[i][j].get_left_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
								break;
							}
							else if (rand_rectangle == 1 && j < sizeOfField - 1) {
								arr[i][j].set_right(1);
								++arr[i][j];
								arr[i][j + 1].set_left(1);
								++arr[i][j + 1];
								sensor_klick[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()] = 1;
								rectangle[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
								break;
							}
							else if (rand_rectangle == 2 && i > 0) {
								arr[i][j].set_top(1);
								++arr[i][j];
								arr[i - 1][j].set_bottom(1);
								++arr[i - 1][j];
								sensor_klick[arr[i][j].get_top_rectangle_i()][arr[i][j].get_top_rectangle_j()] = 1;
								rectangle[arr[i][j].get_top_rectangle_i()][arr[i][j].get_top_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
								break;
							}
							else if (rand_rectangle == 2 && i < sizeOfField - 1) {
								arr[i][j].set_bottom(1);
								++arr[i][j];
								arr[i + 1][j].set_top(1);
								++arr[i + 1][j];
								sensor_klick[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()] = 1;
								rectangle[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
								break;
							}

						}
					}
				}
				// ������������ ������ � ����� ��������:
				for (int i = 0; i < sizeOfField; i++) {
					for (int j = 0; j < sizeOfField; j++) {
						if (arr[i][j].get_count() == 1 && isComp == true) {
							if (arr[i][j].get_left() == 0 && j > 0) {
								arr[i][j].set_left(1);
								++arr[i][j];
								arr[i][j - 1].set_right(1);
								++arr[i][j - 1];
								sensor_klick[arr[i][j].get_left_rectangle_i()][arr[i][j].get_left_rectangle_j()] = 1;
								rectangle[arr[i][j].get_left_rectangle_i()][arr[i][j].get_left_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
								break;
							}
							else if (arr[i][j].get_right() == 0 && j < sizeOfField - 1) {
								arr[i][j].set_right(1);
								++arr[i][j];
								arr[i][j + 1].set_left(1);
								++arr[i][j + 1];
								sensor_klick[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()] = 1;
								rectangle[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
								break;
							}
							else if (arr[i][j].get_top() == 0 && i > 0) {
								arr[i][j].set_top(1);
								++arr[i][j];
								arr[i - 1][j].set_bottom(1);
								++arr[i - 1][j];
								sensor_klick[arr[i][j].get_top_rectangle_i()][arr[i][j].get_top_rectangle_j()] = 1;
								rectangle[arr[i][j].get_top_rectangle_i()][arr[i][j].get_top_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
								break;
							}
							else if (arr[i][j].get_bottom() == 0 && i < sizeOfField - 1) {
								arr[i][j].set_bottom(1);
								++arr[i][j];
								arr[i + 1][j].set_top(1);
								++arr[i + 1][j];
								sensor_klick[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()] = 1;
								rectangle[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
								break;
							}
						}
					}

				}
				// ������������ ������ � 2-�� ���������:
				for (int i = 0; i < sizeOfField; i++) {
					for (int j = 0; j < sizeOfField; j++) {
						if (arr[i][j].get_count() == 2 && isComp == true) {
							if (arr[i][j].get_left() == 0) {
								arr[i][j].set_left(1);
								++arr[i][j];
								arr[i][j - 1].set_right(1);
								++arr[i][j - 1];
								sensor_klick[arr[i][j].get_left_rectangle_i()][arr[i][j].get_left_rectangle_j()] = 1;
								rectangle[arr[i][j].get_left_rectangle_i()][arr[i][j].get_left_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
							}
							else if (arr[i][j].get_right() == 0) {
								arr[i][j].set_right(1);
								++arr[i][j];
								arr[i][j + 1].set_left(1);
								++arr[i][j + 1];
								sensor_klick[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()] = 1;
								rectangle[arr[i][j].get_right_rectangle_i()][arr[i][j].get_right_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
							}
							else if (arr[i][j].get_top() == 0) {
								arr[i][j].set_top(1);
								++arr[i][j];
								arr[i - 1][j].set_bottom(1);
								++arr[i - 1][j];
								sensor_klick[arr[i][j].get_top_rectangle_i()][arr[i][j].get_top_rectangle_j()] = 1;
								rectangle[arr[i][j].get_top_rectangle_i()][arr[i][j].get_top_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
							}
							else {
								arr[i][j].set_bottom(1);
								++arr[i][j];
								arr[i + 1][j].set_top(1);
								++arr[i + 1][j];
								sensor_klick[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()] = 1;
								rectangle[arr[i][j].get_bottom_rectangle_i()][arr[i][j].get_bottom_rectangle_j()].
									setFillColor(Color::Red);
								isComp = false;
							}

						}

					}
				}
				queue = 1; // �������� ��� ��������
			}
		}

	// ���������� ��������:

			if (sizeOfField == 10){						//10x10
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						window.draw(rectangle[i][j]);
					}
				}
			}
			else if (sizeOfField == 5) {					//5x5
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
			else if (sizeOfField == 3 ) {					//3x3
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
			
				// ������� ������� ���-�� �����:
				ostringstream playerScoreString_x, playerScoreString_o;
				playerScoreString_x << player_x.get_count(); //������� � ���������� ����� �����(��������� ������)
				playerScoreString_o << player_o.get_count(); //������� � ���������� ����� �����(��������� ������)
								// ������ ������ ������ � �������� �������������� ���� ������ ������� .str()
				text1.setString("X: " + playerScoreString_x.str());
				text2.setString("O: " + playerScoreString_o.str());
				window.draw(text1);
				window.draw(text2);
				// �������� �� ����� ���� � ��������� ����������:
				// ������� �������:
				if (winnerDetected(player_o.get_count(), player_x.get_count(), sizeOfField) 
					&& player_x.get_count() > player_o.get_count()) {
					text0.setString("Krestik won");
					text0.setFillColor(Color::Blue);
				    text0.setStyle(sf::Text::Bold | sf::Text::Underlined);
					queue= 100; // ���� �� ������������ � ����� "���� � ���, ��� �����"
					window.draw(text0);
					// ���� - ��� ������ ��������������� ������
					while (music_sensor) {
						music.play();//������������� ������
						music_sensor = false;
					}
				}
				// ������� �����:
				if (winnerDetected(player_o.get_count(), player_x.get_count(), sizeOfField)	
					&& player_x.get_count() < player_o.get_count()) {
					text0.setString("Nolik won");
					text0.setFillColor(Color::Red);
					text0.setStyle(sf::Text::Bold | sf::Text::Underlined);
					queue=100; // ���� �� ������������ � ����� "���� � ���, ��� �����"
					window.draw(text0);
					// ���� - ��� ������ ��������������� ������
					while (music_sensor) {
						music.play();//������������� ������
						music_sensor = false;
					}
				}
				// �����:
				if (winnerDetected(player_o.get_count(), player_x.get_count(), sizeOfField)
					&& player_x.get_count() == player_o.get_count()) {
					text0.setString("Draw");
					text0.setFillColor(Color::Black);
					text0.setStyle(sf::Text::Bold | sf::Text::Underlined);
					queue=100; // ���� �� ������������ � ����� "���� � ���, ��� �����"
					window.draw(text0);
					// ���� - ��� ������ ��������������� ������
					while (music_sensor) {
						music.play();//������������� ������
						music_sensor = false;
					}
				}
				// ������� ����������, � ���, ��� ������ �����:
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
		queue = 1;
};

//������� ������ Game:
Game & Game::set_FieldSize(int size) {
	field_size = size;
	return *this;
};
Game &  Game::set_queue(int q) {
	queue = q;
	return *this;
};
Game & Game::set_gameMode(int mode) {
	gameMode = mode;
	return *this;
};
// �������� �� ����� ����
bool Game::winnerDetected(int count1, int count2, int sizeOfField) {
	if (sizeOfField == 10) {
		if (count1 + count2 == 100) { return true; }
		else { return false; }
	}
	if (sizeOfField == 5) {
		if (count1 + count2 == 25) { return true; }
		else {return false;}
	}
	if (sizeOfField == 3) {
		if (count1 + count2 == 9) { return true; }
		else { return false; }
	}
};
// ������� ���������� ��������� �������
int Game::gt_ms_position(RenderWindow & window, int sizeOfField) {
	
	int ms_position = 0;
	float k1, k2, k3, i1 = 1, i2 = 11, rec_size_y;
	// vertical
	if (sizeOfField == 10) { // 10x10
		k1 = 24; 
		k2 = 0;
		k3 = 16;
		rec_size_y = 34;
	}
	else if (sizeOfField == 5) { // 5x5
		k1 = 48;
		k2 = 0;
		k3 = 32;
		rec_size_y = 69;
	}
	else { // 3x3
		k1 = 82;
		k2 = 0;
		k3 = 55;
		rec_size_y = 116;
	}
	
	for (int j = 0; j < 9; j++) {
		for (int i = i1; i < i2; i++)
		{
			if (IntRect(k1, k2, k3, rec_size_y).contains(Mouse::getPosition(window))) { ms_position = i; }
			k2 += rec_size_y;
		}
		k2 = 0;
		k1 += rec_size_y;
		i1 = i2;
		i2 += 10;
	}

	// horisontal
	if (sizeOfField == 10) { // 10x10
		k2 = 24;
	}
	else if (sizeOfField == 5) { // 5x5
		k2 = 48;
	}
	else { // 3x3
		k2 = 82;
	}
	k1 = 0, i1 = 91, i2 = 101;
	for (int j = 0; j < 9; j++) {
		for (int i = i1; i < i2; i++)
		{
			if (IntRect(k1, k2, rec_size_y, k3).contains(Mouse::getPosition(window))) { ms_position = i; } //rec_size_y-4????????
			k1 += rec_size_y;
		}
		k1 = 0;
		k2 += rec_size_y;
		i1 = i2;
		i2 += 10;
	}
	if (IntRect(0, 333, 340, 84).contains(Mouse::getPosition(window))) { ms_position = 0; } // ������ ����� ����(��������)
	return ms_position;
}
// ����������� �� ���������:
Game::Game() {
	queue = 1;  field_size = 10; gameMode = 0; first_klick = true; music_sensor = true;
	isComp = false; square_closed = 0;
};

// ################## class Menu ##################
void Menu::draw_menu(RenderWindow & window) {
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
		abt(aboutTexture), menuBg(menuBackground); //���������� ����������� � ����������� 
	menu1.setTexture(menuTexture1); //���������� �������-�����������
	
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
	abt.setPosition(0, 0);
	menuBg.setPosition(0, 0);
	// �����:
	Font font;
	font.loadFromFile("Capture_it.ttf");
	Text text1("press Esc to go to menu ", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(70, 350);
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
		// ���� �������(� ���������� � ��������� ���������������� �������, �� ��� ����������� 
		//���� ������������ � ���������� �������, ������� ���������� ��� ������������ �� 
		//��������� ������� ���� � ����������� ���)
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				// New Game:
				if (menuNum == 1) {
					gm_ob.start_game(window, gm_ob.get_FieldSize());
				}
				bool menu8_red = false, menu9_blue = false, menu10_red = false,
					 menu6_red = false, menu7_blue = false;
				// Field Parameters:
				if (menuNum == 2) {
					while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
						if (menu8_red){ menu8.setColor(Color::Red); }
						else{ menu8.setColor(Color::Black); }
						if (menu9_blue) { menu9.setColor(Color::Blue); }
						else { menu9.setColor(Color::Black); }
						if (menu10_red) { menu10.setColor(Color::Red); }
						else { menu10.setColor(Color::Black); }
						if (IntRect(110, 100, 120, 50).contains(Mouse::getPosition(window))) {
							menu8.setColor(Color::Red); menuNum = 8;
						}
						if (IntRect(110, 150, 120, 50).contains(Mouse::getPosition(window))) {
							menu9.setColor(Color::Blue); menuNum = 9;
						}
						if (IntRect(80, 200, 180, 50).contains(Mouse::getPosition(window))) {
							menu10.setColor(Color::Red); menuNum = 10;
						}
						Event event;
						while (window.pollEvent(event)) {
							if (event.type == Event::Closed) { window.close(); }
							if (Mouse::isButtonPressed(Mouse::Left)) {
								if (menuNum == 8) {
									menu8_red = true;
									menu9_blue = false;
									menu10_red = false;
									gm_ob.set_FieldSize(3); // 3x3
								}
								if (menuNum == 9) {
									menu9_blue = true;
									menu8_red = false;
									menu10_red = false;
									gm_ob.set_FieldSize(5); // 5x5
								}
								if (menuNum == 10) {
									menu10_red = true;
									menu8_red = false;
									menu9_blue = false;
									gm_ob.set_FieldSize(10); // 10x10
								}
							}
						}
						window.clear(Color::White);
						window.draw(menuBg);
						window.draw(menu8);
						window.draw(menu9);
						window.draw(menu10);
						window.draw(text1);
						window.display();
					}
				}
				//Game Mode:
				if (menuNum == 3) {
					while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
						if(menu6_red){ menu6.setColor(Color::Red); }
						else{ menu6.setColor(Color::Black); }
						if (menu7_blue) { menu7.setColor(Color::Blue); }
						else { menu7.setColor(Color::Black); }
						
						if (IntRect(80, 80, 100, 50).contains(Mouse::getPosition(window))) {
							menu6.setColor(Color::Red); menuNum = 6;}
						if (IntRect(25, 180, 200, 50).contains(Mouse::getPosition(window))) {
							menu7.setColor(Color::Blue); menuNum = 7;}
						Event event;
						while (window.pollEvent(event)) {
							if (event.type == Event::Closed) { window.close(); }
							if (Mouse::isButtonPressed(Mouse::Left)) {
								if (menuNum == 6) { // Duel
									gm_ob.set_queue(0).set_gameMode(0);
									menu6_red = true; 
									menu7_blue = false;
								}
								if (menuNum == 7) { // Game with computer
									gm_ob.set_queue(1).set_gameMode(1);
									menu6_red = false; 
									menu7_blue = true;
								}
							}
						}
						window.clear(Color::White);
						window.draw(menuBg);
						window.draw(menu6);
						window.draw(menu7);
						window.draw(text1);
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
						window.draw(text1);
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
	} //isMenu
}


