#include "Traverse.h"

// 用于深度优先遍历时记录节点是否被访问过
const int max_len = 100;
vector<int>visit(max_len);

void DFS(AGraph* graph, int v)
{
	vector<VNode*>adjlist = graph->adjlist;
	VNode*vnode = adjlist[v];
	visit[v]= 1;
	cout << vnode->No;
	ArcNode* temp = vnode->firstarc;
	// 注意这是针对连通图的
	while (temp != NULL)
	{
		if (visit[temp->value] != 1)
		{
			DFS(graph, temp->value);
		}
		temp = temp->nextarc;
	}
}

void BFS(AGraph* graph, int v)
{
	queue<int>q;
	vector<VNode*>adjlist = graph->adjlist;
	if (adjlist.size() == 0)
	{
		cout << "图为空, 无法遍历";
		return;
	}
	q.push(adjlist[v]->No);
	cout << adjlist[v]->No;
	visit[v] = 1;
	ArcNode* temp;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		temp = adjlist[front]->firstarc;
		while (temp != NULL)
		{
			if (visit[temp->value] != 1)
			{
				cout << "->"<<temp->value;
				visit[temp->value] = 1;
				q.push(temp->value);
			}
			temp = temp->nextarc;
		}
	}
}

void find_farest_node(AGraph*graph, int v)
{
	visit.resize(max_len);
	int farest;
	queue<int>q;
	q.push(v);
	vector<VNode*>adjlist = graph->adjlist;
	visit[adjlist[v]->No] = 1;
	farest = adjlist[v]->No;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		ArcNode* temp = adjlist[front]->firstarc;
		while (temp != NULL)
		{
			if (visit[temp->value] != 1)
			{
				q.push(temp->value);
				visit[temp->value] = 1;
				farest = temp->value;
			}
			temp = temp->nextarc;
		}
	}
	cout << "离编号为" << v << "最远的节点中其中的一个节点的编号为：" << farest << endl;
}