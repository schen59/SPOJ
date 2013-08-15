/*
 * hangover.cpp
 * SPOJ 902
 *  Created on: Aug 14, 2013
 *      Author: Sherwin
 */

#include <iostream>
using namespace std;

int main()
{
	double c = 0.0;
	while (cin >> c && c > 0)
	{
		int i = 2;
		int cards = 1;
		double length = 0.5;
		while (length < c)
		{
			i++;
			length += 1.0/i;
			cards++;
		}
		cout << cards << " card(s)" << endl;
	}
	return 0;
}



