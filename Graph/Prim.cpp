#include "Prim.h"
vector<Edge> Prim::getMST(int s)
{
	vector<Edge> mst;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	vector<int> par(this->n);
	vector<bool> vst(this->n, 0);
	vector<int> d(this->n, this->INF);
	d[s] = 0;
	par[s] = s;
	q.push({ d[s], s });
	while (!q.empty()) {
		int u = q.top().second;
		int dis = q.top().first;
		q.pop();
		if (dis > d[u])
			continue;
		if (u != s)
			mst.push_back({ par[u], u, dis });
		vst[u] = true;
		for (auto x : adj[u]) {
			int v = x.first;
			int w = x.second;
			if (d[v] > w && !vst[v]) {
				d[v] = w;
				par[v] = u;
				q.push({ w, v });
			}
		}
	}
	return mst;
}

Prim::~Prim()
{
	free(adj);
}