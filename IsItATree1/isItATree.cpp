/*
 * isItATree.cpp
 * SPOJ 1436 Is It A Tree
 *  Created on: Aug 20, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

vector<int> adjList[10001];
bool visited[10001];
int previous[10001];
int N = 0;
int M = 0;

bool isTree()
{
	memset(visited, false, sizeof(visited));
	stack<int> s;
	int visitedNodes = 1;
	visited[1] = true;
	s.push(1);
	while (!s.empty())
	{
		int u = s.top();
		s.pop();
		for (int i=0; i<adjList[u].size(); i++)
		{
			int v = adjList[u][i];
			if (visited[v] && previous[u] != v)
			{
				return false;
			}
			else if (!visited[v])
			{
				visited[v] = true;
				visitedNodes++;
				previous[v] = u;
				s.push(v);
			}
		}
	}
	if (visitedNodes != N)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	cin >> N >> M;
	for (int i=0; i<M; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	if (M != N-1)
	{
		cout << "NO" << endl;
	}
	else if (isTree())
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}



