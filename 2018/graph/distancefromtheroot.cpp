#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
#include <set>
#include <queue>
map<int,int> distances;
map<int,set<int> > graph; 
vector<bool> visited;
void  bfs(int i)
{
	queue<int> order;
	order.push(i);
	visited[i]=true;
	while(order.size() !=0)
	{
		int help=order.front();
		order.pop();
		for (auto j:graph[help])
		{
			if (!visited[j])
			{
				order.push(j);
				visited[j]=true;
				distances[j]=distances[help]+1;
			}
		}
	}
}
int main()
{
	int numbertops=0;
	cin>>numbertops;
	int first,second;
	for (int i = 0; i < (numbertops-1); ++i)
	{
		cin>>first;
		graph[first].insert(i+2);
		graph[i+2].insert(first);
	}
	for (int i = 0; i <= numbertops; ++i)
	{
		visited.push_back(false);
	}
	distances[1]=0;
	bfs(1);
	int count=0,max=-1;
	for (auto i:distances)
	{
		if ((i.second) == max) 
		{
			count+=1;
		}
		if ((i.second) > max) 
		{
			max=i.second;
			count=1;
		}
	}
	cout<<max<<endl<<count<<endl;
	for (auto i:distances)
	{
		if ((i.second) == max) 
		{
			cout<<i.first<<" ";
		}
	}
}