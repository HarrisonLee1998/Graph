#include "AdjList.h"

AGraph* create_graph()
{
	cout << "创建一张有向图" << endl;
	AGraph* graph = new AGraph;
	cout << "请输入顶点个数" << endl;
	cin >> graph->n;
	vector<VNode*>vnodes;
	for (int i = 0; i < graph->n; ++i)
	{
		VNode* vnode = new VNode;
		vnode->No = i;
		int value=0;
		// 构建ArcNode的单链表
		ArcNode* head = new ArcNode; //为了方便，所以建一个空结点指向单链表头部
		head->nextarc = NULL;
		ArcNode* temp=head;
		while (value >= 0)
		{
			cout << "'请输入节点" << i << "指向的节点" << endl;
			cin >> value;
			if (value < 0)continue;
			++graph->e;
			ArcnNode* next = new ArcNode;
			next->adjvex = value;
			next->nextarc = NULL;
			temp->nextarc=next;
			temp = temp->nextarc;
		}
		vnode->firstarc = head->nextarc;
		graph->adjlist.push_back(vnode);
	}
	return graph;
}