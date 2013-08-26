/*
 * permutations.cpp
 * SPOJ 64 Permutations
 *  Created on: Aug 24, 2013
 *      Author: Sherwin
 */

#include <iostream>
using namespace std;

const int N = 13;
int dp[N][N*N];

int solve()
{
	dp[0][0] = 1;
	for (int i=1; i<N; i++)
	{
		for (int j=0; j<=i; j++)
		{
			for (int x=0; x+j < N*N; x++)
			{
				dp[i][x+j] += dp[i-1][x];
			}
		}
	}
}

int main()
{
	int t = 0;
	int n, k;
	solve();
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cout << dp[n-1][k] << endl;
	}
	return 0;
}




