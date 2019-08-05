#include "AdjMatrix.h"

#include<cstdlib>

int** static_graph_matrix(int N)
{
	int** graph = (int**)(malloc(sizeof(int *)*N));
	if (graph == NULL)
		return NULL;
	for (int i = 0; i < N; ++i)
	{
		graph[i] = (int*)(malloc(sizeof(int) * N));
		for (int j = 0; j < N; ++j)
		{
			graph[i][j] = 100001;
		}
	}
	graph[0][1] = 5;
	graph[0][2] = 1;
	graph[0][3] = 2;
	graph[1][0] = 5;
	graph[1][2] = 3;
	graph[1][4] = 4;
	graph[2][0] = 1;
	graph[2][1] = 3;
	graph[2][3] = 6;
	graph[2][4] = 2;
	graph[3][0] = 2;
	graph[3][2] = 6;
	graph[3][4] = 3;
	graph[4][1] = 4;
	graph[4][2] = 2;
	graph[4][3] = 3;
	return graph;
}