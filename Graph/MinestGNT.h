#pragma once
#include "Graph.h"

/*
��С������
*/

/*
��krusal�㷨�йصı���
*/

typedef struct
{
	int a, b; //a, b�ֱ�����������ص���������
	int w;//Ȩֵ
}Road;

//Prime�㷨
void prime(int **, int, int , int &);

//Kruskal�㷨
void kruskal(int **, int, int&);