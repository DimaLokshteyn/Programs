#include "stdafx.h"
#include <iostream>

using namespace std;

int lab[7][8] =
{ { 9,9,9,9,9,0,9,9 },
{ 9,0,0,0,0,0,0,9 },
{ 9,0,0,9,9,9,0,9 },
{ 9,0,9,9,0,9,0,9 },
{ 9,0,0,0,0,9,9,9 },
{ 9,9,0,9,0,9,0,9 },
{ 9,9,0,9,9,9,9,9 } };
int n = 7, m = 8;

void FindExitSimple()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][0] == 0) lab[i][0] = 4;
			if (lab[i][7] == 0) lab[i][7] = 6;
			if (lab[0][j] == 0) lab[0][j] = 8;
			if (lab[6][j] == 0) lab[6][j] = 2;
		}
	}
	for (int k = 0; k <= (n - 2)*(m - 2); k++)
	{
		bool flag = false;
		for (int i = 1; i <= n - 1; i++)
		{
			for (int j = 1; j <= m - 1; j++)
			{
				if (lab[i][j] == 0)
				{
					if ((lab[i][j + 1] != 9) && (lab[i][j + 1] != 0))
					{
						lab[i][j] = 6;
						flag = true;
					}
					else
					{
						if ((lab[i - 1][j] != 9) && (lab[i - 1][j] != 0))
						{
							lab[i][j] = 8;
							flag = true;
						}
						else
						{
							if ((lab[i][j - 1] != 9) && (lab[i][j - 1] != 0))
							{
								lab[i][j] = 4;
								flag = true;
							}
							else
							{
								if ((lab[i + 1][j] != 9) && (lab[i + 1][j] != 0))
								{
									lab[i][j] = 2;
									flag = true;
								}
							}
						}
					}
				}
			}
		}
		if (!flag)
			break;
	}

}
void BackTracking(int i, int j)
{
	int x1, y1;
	x1 = i; y1 = j;
	do
	{
		if (j + 1 < m)
		{
			if (lab[i][j + 1] == 0)
			{
				lab[i][j + 1] = 3;
				j = j + 1;
				continue;
			}
		}
		if (i - 1 >= 0)
		{
			if (lab[i - 1][j] == 0)
			{
				lab[i - 1][j] = 4;
				i = i - 1;
				continue;
			}
		}
		if (j - 1 >= 0)
		{
			if (lab[i][j - 1] == 0)
			{
				lab[i][j - 1] = 1;
				j = j - 1;
				continue;
			}
		}
		if (i + 1 < n)
		{
			if (lab[i + 1][j] == 0)
			{
				lab[i + 1][j] = 2;
				i = i + 1;
				continue;
			}
		}
		{       if (lab[i][j] == 4) j = j + 1;
		else if (lab[i][j] == 2) i = i - 1;
		else if (lab[i][j] == 6) j = j - 1;
		else if (lab[i][j] == 8) i = i + 1;
		}
	} while (i != y1 || j != x1);
}
void FindExitBacktracking()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][0] == 0)
			{
				lab[i][0] = 4;
				BackTracking(i, 0);
			}
			if (lab[i][m-1] == 0)
			{
				lab[i][m-1] = 6;
				BackTracking(i, n - 1);
			}
			if (lab[0][j] == 0)
			{
				lab[0][j] = 8;
				BackTracking(0, j);
			}
			if (lab[n-1][j] == 0)
			{
				lab[n-1][j] = 2;
				BackTracking(n - 1, j);
			}
		}
	}
}

void ShowExit()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (lab[i][j] == 0) cout << '0';
			else if (lab[i][j] == 9) cout << '#';
			else if (lab[i][j] == 6) cout << '>';
			else if (lab[i][j] == 8) cout << '^';
			else if (lab[i][j] == 4) cout << '<';
			else if (lab[i][j] == 2) cout << 'v';
		}
		cout << endl;
	}
	cout << endl;
}


void main()
{
	ShowExit();
	FindExitSimple();
	ShowExit();
	//ShowExit();
	//FindExitBacktracking();
	//cout << endl;
	//ShowExit();
	system("pause");
}

