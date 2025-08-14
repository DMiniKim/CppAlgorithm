#include <iostream>
#include <random>
#include <queue>
#define SIZE 8

using namespace std;

class Graph
{
private:
	std::queue<int> queue;
	vector<int> adjList[SIZE];
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
		adjList[i].push_back(j);
		adjList[j].push_back(i);
	}
	void BFS(int start)
	{
		//isCheck[start] = true;
		//cout << start << "->";
		//while (!queue[start].empty())	
		//{
		//	int searchIndex = queue[start].front();
		//	queue[start].pop();
		//	if (isCheck[searchIndex] == false)
		//	{
		//		isCheck[searchIndex] = true;
		//		cout << searchIndex << "->";
		//	}
		//	int size = queue[searchIndex].size();
		//	for (int i = 0; i < size; i++)
		//	{
		//		int next = queue[searchIndex].front();
		//		queue[searchIndex].pop();
		//		if (isCheck[next] == false)
		//		{
		//			queue[start].push(next);
		//		}
		//	}
		//}
		queue.push(start);
		isCheck[start] = true;
		while (!queue.empty())
		{
			int temp = queue.front();
			queue.pop();
			cout << temp << "->";
			for (int i = 0; i < adjList[temp].size(); i++)
			{
				int next = adjList[temp][i];
				if (isCheck[next] == false)
				{
					queue.push(next);
					isCheck[next] = true;
				}
			}
		}
	}
};

int main()
{
#pragma region 너비 우선 탐색 ( Breadth First Search )
	// 시작 정점을 방문한 후 시작 정점에 인접한
	// 모든 정점들을 우선적으로 방문하는 탐색.

	// 더 이상 방문하지 않은 정점이 없을 때 까지 방문하지 않은
	// 모든 정점들에 대해서 너비 우선 탐색을 적용.

	Graph graph;
	graph.insert(1, 2);
	graph.insert(1, 3);

	graph.insert(2, 4);
	graph.insert(2, 5);

	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.BFS(1);
#pragma endregion

	return 0;
}