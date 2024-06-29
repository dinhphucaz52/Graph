#pragma once
#include <iostream>
using namespace std;

class DSU
{
private:
	int n;
	int* par;
	int* sz;
public:
	DSU(int n)
	{
		this->n = n;
		this->par = new int[n];
		this->sz = new int[n];
		for (int u = 0; u < n; u++)
		{
			par[u] = u;
			sz[u] = 1;
		}
	}

	int findSet(int u)
	{
		return u == par[u] ? u : par[u] = findSet(par[u]);
	}

	void unionSets(int u, int v)
	{
		u = findSet(u);
		v = findSet(v);
		if (u != v)
		{
			if (sz[u] < sz[v])
			{
				int tmp = sz[u];
				sz[u] = sz[v];
				sz[v] = tmp;
			}
			par[v] = u;
			sz[v] += sz[u];
		}
	}

	bool check(int u, int v) {
		u = findSet(u);
		v = findSet(v);
		return u == v;
	}

	void check()
	{
		for (int u = 0; u < n; u++)
			cout << u << " " << findSet(u) << endl;
	}

	~DSU()
	{
		free(this->par);
		free(this->sz);
	}
};

