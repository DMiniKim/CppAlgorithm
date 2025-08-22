#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <queue>
#include <Windows.h>

using namespace std;
#define WIDTH 10
#define HEIGHT 10

int map[HEIGHT][WIDTH] = // 배열 선언 순서 변경 (y, x)
{
	{1,0,1,0,1,1,1,1,0,1},
	{1,1,1,0,1,0,0,1,0,1},
	{0,1,0,1,1,0,1,0,1,1},
	{1,1,1,1,0,0,1,1,1,0},
	{0,0,0,1,0,0,1,0,1,1},
	{0,1,1,1,1,1,1,1,0,0},
	{0,1,0,0,0,0,0,1,1,1},
	{0,1,1,1,0,1,1,1,0,1},
	{1,0,0,1,0,1,0,0,0,0},
	{1,1,1,1,0,1,1,1,1,1},
};
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void GotoXY(int x, int y)
{
	COORD pos = { (SHORT)x * 2, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

enum Direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
	DIRECTION_COUNT,
};

class Character
{
private:
	const char* shape;
	int currentX;
	int currentY;
	Direction dir;

public:
	Character()
	{
		shape = "옷";
		currentX = 0;
		currentY = 0;
		dir = DOWN;
	}
	
	bool IsSafe(int x, int y)
	{
		if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
			return false; // 맵 밖으로 벗어나는 경우
		if (map[y][x] == 0)
			return false; // 벽에 부딪히는 경우
		return true; // 안전한 위치
	}

	void Update()
	{
		int nextX = currentX;
		int nextY = currentY;

	
		switch (dir)
		{
		case UP: nextY--; break;
		case RIGHT: nextX++; break;
		case DOWN: nextY++; break;
		case LEFT: nextX--; break;
		default: break;
		}

		// 다음 위치가 안전한지 확인
		if (IsSafe(nextX, nextY))
		{
			// 안전하면 이동
			currentX = nextX;
			currentY = nextY;
		}
		else
		{
			// 벽을 만났을 경우, 무작위로 좌 또는 우로 방향 변경
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(0, 1);

			if (dis(gen) == 0) { // 0이면 좌회전
				dir = static_cast<Direction>(((dir + DIRECTION_COUNT)- 1) % DIRECTION_COUNT);
			}
			else { // 1이면 우회전
				dir = static_cast<Direction>((dir + 1) % DIRECTION_COUNT);
			}
		}
	}
	void Render()
	{
		GotoXY(currentX, currentY);
		cout << shape;
	}
};
void ShowMap()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			switch (map[y][x])
			{
			case 0: cout << "■";
				break;
			case 1: cout << "  ";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}
int main()
{
	Character character;
	while (true)
	{
		HideCursor();
		system("cls");
		ShowMap();
		character.Render();
		character.Update(); 
		Sleep(100);
	}
	return 0;
}