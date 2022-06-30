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
int main()
{
	int n=0;
	cin>>n;
	std::map<long long,long long> function;
	long long help;
	queue<long long> Queue;
	Queue.push(n);
	while (Queue.size()!=0)
	{
		long long help=Queue.front();
		function[help];
		Queue.pop();
		if ((help!=1) || (help!=2))
		{
			if (help%2 == 1)
			{
				long long help1=6*help/7,help2=2*help/3;
					if ((help1!=1 )&&(help2!=1 )&&(help1!=2 )&&(help2!=2 ))
					{
						Queue.push(help1);
						Queue.push(help2);
						function[help1];
						function[help2];
					}
			}
			if (help%2 == 0)
			{
					long long help1=help-1,help2=help-3;
					if ((help1!=1 )&&(help2!=1 )&&(help1!=2 )&&(help2!=2 ))
					{
						Queue.push(help1);
						Queue.push(help2);
						function[help1];
						function[help2];
					}
			}
		}
	}
	function[1]=1;
	function[2]=1;
	// for (auto &help:function)
	// {	
	// 		cout<<help.first<<" "<<help.second<<endl;
	// 	}
	
	long long mod=4294967296;
	for (auto &help:function)
	{	
		if ((help.first==1) || (help.first==2)) continue;
			if ((help.first)%2 == 1)
			{
				help.second=(function[(6*(help.first))/7] + function[(2*(help.first))/3])%mod;
				// cout<<"----"<<(6*(help.first))/7<<" "<<(2*(help.first))/3<<endl;
			}
			if ((help.first)%2 == 0)
			{
				help.second=(function[help.first-1] + function[help.first-3])%mod;
			}
			// cout<<"1 ";
			// cout<<help.first<<" "<<help.second<<endl;
	}
		 
	cout<<function[n];
	return 0;
}