#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
	long long helpint,leadermax[102],n;
	cin>>n>>leadermax[1];
	leadermax[0]=0;
	if (n<2) 
	{
			cout<<leadermax[1];
			return 0;
	}
	for (int i=2;i<=n;i++)
	{
		cin>>helpint;
		leadermax[i]=std::max(leadermax[i-1],leadermax[i-2]) + helpint;
	}
	cout<<leadermax[n];
	return 0;
}