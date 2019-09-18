#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
#include <climits>
void  deikstra(int whichtop, const vector < vector <int> > &graph,int numbertops,vector<int> &distances)
{
	int ourtop=whichtop;
	priority_queue <int> queue;
	distances[whichtop]=0;
	queue.push(whichtop);
	while(!queue.empty())
	{
		int current=queue.top();
		queue.pop();
		for (int i = 0; i < graph[current].size(); ++i)
		{
			int now=graph[current][i];
			if(distances[now] > (distances[current] + 1))
			{
				distances[now]=distances[current] + 1;
				queue.push(now);
			}
		}
	}
	for (int i=1;i<=numbertops;i++)
	{
		if (distances[i] == INT_MAX) distances[i]=-1;
	}
}
int main()
{
	
	int numbertops=0,whichtop,numberribs;
	cin>>numbertops>>whichtop>>numberribs;
	int first,second;
	vector < vector <int> > graph(numbertops+1);
	vector<int> distances (numbertops+1,INT_MAX);
	for (int i = 0; i < (numberribs); ++i)
	{
		cin>>first>>second;
		graph[second].push_back(first);//просто инвертируем подачу в граф
	}
	deikstra(whichtop,graph,numbertops,distances);
	for (int i=1;i<=numbertops;i++)
	{
		cout<<distances[i]<<" ";
	}
}