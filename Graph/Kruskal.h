#pragma once
#include "Graph.h"
#include "DSU.h"
#include <algorithm>

class Kruskal : public Graph
{
public:
	Kruskal(int n) : Graph(n) {}

	Kruskal(int n, vector<Edge> edgeList) : Graph(n, edgeList) {}

	Kruskal(int n, int** a) : Graph(n, a) {}

	vector<Edge> getMST();

	~Kruskal();
};

