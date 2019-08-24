#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>  
using namespace std;

string Perfection_Number_Examine(int num)
{
	if (num == 1)return "DEFICIENT";
	//printf("num = %d\n",num);
	int sum = 1;
	int sqrt_N = sqrtf(num);
	//printf("sqrt = %d\n", sqrt_N);
	for (int factor1 = 2; factor1 <= sqrt_N; factor1++)
	{
		
		if ((num % factor1) == 0)
		{
			int factor2 = num / factor1;		
			if (factor1 == factor2) { sum += factor1; break; }		
			sum = sum + factor1 + factor2;
		}
	}
	//printf("sum = %d\n", sum);
	if (sum < num)
		return "DEFICIENT";
	else if (sum > num)
		return "ABUNDANT";
	else
		return "PERFECT";
}
/*
int main()
{
	string input;
	getline(cin,input);
	//cout << input << endl;
	stringstream sst;
	sst << input;
	cout<<"PERFECTION OUTPUT"<<endl;
	while (true)
	{
		int number;
		sst >> number;
		if (sst.fail())break;
		if (number == 0)break;
		//cout << number << endl;
		printf("%5d  %s\n", number, Perfection_Number_Examine(number).c_str());
	}
	cout << "END OF OUTPUT" << endl << endl;
	//system("pause");
	return 0;
}*/

/*
Sample Input:
15 28 6 56 60000 22 496 0
Sample Output:
PERFECTION OUTPUT
15 DEFICIENT
28 PERFECT
6 PERFECT
56 ABUNDANT
60000 ABUNDANT
22 DEFICIENT
496 PERFECT
END OF OUTPUT

*/