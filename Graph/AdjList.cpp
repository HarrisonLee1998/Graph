#include "AdjList.h"

AGraph* create_graph()
{
	cout << "����һ��ͼ" << endl;
	AGraph* graph = new AGraph;
	cout << "�����붥�����" << endl;
	cin >> graph->n;
	vector<VNode*>vnodes;
	for (int i = 0; i < graph->n; ++i)
	{
		VNode* vnode = new VNode;
		vnode->No = i;
		int value = 0;
		// ����ArcNode�ĵ�����
		ArcNode* head = new ArcNode; //Ϊ�˷��㣬���Խ�һ���ս��ָ������ͷ��
		head->nextarc = NULL;
		ArcNode* temp = head;
		while (value >= 0)
		{
			cout << "'������ڵ�" << i << "ָ��Ľڵ�(���븺���������)" << endl;
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