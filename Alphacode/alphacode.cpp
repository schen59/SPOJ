
/*
 * alphacode.cpp
 * SPOJ 394 Alphacode
 *  Created on: Aug 11, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s;
int memo[5000];
int solve(int n)
{
	if (n == s.length()-1 || n == s.length())
		return 1;
	if (memo[n] == -1)
	{
		string code = s.substr(n, 2);
		if (code == "10" || code == "20")
		{
			memo[n] = solve(n+2);
		}
		else if (code[0] == '0')
		{
			memo[n] = 0;
		}
		else if (code <= "26")
		{
			memo[n] = solve(n+1) + solve(n+2);
		}
		else
		{
			memo[n] = solve(n+1);
		}
	}
	return memo[n];
}

int main()
{
	while (cin >> s && s!="0")
	{
		memset(memo, -1, sizeof(memo));

		cout << solve(0) << endl;

	}
	return 0;
}







