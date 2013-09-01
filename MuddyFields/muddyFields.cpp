/*
 * muddyFields.cpp
 * SPOJ 282 Muddy Fields
 *  Created on: Aug 31, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

bool fields[50][50];
int horizontal[50][50];
int vertical[50][50];
int C = 0;
int R = 0;

struct BipartieGraph
{
	int leftNodesNum;
	int rightNodesNum;
	bool** edges;
	int *matched;
	BipartieGraph(int leftNodesNum, int rightNodesNum)
	{
		this->leftNodesNum = leftNodesNum;
		this->rightNodesNum = rightNodesNum;
		edges = new bool*[leftNodesNum];
		for (int i=0; i<leftNodesNum; i++)
		{
			edges[i] = new bool[rightNodesNum];
			memset(edges[i], false, sizeof(bool)*rightNodesNum);
		}
		matched = new int[rightNodesNum];
		memset(matched, -1, sizeof(int)*rightNodesNum);
	}

	void addEdge(int i, int j)
	{
		edges[i][j] = true;
	}

	bool canMatch(int i, bool *isVisited)
	{
		for (int j=0; j<rightNodesNum; j++)
		{
			if (edges[i][j] && !isVisited[j])
			{
				isVisited[j] = true;
				if (matched[j] == -1 || canMatch(matched[j], isVisited))
				{
					matched[j] = i;
					return true;
				}
			}
		}
		return false;
	}

	int maxMatch()
	{
		bool *isVisited = new bool[rightNodesNum];
		int result = 0;
		for (int i=0; i<leftNodesNum; i++)
		{
			memset(isVisited, false, sizeof(bool)*rightNodesNum);
			if (canMatch(i, isVisited))
			{
				result++;
			}
		}
		return result;
	}
};

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		cin >> R >> C;
		char c;
		int i, j;
		for (i=0; i<R; i++)
		{
			for (j=0; j<C; j++)
			{
				cin >> c;
				fields[i][j] = (c == '*');
			}
		}
		int leftNodesNum = -1;
		int rightNodesNum = -1;
		memset(horizontal, -1, sizeof(horizontal));
		memset(vertical, -1, sizeof(vertical));
		for (i=0; i<R; i++)
		{
			for (j=0; j<C; j++)
			{
				if (fields[i][j])
				{
					if (i == 0 || vertical[i-1][j] == -1)
					{
						rightNodesNum++;
						vertical[i][j] = rightNodesNum;
					}
					else
					{
						vertical[i][j] = vertical[i-1][j];
					}
					if (j == 0 || horizontal[i][j-1] == -1)
					{
						leftNodesNum++;
						horizontal[i][j] = leftNodesNum;
					}
					else
					{
						horizontal[i][j] = horizontal[i][j-1];
					}
				}
			}
		}
		BipartieGraph bipartieGraph(++leftNodesNum, ++rightNodesNum);

		for (i=0; i<R; i++)
		{
			for (j=0; j<C; j++)
			{
				if (fields[i][j])
				{
					bipartieGraph.addEdge(horizontal[i][j], vertical[i][j]);
				}
			}
		}
		cout << bipartieGraph.maxMatch() << endl;

	}
	return 0;
}




