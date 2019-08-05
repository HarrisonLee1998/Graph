#include "MinestGNT.h"
#include "cstdlib"

void prime(int**graph, int len, int v0, int& sum)
{
	const int INFI = 10000;
	int* lowest = (int*)(malloc(sizeof(int)*len)); //每个节点距离生成树最短的距离，0代表该节点已经在生成树中了
	int* vset = (int*)(malloc(sizeof(int) * len)); //vest[i]==1则代表i节点在最小生成树中了
	for (int i = 0; i < len; ++i)
	{
		vset[i] = 0;
		lowest[i] = graph[v0][i];
	}
	vset[v0] = 1;
	sum = 0;
	for (int i = 0; i < len-1; ++i)
	{
		int minest = INFI;
		int k=-1;
		for (int j = 0; j < len; ++j)
		{
			if (vset[j] != 1 && lowest[j] < minest)
			{
				minest = lowest[j];
				k = j;
			}
		}
		vset[k] = 1;
		v0 = k;
		sum += minest;
		for (int j = 0; j < len; ++j)
		{
			if(vset[j]!=1&&graph[v0][j]<lowest[j])
				lowest[j] = graph[v0][j];
		}
	}
}

void kruskal(int **graph, int N,  int&sum)
{
	Road* road = (Road*)(malloc(sizeof(Road) * N * (N - 1)));
	int* v = (int*)(malloc(sizeof(int) * N * (N - 1)));
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (graph[i][j] < 10001)
			{
				road[count].a = i;
				road[count].b = j;
				road[count].w = graph[i][j];
				++count;
			}
		}
		v[i] = i;
	}

	//首先对road数组排序（根据权值）
	for (int i = 0; i < count-1; ++i)
	{
		for (int j = i; j < count; ++j)
		{
			if (road[i].w > road[j].w)
			{
				Road temp = road[i];
				road[i] = road[j];
				road[j] = temp;
			}
		}
	}

	sum = 0;
	for (int i = 0; i < count; ++i)
	{
		int a=road[i].a, b=road[i].b;
		while (a != v[a])a = v[a];
		while (b != v[b])b = v[b];
		if (a != b)
		{
			v[a] = b;
			sum += road[i].w;
		}
	}
}
