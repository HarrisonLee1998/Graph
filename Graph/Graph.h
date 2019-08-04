#pragma once

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef struct ArcNode
{
	int value;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode
{
	int No;
	ArcNode* firstarc;
}VNode;

typedef struct AGraph
{
	vector<VNode*>adjlist; //邻接表
	int n, e; //分别是顶点数和边数
}AGraph;
