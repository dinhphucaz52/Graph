#pragma once
#include "Graph.h"

class Prim : public Graph
{
public:
	Prim(int n) : Graph(n) {}

	Prim(int n, vector<Edge> edgeList) : Graph(n, edgeList) {}

	Prim(int n, int** a) : Graph(n, a) {}

	vector<Edge> getMST(int s);

	~Prim();
};
