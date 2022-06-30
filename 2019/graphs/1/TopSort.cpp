using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
bool dfs(int v, vector<int> &sort, vector<vector<int>> &graph, vector<char> &used) 
{
	used[v] = '1';
	for(int u:graph[v]) 
	{
		if (used[u]=='0') {
			if (dfs(u, sort, graph, used)) return true;
		} else if (used[u] == '1') {
			return true;
		}
	}
	sort.push_back(v);
	used[v] = '2';
	return false;
}
int main() 
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> graph(n);
	for(int i = 0; i < m; i++) 
	{
		int start, end;
		std::cin>>start>>end;
		graph[start - 1].push_back(end - 1);	
	} 
	vector<char> color(n, '0');
	vector<int> sort;
	int flag = false;
	for(int i = 0;i < n; i++) 
	{
		if (color[i] == '0') {
			if (dfs(i, sort, graph, color)){
			flag = true;
			break;
		}
		}
	}
	if (flag) {
		std::cout<<"-1";
	} else {
		reverse(sort.begin(), sort.end());
		for(int i=0; i< sort.size(); i++) 
		{
			std::cout<<sort[i] + 1<<" ";
		}
	}
}