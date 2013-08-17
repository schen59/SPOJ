/*
 * theMoronicCowmpourter.cpp
 * SPOJ 739 The Moronic Cowmpourter
 *  Created on: Aug 16, 2013
 *      Author: Sherwin
 */

#include <iostream>
using namespace std;

void negBase2(int n)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		if (n > 0)
		{
			negBase2(n / (-2));
			cout << n % -2;
		}
		else
		{
			if (n % (-2) == 0)
			{
				negBase2(n / (-2));
				cout << 0;
			}
			else
			{
				negBase2(n / (-2) + 1);
				cout << 1;
			}
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	if (n == 0)
		cout << 0;
	else
	    negBase2(n);
	cout << endl;
	return 0;
}




