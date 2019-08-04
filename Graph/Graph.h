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
	vector<VNode*>adjlist; //�ڽӱ�
	int n, e; //�ֱ��Ƕ������ͱ���
}AGraph;
