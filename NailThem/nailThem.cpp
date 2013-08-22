/*
 * nailThem.cpp
 * SPOJ 661 Nail Them
 *  Created on: Aug 21, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Plank
{
	int s;
	int e;

	bool operator < (const Plank &rhs) const
	{
		return this->e < rhs.e;
	}
};

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;
		vector<Plank> planks(n);
		int i = 0;
		for (i=0; i<n; i++)
		{
			int s, e;
			cin >> s >> e;
			planks[i].s = s;
			planks[i].e = e;
		}
		int last = -1;
		int cnt = 0;
		sort(planks.begin(), planks.end());
		for (i=0; i<n; i++)
		{
			if (planks[i].s > last)
			{
				cnt++;
				last = planks[i].e;
			}
		}
		cout << cnt << endl;
	}
}




