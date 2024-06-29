#include "Dijkstra.h"

vector<int> Dijkstra::getMinDistance(int s)
{
	priority_queue<ii, vector<ii>, greater<ii>> q;
	par.resize(this->n);
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
		for (auto x : adj[u]) {
			int v = x.first;
			int w = x.second;
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				par[v] = u;
				q.push({ d[v], v});
			}
		}
	}
	return d;
}

void Dijkstra::printDistance(int s)
{
	vector<int> dis = getMinDistance(s);
	for (int x : dis)
		cout << x << " ";
	cout << endl;
}

void Dijkstra::printPath(int s, int t)
{
	vector<int> dis = getMinDistance(s);
	cout << dis[t] << endl;
	vector<int> res; 
	for (int v = t; v != s; v = par[v])
		res.push_back(v);
	res.push_back(s);
	reverse(res.begin(), res.end());
	for (int u : res)
		cout << u << " ";
}

Dijkstra::~Dijkstra()
{
	free(adj);
}
