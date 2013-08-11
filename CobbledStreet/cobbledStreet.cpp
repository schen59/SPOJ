/*
 * cobbledStreet.cpp
 * SPOJ 368 Cobbled Street
 *  Created on: Aug 9, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

struct Edge
{
	int u;
	int length;
	Edge() {}
	Edge(int u, int length)
	{
		this->u = u;
		this->length = length;
	}
	bool operator < (const Edge &rhs) const
	{
		return length > rhs.length;
	}
};

int adj_matrix[1000][1000];
int n = 0;
int m = 0;
int p = 0;

int solve()
{
	bool *visited = new bool[n];
	int i = 0;
	for (i=0; i<n; i++)
	{
		visited[i] = false;
	}
	priority_queue<Edge> q;
	q.push(Edge(0, 0));
	int vex = 0;
	int cost = 0;
	while (vex < n)
	{
		int u = q.top().u;
		int l = q.top().length;
		q.pop();
		if (visited[u])
		{
			continue;
		}
		vex++;
		visited[u] = true;
		cost += l;
		for (int v=0; v<n; v++)
		{
			if (adj_matrix[u][v] != -1)
			{
				q.push(Edge(v, adj_matrix[u][v]));
			}
		}
	}
	return cost*p;
}

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		cin >> p >> n >> m;
		memset(adj_matrix, -1, sizeof(adj_matrix));
		int i, u, v, l;
		for (i=0; i<m; i++)
		{
			cin >> u >> v >> l;
			adj_matrix[u-1][v-1] = adj_matrix[v-1][u-1] = l;
		}
		cout << solve() << endl;
	}
	return 0;
}



