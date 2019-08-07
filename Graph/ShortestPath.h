#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

const int INFI = 100000000;
const int N = 7, E = 12;

int** matrix_for_dijkstra();
int** matrix_for_floyd();
void Dijkstra(int**, int , int* , int* );
void Floyd();
void testDijkstra();