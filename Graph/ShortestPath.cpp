#include "ShortestPath.h"
#include <stack>

int** matrix_for_dijkstra()
{
	/*
		0 1 4
		0 2 6
		0 3 6
		1 2 1
		1 4 7
		2 4 6 
		2 5 4
		3 2 2
		3 5 5
		4 6 6
		5 4 1
		5 6 8
	*/
	int **graph=(int **)(malloc(sizeof(int *)*N));
	for (int i = 0; i < N; ++i)
	{
		graph[i] = (int*)(malloc(sizeof(int)*N));
		for (int j = 0; j < N; ++j)
		{
			graph[i][j] = INFI;
		}
	}
	int a, b, len;
	for (int i = 0; i < E; ++i)
	{
		cin >> a >> b >> len;
		graph[a][b] = len;
	}
	return graph;
}
int** matrix_for_floyd()
{
	return nullptr;
}
void Dijkstra(int **graph, int v, int*dist, int*path)
{
	bool isSet[N]; //是否包含进最小生成树的集合中
	for (int i = 0; i < N; ++i)
	{
		isSet[i] = false;
		dist[i] = graph[v][i];
		if (graph[v][i] != INFI)
			path[i] = v;
		else
			path[i] = -1;
	}
	isSet[v] = true;
	for (int i = 0; i < N - 1; ++i)
	{
		int min = INFI;
		int u = -1;
		for (int j = 0; j < N; ++j)
		{
			if (!isSet[j] && dist[j] < min)
			{
				min = dist[j];
				u = j;
			}
		}
		if (u == -1)
			return;
		isSet[u] = true;
		for (int j = 0; j < N; ++j)
		{
			if (!isSet[j] && dist[u] + graph[u][j] < dist[j])
			{
				dist[j] = dist[u] + graph[u][j];
				path[j] = u;
			}
		}
	}
}
void Floyd()
{

}

void testDijkstra()
{
	int** graph = matrix_for_dijkstra();
	int dist[N];
	int path[N];
	const int start = 3;
	Dijkstra(graph,start,dist,path);
	for (int i = 0; i < N; ++i)
	{
		int a = i;
		stack<int>s;
		s.push(a);
		while (path[a] != -1)
		{
			a = path[a];
			s.push(a);
		}
		if (s.size() == 1 && s.top() != start)
		{
			cout << "不存在从节点"<<start<<"到节点"<<i <<"的最短路径"<< endl;
			continue;
		}
		while (!s.empty())
		{
			cout << s.top() << '\t';
			s.pop();
		}
		cout << endl;
	}
}