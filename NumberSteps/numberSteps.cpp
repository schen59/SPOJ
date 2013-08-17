/*
 * numberSteps.cpp
 * SPOJ 1112 Number Steps
 *  Created on: Aug 17, 2013
 *      Author: Sherwin
 */

#include <iostream>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if (x == y && x%2 == 0)
		{
			cout << x+y << endl;
		}
		else if (x==y && x%2 != 0)
		{
			cout << x+y-1 << endl;
		}
		else if (x-y == 2 && x%2 == 0)
		{
			cout << x+y << endl;
		}
		else if (x-y == 2 && x%2 != 0)
		{
			cout << x+y-1 << endl;
		}
		else
		{
			cout << "No Number" << endl;
		}
	}
	return 0;
}




