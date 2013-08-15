/*
 * toAndFro.cpp
 * SPOJ 400 To and Fro
 *  Created on: Aug 13, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cols = 0;
	int rows = 0;
	while (cin >> cols && cols != 0)
	{
		string code;
		cin >> code;
		rows = code.length() / cols;
		char *encode = new char[rows*cols];
		int i, j, k;
		for (k=0; k<code.length(); k++)
		{
			i = k / cols;
			j = k % cols;
			if (i%2 != 0)
			{
				j = cols - j - 1;
			}
			encode[j*rows + i] = code[k];
		}
		for (i=0; i<rows*cols; i++)
		{
			cout << encode[i];
		}
		cout << endl;
	}
	return 0;
}





