#include <iostream>
#include <random>
#include <vector>

#define SIZE 7
using namespace std;

vector<int> parents;
//Root Node 를 찾는 함수
int find(int x)
{
	if (parents[x] == x)
	{
		return parents[x];
	}
	else
	{
		return parents[x] = find(parents[x]);
	}
	// 배열의 인덱스와 값이 같다면 root Node를 발견

	// 부모의 노드의 번호를 전달하면서 , root Node 를 찾을 때 까지
	// 재귀 함수를 호출하여 반복.
}

void Union(int x, int y)
{
	int findx = find(x);
	int findy = find(y);

	(findx < findy) ? parents[y] = findx : parents[x] = findy;
}
bool Same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
#pragma region  서로소 집합
	// 서로 공통된 원소를 가지고 있지 않은 두 개 이상의 
	// 집합을 의미합니다.

	// union (합집합) : 두 집합을 하나로 합치는 연산.

	// find (찾기) : 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산.

	// 1. 합집합 연산을 확인하여 , 서로 연결된 두 노드를 확인
	//	  -> 1) A와 B의 루트 노드를 A',B' 를 각각 찾음.
	//       2) A',B' 의 부모 노드를 설정.

	// 2. 모든 합집합 연산을 처리할 때 까지 1번을 반복.
	parents.resize(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		parents[i] = i;
	}
	Union(0, 1);
	Union(0, 3);
	Union(1, 3);
	Union(4, 5);

	cout << Same(1, 3) << endl;


#pragma endregion



	return 0;
}