#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
#include <set>
#include <queue>

int main()
{

	int numbertops,numberribs;
	cin>>numbertops>>numberribs;
	// map<int,set<int> > graph; 
	int array[numbertops][numbertops];
	for (int i = 0; i < numbertops; ++i)
	{
		for (int j = 0; j < numbertops; ++j)
		{
			array[i][j]=0;
		}
	}
	for (int i = 0; i < numberribs; ++i)
	{
		int first,second;
		cin>>first>>second;
		// cout<<first-1<<" "<< second-1;
		// cout<<endl;
		// if (second > first) graph[first].insert(second);
		// if (second < first) graph[second].insert(first);
		array[first-1][second-1]=1;
		array[second-1][first-1]=1;
	}
	// cout<<endl;
	// for (int i = 0; i < numbertops; i++)
	// {
	// 	for (int j = 0; j < numbertops; j++)
	// 	{
	// 		cout<<array[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	long long summ=0;
	// for (const auto &a:graph)
	// 	for(const auto &b:graph[a.first])
	// 		for(const auto &c:graph[b])
	// 		{
	// 			if (array[a.first][c]==1) summ+=1;
	// 		}
	for (int i = 0; i < numbertops; ++i)
	{
		for(int j=i+1;j < numbertops;j++)
		{
			if (!array[i][j]) continue;
			for (int k=j+1;k<numbertops;k++)
			{
				if(array[j][k] && array[i][k]) summ+=1;
			}
		}
	}
	cout<<summ;
}