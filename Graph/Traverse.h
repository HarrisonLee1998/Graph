#pragma once
#include "Graph.h"

// 深度优先搜索遍历
void DFS(AGraph*, int);

// 广度优先搜索遍历
void BFS(AGraph*, int);

//寻找距离顶点v最远的一个顶点
void find_farest_node(AGraph*, int);