#include <iostream>
#include <stdio.h>
#include <sstream>
#include <limits.h>
#include <vector>
#include <set>
using namespace std;



vector<set<long long int> > getSet(vector<long long int> arr,long long int target)
{
	
	vector<set<long long int> > ans_pairs;
	int count = arr.size();
	for (int i = 0; i <= ((1 << count) - 1); ++i)
	{
		set<long long int> pairs;
		long long int sumOfcurPair = 0;
		for (int j = 0; j < count; ++j)
		{
			int cur_bit = (1 << j);
			if (i & cur_bit)
			{
				pairs.insert(arr[j]);
				sumOfcurPair += arr[j];
			}
		}

		if (sumOfcurPair == target)
		{
			//cout << i << endl;
			ans_pairs.push_back(pairs);
		}

	}
	return ans_pairs;
}

void printAns(vector<set<long long int> > arr)
{
	int count = arr.size();
	printf("%d subsets.\n", count);

	
	for (int i = 0; i < count; ++i)
	{	
		bool firstPrint = true;
		printf("{");
	
		for (set<long long int>::iterator j = arr[i].begin(); j != arr[i].end(); ++j)
		{
			
			if (firstPrint) {
				firstPrint = false;
				printf("%lld", *j);
			}
			else
				printf(" %lld", *j);
			
			
		}
		printf("}\n");
	}
	printf("\n");

}



bool bigger(set<long long int> a, set<long long int> b)
{
	
	if (a.size() > b.size())return true;
	else if (a.size() < b.size())return false;
	else{
		if (a > b)return true;
		else return false;

	}
	
	//return true;
}

void sortAns(vector<set<long long int> >& arr)
{
	for (int i = 0; i < arr.size() - 1; ++i)
	{
		for (int j = 0; j < arr.size() - i - 1; ++j)
		{
			//cout<< arr[j] << " " <<arr[j + 1] <<endl;
			if (bigger(arr[j], arr[j + 1]))
			{
				set<long long int> temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
/*
int main()
{

	string input;
	while (getline(cin, input))
	{
		if (input == ".")break;
		vector<int> answer;
		input = input.substr(1, input.size() - 1);
		stringstream sst;
		sst << input;
		vector<long long int> all_numbers;
		long long int sumOfnumbers = 0;
		while (true)
		{
			long long int num;
			sst >> num;
			if (sst.fail())break;
			sumOfnumbers += num;
			all_numbers.push_back(num);
		}
		//cout << sumOfnumbers << endl;
		//cout << all_numbers.size() << endl;
		if (sumOfnumbers % 2 != 0)
		{
			printf("No such subset\n\n");
		}
		else
		{
			//cout << sumOfnumbers / 2 << endl;
			vector<set<long long int> > ans_pairs;
			ans_pairs = getSet(all_numbers, sumOfnumbers / 2);
			if (ans_pairs.size() == 0)printf("No such subset\n\n");
			else {
				sortAns(ans_pairs);
				printAns(ans_pairs);
			}
			
		}
		

	}

	//system("pause");
	return 0;
}
*/
/*
Sample Input:
{1 2 3 4 5 6 7}
{1 3 5 7 12}
.
Sample Output:
8 subsets.
{1 6 7}
{2 5 7}
{3 4 7}
{3 5 6}
{1 2 4 7}
{1 2 5 6}
{1 3 4 6}
{2 3 4 5}

No such subset

*/