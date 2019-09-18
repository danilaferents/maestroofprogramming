#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <set> 
#include <map> 
#include <math.h> 
#include <cstdio>
#include <queue>
long long mod=4294967296;
void recursion(map<long long, long long> &helpmap,long long i)
{
	auto I = helpmap.find(i);
	if(I == helpmap.end())
	{
		if ((i)%2 == 1)
		{
			if ((i!=1) && (i!=2))
			{
				recursion(helpmap,6*(i)/7);
				recursion(helpmap,2*(i)/3);
				helpmap[i]=(helpmap[6*(i)/7]+helpmap[2*(i)/3])%mod;
			}
		}
		if ((i)%2 == 0)
		{
			if ((i!=1) && (i!=2))
			{
				recursion(helpmap,i-1);
				recursion(helpmap,i-3);
				helpmap[i]=(helpmap[i-1]+helpmap[i-3])%mod;
			}
		}
	}
}
int main()
{
	long long n=0;
	cin>>n;
	std::map<long long,long long> function;
	function[1]=1;
	function[2]=1;
	recursion(function,n);
	cout<<function[n];
	return 0;
}