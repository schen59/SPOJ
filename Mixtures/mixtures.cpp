/*
 * mixtures.cpp
 * SPOJ 345 Mixtures
 *  Created on: Aug 11, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int colors[100][100];
int smokes[100][100];
int n = 0;

int solve(int i, int j)
{
	if (smokes[i][j] == -1)
	{
		smokes[i][j] = INT_MAX;
		int point = i;
		for (int k=i; k<j; k++)
		{
			int left = solve(i, k);
			int right = solve(k+1, j);
			int smoke = left + right + colors[i][k] * colors[k+1][j];
			if (smoke < smokes[i][j])
			{
				smokes[i][j] = smoke;
				point = k;
			}
		}
		colors[i][j] = (colors[i][point] + colors[point+1][j]) % 100;
	}
	return smokes[i][j];
}

int main()
{
	while (cin >> n)
	{
		memset(smokes, -1, sizeof(smokes));
		for (int i=0; i<n; i++)
		{
			cin >> colors[i][i];
			smokes[i][i] = 0;
		}
		cout << solve(0, n-1) << endl;
	}

	return 0;
}




