/*
 * 106MilesToChicago.cpp
 * SPOJ 381 106 Miles to Chicago
 *  Created on: Aug 10, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node
{
	double dist;
	int u;
	Node() {}
	Node(double dist, int u)
	{
		this->dist = dist;
		this->u = u;
	}
	bool operator < (const Node &rhs) const
	{
		return dist < rhs.dist;
	}
};

double edges[102][102];
int n = 0;
int m = 0;

void dijkstra(int s)
{
	bool visited[102];
	double dist[102];
	memset(visited, 0, sizeof(visited));
	for (int t=1; t<=n; t++)
	{
		dist[t] = 0;
	}
	dist[s] = 1;
	priority_queue<Node> q;
	q.push(Node(1, s));
	while (!q.empty())
	{
		int u = q.top().u;
		q.pop();
		visited[u] = true;
		for (int v=1; v<=n; v++)
		{
			if (!visited[v] && v!=u && edges[u][v] > 0)
			{
				if (dist[u]*edges[u][v] > dist[v])
				{
				    dist[v] = dist[u] * edges[u][v];
				    q.push(Node(dist[v], v));
				}

			}
		}
	}
	cout.precision(6);
	cout << fixed << dist[n]*100 << " percent" << endl;
}

int main()
{
	while (cin >> n && n!=0)
	{
		cin >> m;
		for (int s=1; s<=n; s++)
		{
			for (int t=1; t<=n; t++)
			{
				edges[s][t] = -1;
			}
		}
		for (int i=0; i<m; i++)
		{
			int u, v;
			double d;
			cin >> u >> v >> d;
			edges[u][v] = edges[v][u] = d/100.0;
		}
		dijkstra(1);
	}
	return 0;
}




