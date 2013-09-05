/*
 * iKeyboard.cpp
 * SPOJ 14 I-Keyboard
 *  Created on: Sep 4, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <string>
using namespace std;

int M[95][95];
int P[95][95];
int K = 0;
int L = 0;
int F[95];
string keys;
string letters;

void solve()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i=0; i<L; i++)
	{
		P[i][0] = 0;
		if (i == 0)
		{
			M[i][0] = F[i];
		}
		else
		{
			M[i][0] = M[i-1][0] + F[i]*(i+1);
		}
	}

	for (j=1; j<K; j++)
	{
		for (i=0; i<L; i++)
		{
			if (M[i][j-1] < 1023456789)
			{
				int cur = 0;
			    for (k=i+1; k<L; k++)
			    {
				    cur += F[k] * (k-i);
				    if (M[i][j-1] + cur < M[k][j])
				    {
					    M[k][j] = M[i][j-1] + cur;
					    P[k][j] = i+1;
				    }
			    }
			}
		}
	}

}

void printKeyboard(int k, int l)
{
	if (k < 0)
	{
		return;
	}
	printKeyboard(k-1, P[l][k]-1);
	cout << keys[k] << ": ";
	for (int i=P[l][k]; i<=l; i++)
	{
		cout << letters[i];
	}
	cout << endl;
}

int main()
{
	int T = 0;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		int i, j;
		cin >> K >> L >> keys >> letters;
		for (i=0; i<L; i++)
		{
			cin >> F[i];
		}
		for (int i=0; i<L; i++)
		{
			for (int j=0; j<K; j++)
			{
				M[i][j] = 1023456789;
			}
		}
		solve();
		cout << "Keypad #" << t << ":" << endl;

		printKeyboard(K-1, L-1);
	}
	return 0;
}
