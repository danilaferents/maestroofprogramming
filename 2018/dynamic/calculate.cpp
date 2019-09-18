#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	int N[n+1];
	vector<int> order;
	N[1]=0;
	if (n==1) 
	{
			cout<<"0"<<endl;
			cout<<"1";
			return 0;
	}
	if (n==2) 
	{
			cout<<"1"<<endl;
			cout<<"1 2";
			return 0;
	//просто берем минимум из предыдущих ячеек
	for (int i=2;i<=n;i++)
	{
		N[i]=N[i-1]+1;
		if (i%2==0) if (N[i] > (N[i/2]+1)) N[i]=N[i/2]+1;
		if (i%3==0) if (N[i] > (N[i/3]+1)) N[i]=N[i/3]+1;
	}
	order.push_back(n);
	int i=n;
    //прогоняем  минимумы чтобы понять что мы взяли 
	while(i>1)
	{
		if (N[i]==(N[i-1]+1) )
		{
			order.push_back(i-1);
			i--;
			continue;
		}
		if (((i%2)==0) && (N[i]==N[i/2]+1))
		{
			order.push_back(i/2);
			i/=2;
			continue;
		}
		order.push_back(i/3);
		i/=3;
	}

	cout<<order.size()-1<<endl;

	for (int i=order.size()-1;i >= 0; i--)
	{
		cout<<order[i]<<" ";
	}
	return 0;
}
