/*
 * pocketMoney.cpp
 * SPOJ 364 Pocket Money
 *  Created on: Aug 22, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <cstring>
using namespace std;

#define max(a, b) ((a>b) ? a : b)
#define min(a, b) ((a<b) ? a : b)
int memoMax[100][100];
int memoMin[100][100];
int numbers[100];
char ops[100];
int n = 0;

int solveMax(int i, int j)
{
	if (i == j)
	{
		return numbers[i];
	}
	int k;
	if (memoMax[i][j] == -1)
	{
		memoMax[i][j] = INT_MIN;
		for (k=i; k<j; k++)
		{
			int tmp = ops[k] == '*' ? solveMax(i, k)*solveMax(k+1, j) : solveMax(i, k) + solveMax(k+1, j);
			memoMax[i][j] = max(memoMax[i][j], tmp);
		}
	}
	return memoMax[i][j];
}

int solveMin(int i, int j)
{
	if (i == j)
	{
		return numbers[i];
	}
	int k;
	if (memoMin[i][j] == -1)
	{
		memoMin[i][j] = INT_MAX;
		for (k=i; k<j; k++)
		{
			int tmp = ops[k] == '*' ? solveMin(i, k)*solveMin(k+1, j) : solveMin(i, k) + solveMin(k+1, j);
			memoMin[i][j] = min(memoMin[i][j], tmp);
		}
	}
	return memoMin[i][j];
}

int main()
{
	int k = 0;
	cin >> k;
	while (k--)
	{
		string expression;
		cin >> expression;
		int i = 0;
		int j = 0;
		int k = 0;
		for (i=0; i<expression.length(); i++)
		{
			if (i % 2 == 0)
			{
			    numbers[j++] = expression[i] - '0';
			}
			else
			{
				ops[k++] = expression[i];
			}
		}
		n = j;
		memset(memoMax, -1, sizeof(memoMax));
		memset(memoMin, -1, sizeof(memoMin));
		int maxResult = solveMax(0, n-1);
		int minResult = solveMin(0, n-1);
		cout << maxResult << " " << minResult << endl;
	}
	return 0;
}




