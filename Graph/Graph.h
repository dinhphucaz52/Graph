#pragma once
#include <queue>
#include <vector>
#include "Edge.h"
#include <iostream>

using namespace std;

#define ii pair<int, int>

class Graph
{
protected:
	int n;
	int INF;
	vector<ii>* adj;
public:
	Graph();

	Graph(int n);

	Graph(int n, vector<Edge> edgeList);

	Graph(int n, int** a);

	void printDSK();

	~Graph();
};

