#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

#define SIZE 8
#define Infinity 1e18

using namespace std;



class Dijkstra
{
	std::vector<std::vector<int>> adjList;
	vector<int> distance;
	vector<bool> visited;
public:
	Dijkstra()
	{

	}
	void SetVertex(int nodeIndex)
	{
		adjList.resize(nodeIndex);
		visited.resize(nodeIndex, false);
		distance.resize(nodeIndex, 0);
		for (int i = 0; i < nodeIndex; i++)
		{
			adjList[i].resize(nodeIndex, Infinity);
		}
		for (int i = 0; i < nodeIndex; i++)
		{
			adjList[i][i] = 0;	// 자신 자리의 코스트는 0으로 처리;
		}
	}
	void SetCost(int vertex, int other, int cost)
	{
		adjList[vertex][other] = cost;
		adjList[other][vertex] = cost;
	}
	const int& Find()
	{
		int i;
		unsigned int temp = Infinity;
		for (i = 0; i < distance.size(); i++)
		{
			if (visited[i] == true) continue;

			if (temp > distance[i])
			{
				temp = distance[i];
				break;
			}
		}
		return i;
	}
	void Update(int start)
	{
		visited[start] = true;
		for (int i = 0; i < adjList[start].size(); i++)
		{
			distance[i] = adjList[start][i];
		}
		for (int i = 0; i < distance.size() - 1; i++)
		{
			int minNode = Find();
			visited[minNode] = true;
			for (int j = 0; j < distance.size() - 1; j++)
			{
				if (visited[j] == true)
				{
					continue;
				}
				else
				{
					if (distance[minNode] + adjList[minNode][j] < distance[j])
					{
						distance[j] = distance[minNode] + adjList[minNode][j];
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
};


int main()
{
#pragma region 다익스트라 알고리즘
	// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘

	// 1. 거리 배열에서 Weight[시작 노드]의 값들로 초기화.

	// 2. 시작점을 방문 처리.

	// 3. 거리 배열에서 최소 비용 노드를 찾고 방문 처리.
	//	  단, 이미 방문한 노드는 제외.

	// 4. 최소 비용 노드를 거쳐갈 지 고민해서 거리 배열을 갱신.
	//    단, 이미 방문한 노드는 제외

	// 5. 모든 노드를 방문할 때 까지 3~4번 반복.

	// 방문하지 않은 노드 중 가장 작은 거리를 가진 노드를 방문하고,
	// 그 노드와 연결된 다른 노드까지의 거리를 계산.

	Dijkstra dijkstra;
	dijkstra.SetVertex(6);
	dijkstra.SetCost(0, 1, 2);
	dijkstra.SetCost(0, 2, 5);
	dijkstra.SetCost(0, 3, 1);
	dijkstra.SetCost(1, 2, 3);
	dijkstra.SetCost(1, 3, 2);
	dijkstra.SetCost(2, 3, 3);
	dijkstra.SetCost(2, 4, 1);
	dijkstra.SetCost(2, 5, 5);
	dijkstra.SetCost(3, 4, 1);
	dijkstra.SetCost(4, 5, 2);

	dijkstra.Update(0);
	// 지금 터짐 수정해야함.
#pragma endregion

	return 0;
}