#pragma once
#include "Graph.h"
class Dijkstra : public Graph
{
private:
	vector<int> par;
public:

	Dijkstra(int n) : Graph(n) {
		par = vector<int>();
	}

	Dijkstra(int n, vector<Edge> edgeList) : Graph(n, edgeList) {
		par = vector<int>();
	}

	Dijkstra(int n, int** a) : Graph(n, a) {
		par = vector<int>();
	}

	vector<int> getMinDistance(int s = 0);

	void printDistance(int s = 0);

	void printPath(int s, int t);

	~Dijkstra();
};

