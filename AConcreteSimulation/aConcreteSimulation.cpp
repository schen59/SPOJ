/*
 * aConcreteSimulation.cpp
 * SPOJ 376 A Concrete Simulation
 *  Created on: Aug 10, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <cstring>
using namespace std;

int rows[1235];
int cols[5679];
int rev_rows[1235];
int rev_cols[5679];

void query(int x, int y)
{
	cout << (rows[x]-1) * 5678 + cols[y] << endl;
}

void write(int z)
{
	int x = (z-1)/5678 + 1;
	int y = (z-1)%5678 + 1;

	cout << rev_rows[x] << " " << rev_cols[y] << endl;
}

int main()
{
	char cmd;
	int x, y, z, r1, r2, c1, c2;
	for (x = 1; x<=1234; x++)
	{
		rows[x] = x;
		rev_rows[x] = x;
	}
	for (y=1; y<=5678; y++)
	{
		cols[y] = y;
		rev_cols[y] = y;
	}

	while (cin >> cmd)
	{
		switch (cmd)
		{
		case 'R':
			cin >> x >> y;
			r1 = rows[x];
			r2 = rows[y];
			rows[x] = r2;
			rows[y] = r1;
			rev_rows[r2] = x;
			rev_rows[r1] = y;
			break;
		case 'C':
			cin >> x >> y;
			c1 = cols[x];
			c2 = cols[y];
			cols[x] = c2;
			cols[y] = c1;
			rev_cols[c2] = x;
			rev_cols[c1] = y;
			break;
		case 'Q':
			cin >> x >> y;
			query(x, y);
			break;
		case 'W':
			cin >> z;
			write(z);
			break;
		}
	}
	return 0;
}



