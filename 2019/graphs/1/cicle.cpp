using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
bool dfs(int v, vector<int> &p, vector<vector<int>> &graph, vector<char> &used, int &start, int &end) 
{
	used[v] = '1';
	for(int u:graph[v]) 
	{
		if (used[u]=='0') {
			if (dfs(u, p, graph, used, start, end)) 
			{	
				p[u] = v;
				return true;
			}
		} else if (used[u] == '1') {
			end = v;
			start = u;
			return true;
		}
	}
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
	vector<int> p(n);
	int start = -1, end; 
	p[0] = -1;
	for(int i = 0;i < n; i++) 
	{
		if (dfs(i, p, graph, color, start, end))	break;
	}
	if (start == -1) {
		std::cout<<"NO";
	} else {
		vector<int> trace;
		for(int v = end; v!=start; v = p[v]) 
		{
			trace.push_back(v);
		}
		trace.push_back(start);
		std::cout<<"YES"<<std::endl;
		reverse(trace.begin(), trace.end());
		for(int i = 0; i < trace.size(); i++) {
			std::cout<<trace[i] + 1<<" ";
		}
	}

}