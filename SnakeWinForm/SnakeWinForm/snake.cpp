#include"shake.hpp"
#include<iostream>
#include<fstream>
extern int t;
void Snake::SnakeMove(MyPoint New) {
	this->Before = this->Body[0];
	for (int i = 0; i < this->Size; i++) {
		this->Body[i] = this->Body[i + 1];
	}
	this->Body[Size - 1] = New;
}
void Snake::SnakeGrow(MyPoint New) {
	this->Size++;
	this->Body[Size - 1] = New;
}
bool Game::IfGameEnd() {
	if (this->box.GetSnake().GetBody()[this->box.GetSnake().GetSize() - 1].x >= SIZEX ||
	this->box.GetSnake().GetBody()[this->box.GetSnake().GetSize() - 1].x < 0 ||
	this->box.GetSnake().GetBody()[this->box.GetSnake().GetSize() - 1].y >= SIZEY ||
	this->box.GetSnake().GetBody()[this->box.GetSnake().GetSize() - 1].y < 0) {
		this->GInfo = END;
		this->MoInfo = ZERO;
		return true;
	}
	for (int i = 0; i < this->box.GetSnake().GetSize() - 2; i++) {
		if (this->box.GetSnake().GetBody()[this->box.GetSnake().GetSize() - 1].x ==
		this->box.GetSnake().GetBody()[i].x &&
		this->box.GetSnake().GetBody()[this->box.GetSnake().GetSize() - 1].y ==
		this->box.GetSnake().GetBody()[i].y) {
			this->GInfo = END;
			this->MoInfo = ZERO;
			return true;
		}
	}
	return false;
}
void Game::NewApple() {
	srand(t);
	while (1) {
		int x = rand() % SIZEX;
		int y = rand() % SIZEY;
		int f = 1;
		for (int i = 0; i < this->box.GetSnake().GetSize(); i++) {
			if (this->box.GetSnake().GetBody()[i].x == x && this->box.GetSnake().GetBody()[i].y == y) {
				f = 0;
				break;
			}
		}
		if (f == 1) {
			this->Apple.x = x;
			this->Apple.y = y;
			break;
		}
	}
}
void MySettings::GetInFile(std::string One) {
	std::fstream input(One);
	input.close();
}
void MySettings::SetInFile(std::string One) {
	std::ofstream output(One, std::ios_base::trunc);
	output.close();
}