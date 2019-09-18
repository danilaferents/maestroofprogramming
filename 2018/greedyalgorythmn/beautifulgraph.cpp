#include <iostream>
#include <vector>
#include <map>
#include <set>
#include<algorithm>
using namespace std;
void dfs(map<int,set<int>> &reddots,vector<vector<char>> &array,int i,int size,int curri,set<int> &visited)
{
	//if (curri==i) return;

	for (int j = 0; j < size; ++j)
	{
		if ((array[curri][j]!='0') && (visited.find(j) == visited.end())) 
		{
				reddots[i].insert(j);
				visited.insert(j);
				dfs(reddots,array,i,size,j,visited);
		}
	}
}
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int size,sizered;
	cin>>size;
	vector<vector<char>> array(size);
	map<int,set<int>> reddots;
	set<int> visited;
	set<int> setofothers;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			char help;
			cin>>help;
			array[i].push_back(help);
		}
	}
	cin>>sizered;
	int helpdot;
	for (int i = 0; i < sizered; ++i)
	{
		cin>>helpdot;
		visited.insert(helpdot);
		dfs(reddots,array,helpdot,size,helpdot,visited);
	}
	for (int i = 0; i < size; ++i)
	{
		if(visited.find(i)==visited.end())
		{
			setofothers.insert(i);
		}
	}
	//cout
	// for(auto i:reddots)
	// {
	// 	cout<<i.first<<endl;
	// 	for(auto j:i.second)
	// 		cout<<j<<" ";
	// 	cout<<endl;
	// }
	// for (auto i:setofothers)
	// {
	// 	cout<<i<<" ";
	// }
	int summ=0;
	//очень странная ошибка вылезала если сделать max=-1 спросить надо 
	int current=-1,max=0;
	for(auto i:reddots)
	{
		for (auto j:i.second)
		{
			if(array[i.first][j]=='0') 
			{
				summ++;
				array[i.first][j]='1';
				array[j][i.first]='1';
			}
			for (auto k:i.second)
			{
				if (k!=j)
				{
					if(array[j][k]=='0') 
					{	
						summ++;
						array[j][k]='1';
						array[k][j]='1';
					}
				}
			}
		}
		// cout<<(i.second).size()<<max<<endl;
		if((((i.second).size()) > max))
		{
			max=(i.second).size();
			current=i.first;
		}
		// cout<<summ<<" "<<endl;
	}
	if(current==-1)
	{
		for(auto i:setofothers)
			summ++;
	}
	for(auto i:reddots)
	{
		for (auto j:i.second)
		{
			for (auto k:i.second)
			{
				if (k!=j)
				{
					if(array[j][k]=='0') summ++;
					array[j][k]='1';
					array[k][j]='1';
				}
			}
		}
	}
	//можно оптимизировать поубирать неокторые if тк там всегда 0 будет 
	if (current!=-1)
	{
		if (setofothers.size()) summ+=setofothers.size(); //сначала забыл эту строчку и не прибавлял ребра с красной вершиной связанные 
		for (auto i:reddots[current])
		{
			for (auto j:setofothers)
			{
				if (i!=j)
				{
					if(array[i][j]=='0')
					{	
						summ++;
						array[i][j]='1';
						array[j][i]='1';
					}
				}
			}
		}
	}
	for (auto i:setofothers)
	{
		for (auto j:setofothers)
		{

			if (i!=j)
			{
				if(array[i][j]=='0') 
				{
						summ++;
						array[i][j]='1';
						array[j][i]='1';
				}
			}
		}
	}
	cout<<summ;
}