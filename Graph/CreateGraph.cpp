#include "AdjList.h"

AGraph* create_graph()
{
	cout << "����һ������ͼ" << endl;
	AGraph* graph = new AGraph;
	cout << "�����붥�����" << endl;
	cin >> graph->n;
	vector<VNode*>vnodes;
	for (int i = 0; i < graph->n; ++i)
	{
		VNode* vnode = new VNode;
		vnode->No = i;
		int value=0;
		// ����ArcNode�ĵ�����
		ArcNode* head = new ArcNode; //Ϊ�˷��㣬���Խ�һ���ս��ָ������ͷ��
		head->nextarc = NULL;
		ArcNode* temp=head;
		while (value >= 0)
		{
			cout << "'������ڵ�" << i << "ָ��Ľڵ�" << endl;
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