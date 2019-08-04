#include "AdjList.h"

AGraph* create_graph()
{
	cout << "创建一张图" << endl;
	AGraph* graph = new AGraph;
	cout << "请输入顶点个数" << endl;
	cin >> graph->n;
	vector<VNode*>vnodes;
	for (int i = 0; i < graph->n; ++i)
	{
		VNode* vnode = new VNode;
		vnode->No = i;
		int value = 0;
		// 构建ArcNode的单链表
		ArcNode* head = new ArcNode; //为了方便，所以建一个空结点指向单链表头部
		head->nextarc = NULL;
		ArcNode* temp = head;
		while (value >= 0)
		{
			cout << "'请输入节点" << i << "指向的节点(输入负数代表结束)" << endl;
			cin >> value;
			if (value < 0)continue;
			++graph->e;
			ArcNode* next = new ArcNode;
			next->value = value;
			next->nextarc = NULL;
			temp->nextarc = next;
			temp = temp->nextarc;
		}
		vnode->firstarc = head->nextarc;
		graph->adjlist.push_back(vnode);
	}
	return graph;
}

void print_graph(AGraph*graph)
{
	vector<VNode*>adjlist = graph->adjlist;
	for (auto it = adjlist.begin(); it != adjlist.end(); ++it)
	{
		cout << (*it)->No;
		ArcNode* temp = (*it)->firstarc;
		while (temp != NULL)
		{
			cout << "->" << temp->value;
			temp = temp->nextarc;
		}
		cout << endl;
	}
}