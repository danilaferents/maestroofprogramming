
#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
int main()
{
	int n=0,help=0;
	cin>>n;
	int array[n][n];
	vector <pair<int,int> > graph;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>help;
			array[i][j]=help;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (array[i][j] == 1) 
				{
					if ((find(graph.begin(),graph.end(),make_pair(j+1,i+1)))==graph.end()) graph.push_back(make_pair(i+1,j+1));
				}
		}
	}
	for (auto i:graph)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}