#pragma once
#include "Graph.h"

/*
最小生成树
*/

/*
与krusal算法有关的变量
*/

typedef struct
{
	int a, b; //a, b分别是这条边相关的两个顶点
	int w;//权值
}Road;

//Prime算法
void prime(int **, int, int , int &);

//Kruskal算法
void kruskal(int **, int, int&);