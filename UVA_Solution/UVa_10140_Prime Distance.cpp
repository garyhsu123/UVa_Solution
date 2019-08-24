#define _CRT_SECURE_NO_WARNINGS
#define PrimeCountMax 46343
#define Diff 1000001
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>  
#include <string.h> 
#include <limits.h>
using namespace std;

bool bPrime[PrimeCountMax];
long long int Primes[PrimeCountMax];
int primeNum = 0;
bool bDetechPrimInRange[Diff];
long long int primeInRange[Diff];
void establishPrimeTable()
{
	
	memset(bPrime, 1, PrimeCountMax);
	for (long long int i = 2; i < PrimeCountMax; ++i)
	{
		if (true == bPrime[i])
		{
			Primes[primeNum++] = i;
			for (long long int j = i; j < PrimeCountMax; j += i)
			{
				bPrime[j] = false;
			}
		}
	}
}


void getPrimeInRange(long long int L, long long int U, long long int * primeInRange,int &primeInRangeCount)
{
	
	
	memset(bDetechPrimInRange, 1, Diff);
	for (int j = 0; j < primeNum; ++j)
	{
		if ( Primes[j] > U )break;
		long long int times = (L - 1) / Primes[j] + 1;
		if (times <2)times = 2;
		for (long long int i = Primes[j] * times; i <= U; i+= Primes[j])
		{
			bDetechPrimInRange[i - L] = false;
		}
	}

	for (long long int i = L ; i <= U; ++i)
	{
		
		if (bDetechPrimInRange[i - L] && i != 1)
		{
	
			primeInRange[primeInRangeCount++] = i;

		}
	}
}

void getCloseAndMostDis(long long int * primeInRange, int &primeInRangeCount
	, long int&closeX, long int&closeY, long int&MostX, long int&MostY)
{
	long int max = 1 << 31 ;
	long int min = 1 << 31 - 1;
	for (int i = 0; i < primeInRangeCount - 1; ++i)
	{
		long int dis = primeInRange[i + 1] - primeInRange[i];
		if (dis < min)
		{
			closeX = primeInRange[i];
			closeY = primeInRange[i + 1];
			min = dis;
		}
		if (dis > max)
		{
			MostX = primeInRange[i];
			MostY = primeInRange[i + 1];
			max = dis;
		}

	}
}
/*
int main()
{
	establishPrimeTable();
	long long int L, U;
	while (scanf("%lld%lld", &L, &U) == 1)
	{

		int primeInRangeNum = 0;
		getPrimeInRange(L,U,primeInRange, primeInRangeNum);
		
		if (primeInRangeNum <= 1)printf("There are no adjacent primes.\n");
		else
		{
			long int closeX, closeY, MostX, MostY;
			getCloseAndMostDis(primeInRange, primeInRangeNum, closeX, closeY, MostX, MostY);
			printf("%d,%d are closest, %d,%d are most distant.\n", closeX, closeY, MostX, MostY);
		}
	}

	
	return 0;
}
*/



/*
Sample Input:
2 17
14 17
Sample Output:
2,3 are closest, 7,11 are most distant.
There are no adjacent primes.

*/