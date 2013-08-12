/*
 * alphaCentauriTennis.cpp
 * SPOJ 359 Alpha Centauri Tennis
 *  Created on: Aug 11, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		string s;
		cin >> n >> s;
		cout << s[s.length()-1] << endl;
	}
	return 0;
}



