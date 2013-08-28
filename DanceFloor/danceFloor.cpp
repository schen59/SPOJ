/*
 * danceFloor.cpp
 * SPOJ 98 Dance Floor
 *  Created on: Aug 26, 2013
 *      Author: Sherwin
 */

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;

int cols = 0;
int rows = 0;
bool danceFloor[15][15];
bool preDanceFloor[15][15];
vector<pair<int, int> > cur_steps, min_steps;
int min_step = INT_MAX;
int cur_step = 0;
bool solved = false;


void danceTile(int i, int j)
{
	danceFloor[i][j] = !danceFloor[i][j];
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	for (int k=0; k<4; k++)
	{
		int x = j + dx[k];
		int y = i + dy[k];
		if (x>=0 && x<cols && y>=0 && y<rows)
		{
			danceFloor[y][x] = !danceFloor[y][x];
		}
	}
}

bool isValidDance()
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			if (!danceFloor[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void danceOtherLines()
{
	int i, j;
	for (i=0; i<rows-1; i++)
	{
		for (j=0; j<cols; j++)
		{
			if (!danceFloor[i][j])
			{
				cur_step++;
				cur_steps.push_back(pair<int, int>(i+1, j));
				danceTile(i+1, j);
			}
		}
	}
	if (isValidDance())
	{
		solved = true;
		if (cur_step < min_step)
		{
			min_step = cur_step;
			min_steps = cur_steps;
		}
	}
}

void danceFirstLine()
{
	for (int i=0; i<(1<<cols); i++)
	{
		memcpy(danceFloor, preDanceFloor, sizeof(danceFloor));
		cur_steps.clear();
		cur_step = 0;
		for (int j=0; j<cols; j++)
		{
			if (i & (1<<j))
			{
				danceTile(0, j);
				cur_steps.push_back(pair<int, int>(0, j));
				cur_step++;
			}
		}
	    danceOtherLines();
	}
}

int main()
{
	while (cin >> cols >> rows && cols!=0 && rows!= 0)
	{
		min_step = INT_MAX;
		cur_step = 0;
		min_steps.clear();
		cur_steps.clear();
		solved = false;
	    int i = 0;
	    int j = 0;
	    for (i=0; i<rows; i++)
	    {
	    	for (j=0; j<cols; j++)
	    	{
	    	    char c;
	    	    cin >> c;
		        danceFloor[i][j] = (c == '1');
	    	}
	    }
	    memcpy(preDanceFloor, danceFloor, sizeof(danceFloor));
	    danceFirstLine();
	    if (solved)
	    {
	        cout << min_step << endl;
	        for (vector<pair<int, int> >::iterator it=min_steps.begin(); it!=min_steps.end(); it++)
	        {
	    	    cout << it->second+1 << " " << it->first+1 << endl;
	        }
	    }
	    else
	    {
	    	cout << -1 << endl;
	    }
	}
	return 0;
}



