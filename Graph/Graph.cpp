#include "Graph.h"

Graph::Graph() : n(0), INF(0), adj(nullptr) {}

Graph::Graph(int n) : n(n), INF(0), adj(new vector<ii>[n]) {}


Graph::Graph(int n, vector<Edge> edgeList) : Graph(n)
{
	for (int i = 0; i < edgeList.size(); i++)
	{
		int u = edgeList[i].u;
		int v = edgeList[i].v;
		int w = edgeList[i].w;
		INF = max(INF + 1, w);
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
}

Graph::Graph(int n, int** a) : Graph(n)
{
	for (int u = 0; u + 1 < n; u++)
	{
		for (int v = u + 1; v < n; v++)
		{
			if (a[u][v])
			{
				adj[u].push_back({ v, a[u][v] });
				adj[v].push_back({ u, a[u][v] });
			}
		}
	}
}

void Graph::printDSK()
{
	for (int u = 0; u < n; u++)
	{
		cout << u << " : ";
		for (auto x : adj[u])
		{
			cout << x.first << "," << x.second << " ";
		}
		cout << endl;
	}
}

Graph::~Graph()
{
	free(this->adj);
}
