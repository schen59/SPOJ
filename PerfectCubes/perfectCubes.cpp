/*
 * perfectCubes.cpp
 * SPOJ 867 Hangover
 *  Created on: Aug 14, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> cubes(101);
	vector<int>::iterator it;
	int i = 0;
	for (i=1; i<=100; i++)
	{
		cubes[i] = i*i*i;
	}
	for (int a=2; a<=100; a++)
	{
		for (int b=2; b<a; b++)
		{
			for (int c=b+1; c<a; c++)
			{
				int sum = cubes[b] + cubes[c];
				sum = cubes[a] - sum;
				if (binary_search(cubes.begin()+1, cubes.end(), sum))
				{
					it = lower_bound(cubes.begin()+1, cubes.end(), sum);
					int d = (int)(it - cubes.begin());
					if (d < c)
						continue;
					vector<int> triple(3);
					triple[0] = b;
					triple[1] = c;
					triple[2] = d;
					sort(triple.begin(), triple.end());
					cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
				}
			}
		}
	}
	return 0;
}




