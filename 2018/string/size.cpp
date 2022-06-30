#include<cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;
int main()
{
	map<char,int> chars;
	for (char i = 'a'; i < 'z'; ++i)
	{
		chars[i]=0;
	}
	string ourstring;
	cin>>ourstring;
	for (char j:ourstring)
	{
		chars[j]++;
	}
	int maxint=0;
	char maxchar;
	for (auto i:chars)
	{
		if(maxint < i.second)
		{
			maxint = i.second;
			maxchar = i.first;
		}
	}
	cout<<maxchar;
}