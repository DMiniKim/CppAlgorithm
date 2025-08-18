#include <iostream>
#include <vector>
#define SIZE 4

using namespace std;
std::vector<bool> map[SIZE];
// vector<vector<bool>> map
bool visited[SIZE][SIZE] = {};

void CreateMap(int x, int y)
{
	//map.resize(x);
	//for (int _y = 0; _y < y; _y++)
	//{
	//	map[_y].resize(y);
	//}
}
void SelectMap(bool a, bool b, bool c, bool d)
{
	int index = 0;
	while (index < SIZE)
	{
		if (map[index].empty())
		{
			map[index].push_back(a);
			map[index].push_back(b);
			map[index].push_back(c);
			map[index].push_back(d);
			break;
		}
		else
		{
			index++;
		}
	}

}

bool Search(int x, int y)
{
	if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) return false;
	
	if (map[x][y] == false)		return false;

	if (visited[x][y] == true)	return false;
		
	if (x == SIZE - 1 && y == SIZE - 1)		return true;

	visited[x][y] = true;

	
	if (Search(x, y + 1)) return true;	// 오른쪽으로 이동	
	if (Search(x + 1, y)) return true;	// 아래로 이동
	if (Search(x, y - 1)) return true;	// 왼쪽으로 이동
	if (Search(x - 1, y)) return true;	// 위로 이동
	
	visited[x][y] = false;

	return false;
}


int main()
{
#pragma region 백 트래킹 ( Back Tracking )


	// 백 트래킹(Backtracking) 개요

	// 백 트래킹은 재귀적 알고리즘의 한 종류로, 
	// 모든 가능한 경우의 수를 탐색하면서 문제를 해결하는 방법.
	// 해를 찾는 과정에서 "가능성이 없는 경로"를 발견하면 즉시 되돌아가서(backtrack) 
	// 다른 경로를 탐색하는 것이 핵심 원리.

	// 쉽게 말해, 미로를 탐색하는 느낌.
	// 
	// 앞으로 나아가다가(하나의 해를 찾는 과정)    
	// 
	// 막다른 길에 도달하면(더 이상 해가 될 가능성이 없는 경우)   
	// 
	// 바로 전 갈림길로 되돌아가서(백트래킹) 다른 길을 선택하여 다시 탐색.    
	// 
	// 이 과정을 해를 찾을 때까지 또는 모든 경로를 다 탐색할 때까지 반복.


	// 주요 특징 
	// =================================================================================== 
	// 재귀 호출 : 대부분 재귀 함수를 사용하여 구현.

	// 상태 공간 트리(State - Space Tree) : 백트래킹은 모든 가능한 해를 트리 구조로 나타내고, 
	//                                    이 트리를 깊이 우선 탐색(DFS) 방식으로 탐색합니다.

	// 가지치기(Pruning) : 불필요한 경로를 탐색하지 않고 중간에 되돌아가는 것
	//                    이 덕분에 무식하게 모든 경우의 수를 탐색하는 브루트 포스(Brute - force)보다 효율적임.
	// =================================================================================== 

	// 예시 : 백 트래킹은 다음과 같은 문제들을 해결하는 데 자주 사용됨.

	// 1. N - Queen 문제    
	// 2. 미로 찾기    
	// 3. 조합, 순열 생성    
	// 4. 스도쿠 퍼즐 해결


#pragma endregion
	CreateMap(4, 4);
	SelectMap(1, 1, 1, 1);
	SelectMap(0, 0, 0, 1);
	SelectMap(1, 1, 1, 1);
	SelectMap(1, 0, 0, 1);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	if (Search(0, 0))
	{
		cout << "찾았다 당신은 길을" << endl;
	}
	

}

