/*
 * vertexCover.cpp
 * SPOJ 1435 Vertex Cover
 *  Created on: Aug 19, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define min(a, b) ((a<b) ? a : b)

int vCover[100001][2];

void solve(int u, const vector<int> adjList[], bool visited[])
{
	visited[u] = true;
	int v0 = 0;
	int v1 = 1;
	for (int i=0; i<adjList[u].size(); i++)
	{
		int v = adjList[u][i];
		if (!visited[v])
		{
			solve(v, adjList, visited);
		}
		v0 += vCover[v][1];
		v1 += min(vCover[v][0], vCover[v][1]);
	}
	vCover[u][0] = v0;
	vCover[u][1] = v1;
}

int main()
{
	int N = 0;
	cin >> N;
	vector<int> adjList[N+1];
	bool *visited = new bool[N+1];
	memset(visited, false, sizeof(bool)*(N+1));
	for (int i=0; i<N-1; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	solve(1, adjList, visited);
	cout << min(vCover[1][0], vCover[1][1]) << endl;
	return 0;
}



