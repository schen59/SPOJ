/*
 * jillRidesAgain.cpp
 * SPOJ 408 Jill Rides Again
 *  Created on: Aug 21, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	int b = 0;
	cin >> b;
	int i, j;
	for (i=1; i<=b; i++)
	{
		int s = 0;
		cin >> s;
		vector<int> accessment(s);
		int maxValue = INT_MIN;
		int start, end;
		int curValue = 0;
		int curStart=1, curEnd;
		for (j=1; j<s; j++)
		{
			cin >> accessment[j];
			curValue += accessment[j];
			if (curValue >= 0)
			{
				curEnd = j;
				if (curValue > maxValue)
				{
					maxValue = curValue;
					start = curStart;
					end = curEnd;
				}
				else if (curValue == maxValue)
				{
					if ((curEnd-curStart) > (end-start))
					{
						start = curStart;
						end = curEnd;
					}
				}
			}
			else
			{
				curValue = 0;
				curStart = j+1;
			}
		}
		if (maxValue > 0)
		{
			cout << "The nicest part of route "<< i << " is between stops " << start << " and " << end+1 << endl;
		}
		else
		{
			cout << "Route " << i << " has no nice parts" << endl;
		}
	}
	return 0;
}




