using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
void bfs(int x1, int y1, int x2,int y2, int w, int h, vector<vector<int>> graph) 
{
	queue<int> q;
	int s = y1*w+x1;
	int wheretogo = y2*w+x2;
	int size = w*h;
	q.push(s); 
	vector<bool> used(size);
	vector<int> p(size);
	vector<int> d(size);
	used[s] = true;
	p[s] = -1;

	while (!q.empty()) 
	{
		int now = q.front();
		q.pop();
		// std::cout<<"now: "<<now<<" ";
		for(int i = 0; i < size; i++) 
		{
			if (!used[i] && graph[now][i]) 
			{
				p[i] = now;
				d[i] = d[now] + 1;
				used[i] = true;
				// std::cout<<wheretogo<<"  "<<i<<"  ";
				if (wheretogo == i) 
				{	
					vector<int> path;
					for(int v = wheretogo; v!= -1; v = p[v])
					{
						path.push_back(v);
					}
					reverse(path.begin(), path.end());
					std::cout<<"YES"<<std::endl;
					for(int i = 0; i< path.size(); i++) 
					{
						// std::cout<<path[i]<<" ";
						std::cout<<path[i]%w + 1<<" "<<path[i]/w + 1<<" "; 
					}
					break;
				}	
				q.push(i);
			}
		}
	}
	if (!used[wheretogo]) std::cout<<"NO";
}
int main() 
{
	int w, h, x1, y1, x2, y2;
	cin>>w>>h>>x1>>y1>>x2>>y2;
	vector<vector<int>> rectangle(w, vector<int>(h,0));
	for(int i = 0; i < h; i++) 
	{
		for(int j = 0; j < w; j++) 
		{
			char t; 
			cin >> t;
			if (t == '.') rectangle[i][j] = 1;
			if (t == '*') rectangle[i][j] = 0;	
		}
	} 

	vector<vector<int>> graph(w*h, vector<int>(w*h,0));

	for(int i = 0; i < h; i++) 
	{
		for(int j = 0; j < w; j++) 
		{
			if (i!=0 && rectangle[i - 1][j] && rectangle[i][j]) 
			{
				graph[i*w+j][(i-1)*w+j] = 1;
				graph[(i-1)*w+j][i*w+j] = 1;
			}
			if (i != h - 1 && rectangle[i+1][j] && rectangle[i][j]) 
			{
				graph[i*w+j][(i+1)*w+j] = 1;
				graph[(i+1)*w+j][i*w+j] = 1; 
			}
			if (j!=0 && rectangle[i][j-1] && rectangle[i][j]) 
			{
				graph[i*w+j][i*w+j-1] = 1;
				graph[i*w+j-1][i*w+j] = 1; 
			}
			if (j!=w - 1 && rectangle[i][j+1] && rectangle[i][j]) 
			{
				graph[i*w+j][i*w+j+1] = 1;
				graph[i*w+j+1][i*w+j] = 1;
			}
		}
	} 
	bfs(x1 - 1, y1 - 1, x2 - 1, y2 - 1, w, h, graph);
}
