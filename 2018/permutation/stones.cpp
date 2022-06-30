#include<climits>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int minsumm=INT_MAX;
int array1[20];
void recursion(int i,long long summ1,long long summ2,int n)
{
	if(i==n)
	{
		if (abs(summ1 - summ2) < minsumm)
		{
			minsumm=abs(summ1-summ2);
		}
		return;
	}
	recursion(i+1,summ1+array1[i],summ2,n);
	recursion(i+1,summ1,summ2+array1[i],n);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>array1[i];
	}
	recursion(0,0,0,n);
	cout<<minsumm;
}