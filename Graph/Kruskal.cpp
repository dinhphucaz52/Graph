#include "Kruskal.h"

vector<Edge> Kruskal::getMST()
{
	vector<Edge> mst;
	vector<Edge> edgeList;

	
	DSU* dsu = new DSU(this->n);
	
	for (int u = 0; u < n; u++)
	{
		for (auto x : adj[u])
		{
			int v = x.first;
			int w = x.second;	
			if (u < v)
				edgeList.push_back({ u, v, w });
		}
	}

	sort(edgeList.begin(), edgeList.end(), [](Edge a, Edge b) {return a.w < b.w; });


	for (auto x : edgeList)
	{
		int u = x.u;
		int v = x.v;
		int w = x.w;
		if (!dsu->check(u, v))
		{
			mst.push_back({ u, v, w });
			dsu->unionSets(u, v);
		}
	}
	free(dsu);
	return mst;
}

Kruskal::~Kruskal()
{
	free(adj);
}
