#include <iostream>
#include <vector>
#include <cstdio>
#include<climits>
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	long long helpside=0,tetrahedronnumber=0;
	std::vector<int> maxnumbers;
	for (int i=0;i<=n;i++)
	{
		maxnumbers.push_back(INT_MAX);
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0; ;j++)
		{
			helpside+=j;
			tetrahedronnumber+=helpside;
			if (i>=tetrahedronnumber) maxnumbers[i]=min(maxnumbers[i],maxnumbers[i- tetrahedronnumber]);
			else break;
		}
		helpside=0;
		tetrahedronnumber=0;
	}
	return 0;
}