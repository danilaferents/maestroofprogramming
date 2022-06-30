#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
#include <set>
map<int,set<int> > graph; 
int dfs(int i,vector<bool> &visited)
{
	int countvisited=1;
	visited[i]=true;
	for (auto j:graph[i])
	{
		if (!visited[j])
		{
			countvisited+=dfs(j,visited);
		}
	}
	return countvisited;
}
int main()
{
	int numbertops=0,numberribs;
	cin>>numbertops>>numberribs;
	vector<bool> visited;
	int first,second;
	for (int i = 0; i < numberribs; ++i)
	{
		cin>>first>>second;
		graph[first].insert(second);
		graph[second].insert(first);
	}
	for (int i = 0; i <= numbertops; ++i)
	{
		visited.push_back(false);
	}
	if((dfs(1,visited)) == numbertops) cout<<"YES";
	else cout<<"NO";
}