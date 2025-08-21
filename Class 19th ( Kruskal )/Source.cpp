#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

#define SIZE 8
using namespace std;

class Kruskal
{
private:

	class Edge
	{
	public:
		int vertexX;
		int vertexY;
		int weight;
		Edge(int x, int y, int w) :vertexX(x), vertexY(y), weight(w) {};

		const int& X() { return vertexX; }
		const int& Y() { return vertexY; }
		const int& Weight() { return weight; }

		const bool& operator < (const Edge& other)
		{
			return this->weight < other.weight;
		}
	};
	std::vector<Edge> nodeList;
	int cost = 0;
	std::vector<int> parents;
	int parentsCount = 0;
public:
	Kruskal()
	{
		cost = 0;
	}
	void insert(int vertexX, int vertexY, int weight)
	{
		Edge edge(vertexX, vertexY, weight);
		parents.push_back(parentsCount++);
		nodeList.push_back(edge);
	}
	void Calculate()
	{
		sort(nodeList.begin(), nodeList.end());
		for (int i = 0; i < nodeList.size();i++)
		{
			if (Find(nodeList[i].X()) == Find(nodeList[i].Y()))
			{
				continue;
			}
			Union(nodeList[i].X(), nodeList[i].Y());
			cost += nodeList[i].Weight();
		}
		cout << cost << endl;
		//for (auto& element : nodeList)
		//{
		//	cout << "X : " << element.vertexX << "\t" <<
		//		    "Y : " << element.vertexY << "\t" << 
		//		    "Weight : " << element.weight << endl;
		//}
	}
	int Find(int x)
	{
		if (parents[x] == x)
		{
			return parents[x];
		}
		else
		{
			return parents[x] = Find(parents[x]);
		}
	}
	void Union(int x, int y)
	{
		int findX = Find(x);
		int findY = Find(y);
		if (x == y)
			return;

		(findX < findY) ? parents[y] = findX : parents[x] = findY;
	}
};

int main()
{
#pragma region 최소 신장 트리
	// 그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는
	// 부분 그래프로 , 그래프의 모든 정점을 최소 비용으로 연결하는 트리입니다.

	// 그래프의 정점의 수가 n 개 일 때 , 간선의 수는 n-1 개이다.
	Kruskal kruskal;
	kruskal.insert(1, 7, 12);
	kruskal.insert(4, 7, 13);
	kruskal.insert(1, 4, 30);
	kruskal.insert(4, 2, 23);
	kruskal.insert(1, 2, 71);
	kruskal.insert(7, 5, 79);
	kruskal.insert(1, 5, 15);
	kruskal.insert(2, 5, 65);
	kruskal.insert(6, 5, 44);
	kruskal.insert(3, 5, 18);
	kruskal.insert(3, 6, 36);
	kruskal.Calculate();



#pragma endregion

	return 0;
}