#include <iostream>
#include <random>
#include <vector>
#define SIZE 8

using namespace std;

class Graph
{
private:
	vector<int> data[SIZE];
	bool isCheck[SIZE];
public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			isCheck[i] = false;
		}
	}
	void insert(int i, int j)
	{
		auto itI = find(data[i].begin(), data[i].end(), j);
		auto itJ = find(data[j].begin(), data[j].end(), i);
		if (itI == data[i].end())
		{
			data[i].push_back(j);
		}
		if (itJ == data[j].end())
		{
			data[j].push_back(i);
		}
	}
	void DFS(int start)
	{

		isCheck[start] = true;
		cout << start << " - ";
		int size = data[start].size();
		for (int i = 0; i < size; i++)
		{
			if (isCheck[data[start][i]] == false)
			{
				DFS(data[start][i]);
			}
		}
	}
};

int main()
{
#pragma region 깊이 우선 탐색 (Depth First Search)
	// root 노드에서부터 다음 분기로 넘어가기 전에
	// 해당 분기를 완벽하게 탐색하는 방법.

	// 깊이 우선 탐색은 Stack을 활용합니다.
#pragma endregion
	Graph graph;
	graph.insert(1, 2);
	graph.insert(1, 3);

	graph.insert(2, 3);
	graph.insert(2, 4);
	graph.insert(2, 5);

	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.insert(4, 5);
	graph.insert(6, 7);

	graph.DFS(1);

	return 0;
}