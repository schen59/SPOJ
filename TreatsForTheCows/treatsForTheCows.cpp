/*
 * treatsForTheCows.cpp
 * SPOJ 740 Treats For The Cows
 *  Created on: Aug 15, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <cstring>
using namespace std;

#define max(a, b) ((a>b) ? a : b)
int v[2000];
int m[2000][2000];
int main()
{
	int N = 0;
	cin >> N;
	int i, j;
	for (i=0; i<N; i++)
	{
		cin >> v[i];
		m[i][i] = v[i] * N;
	}
	for (int a=N-1, l=1; l<N; a--, l++)
	{
		for (int s=0, e=s+l; e<N; s++, e++)
		{
			m[s][e] = max(v[s]*a + m[s+1][e], v[e]*a + m[s][e-1]);
		}
	}
	cout << m[0][N-1] << endl;
	return 0;
}



