#include<string>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#define SIZEX 30
#define SIZEY 30
enum MovingInfo {
	ZERO,
	UP,
	DOWN,
	LEFT,
	RIGHT
};
enum GameInfo {
	LOAD,
	PAUSE,
	END,
	BEGIN
};
struct MySettings {
	int Speed=0;
	void SetInFile(std::string One);
	void GetInFile(std::string One);
};
struct MyPoint {
	int x;
	int y;
	void ShowPoint(Graphics^ graphics, Color color, int r);
};
class Snake {
private:
	MyPoint Body[901];
	MyPoint Before;
	int Size;
public:
	Snake() { Size = 1; Body[0] = { 0,0 }; Before = { -1,-1 }; };
	void SnakeMove(MyPoint New);
	void SnakeGrow(MyPoint New);
	MyPoint* GetBody() { return this->Body; };
	int GetSize() { return this->Size; };
	void ShowSnake(Graphics^ graphics, int r);
};
class Box {
private:
	Snake snake;
	int SizeX;
	int SizeY;
public:
	Box() { this->snake; this->SizeX = SIZEX; this->SizeY = SIZEY; };
	int GetSizeX() { return this->SizeX; };
	int GetSizeY() { return this->SizeY; };
	Snake GetSnake() { return this->snake; };
	void SetSnake(Snake snake1) { this->snake = snake1; }
	void ShowBox(Graphics^ graphics, int Height, int Width);
};
class Game {
public:
	Box box;
	MyPoint Apple;
	GameInfo GInfo;
	MovingInfo MoInfo;
	Game() { box; this->GInfo = BEGIN; this->MoInfo = ZERO; NewApple(); };
	void ShowGame(Graphics^ graphics, PictureBox^ pictureBox1);
	bool IfGameEnd();	
	void NewApple();
	void ShowMovingInfo(Graphics^ graphics, PictureBox^ pictureBox1);
	void ShowGameOver(Graphics^ graphics, PictureBox^ pictureBox1);
	void ShowPause(Graphics^ graphics, PictureBox^ pictureBox1);
};