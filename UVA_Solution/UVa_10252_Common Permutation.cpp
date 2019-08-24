#define _CRT_SECURE_NO_WARNINGS
#define Min(a,b) (a>b)?b:a
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>  
#include <vector>
using namespace std;


string compareTwoDict(vector<int> dict1, vector<int> dict2)
{
	string ret = "";
	for (int i = 0; i < 26; ++i)
	{
		int count = Min(dict1[i], dict2[i]);
		char c = ('a' + i);
		//cout << c << endl;
		for (int j = 0; j < count; ++j)
		{
			char c = ('a' + i);
			
			ret += c;
		}
	}
	return ret;
}

vector<int> translate2Dict(string str)
{
	vector<int> stringStruc;
	stringStruc.resize(26, 0);
	for (int i = 0; i < str.size(); i++)
	{
		char temp_c = str[i];
		stringStruc[temp_c - 'a'] += 1;
	}
	return stringStruc;
}

/*
int main()
{
	vector<int> dict1, dict2;
	string str1, str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		dict1.clear();
		dict2.clear();
		dict1 = translate2Dict(str1);
		
		dict2 = translate2Dict(str2);
		cout<<compareTwoDict(dict1,dict2)<<endl;

	}



	return 0;
}*/


/*
Sample Input:
pretty
women
walking
down
the
street
Sample Output:
e
nw
et

*/