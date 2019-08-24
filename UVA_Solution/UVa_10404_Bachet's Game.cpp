#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int n_stones, m_ways;
	
	while (scanf("%d %d",&n_stones,&m_ways)==2)
	{
		bool* dp = new bool[n_stones + 1];
		int* ways = new int[m_ways];
		memset(dp, 0, n_stones + 1);
		memset(ways, 0, m_ways);
		for (int i = 0; i < m_ways; i++)
		{
			scanf("%d", &ways[i]);
		}


		for (int i = 1; i <= n_stones; ++i)
		{
			for (int j = 0; j < m_ways; ++j)
			{
				if (i - ways[j] >= 0 && !dp[i - ways[j]])
				{
					dp[i] = true;
					break;
				}
			}
		}
		if (dp[n_stones])
			cout << "Stan wins" << endl;
		else
			cout << "Ollie wins" << endl;

		delete[] ways;
		delete[] dp;
	}


	return 0;
}

/*
Sample Input:
20 3 1 3 8
21 3 1 3 8
22 3 1 3 8
23 3 1 3 8
1000000 10 1 23 38 11 7 5 4 8 3 13
999996 10 1 23 38 11 7 5 4 8 3 13
Sample Output:
Stan wins
Stan wins
Ollie wins
Stan wins
Stan wins
Ollie wins

*/