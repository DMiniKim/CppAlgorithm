#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <queue>
#define SIZE 8
using namespace std;

class Graph
{
private:
	//queue<int> queue;
	vector<int> adjList[SIZE];
	vector<int> inDegree;
	bool isCheck[SIZE];
public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			isCheck[i] = false;
		}
		inDegree.resize(SIZE, 0);

	}
	void insert(int vertex, int edge)
	{
		adjList[vertex].push_back(edge);
		cout << vertex << " -> " << edge << endl;
		inDegree[edge]++;
	}
	void TopologicalSort()
	{
		std::queue<int> queue;
		for (int i = 1; i < SIZE; i++)
		{
			if (inDegree[i] == 0)
			{
				queue.push(i);
			}
		}
		while (queue.empty() == false)
		{
			int x = queue.front();

			queue.pop();

			cout << x << " ";

			for (int i = 0; i < adjList[x].size(); i++)
			{
				int start = adjList[x][i];
				inDegree[start]--;
				if (inDegree[start] == 0)
				{
					queue.push(start);
				}
			}
		}
	}
};

int main()
{
#pragma region 위상 정렬
	// 병합 그래프의 존재하는 각 정점들의 선행 순서를 지키며,
	// 정점들을 차례대로 진행해서 나열하는 알고리즘.

	// 사이클이 발생하는 경우 위상 정렬을 수행할 수 없음.

	// DAG(Directed Acyclic Graph) : 사이클이 존재하지 않는 그래프

	// 시간 복잡도 : // O(V + E) (Vertex : 정점의 개수, Edge : 간선의 개수)

	// 위상 정렬하는 방법

	// 1. 진입 차수가 0인 정점을 큐에 삽입.

	// 2. Queue에서 원소를 꺼내 연결된 모든 간선을 제거.

	// 3. 간선 제거 이후에 진입차수가 0 이된 정점을 Queue에 삽입.

	// 4. Queue가 비어있을 때 까지 2번~ 3번 작업을 반복 수행.


	Graph graph;
	graph.insert(1, 2);
	graph.insert(1, 5);
	graph.insert(2, 3);
	graph.insert(3, 4);
	graph.insert(4, 6);
	graph.insert(5, 6);
	graph.insert(6, 7);

	graph.TopologicalSort();

#pragma endregion

	return 0;
}