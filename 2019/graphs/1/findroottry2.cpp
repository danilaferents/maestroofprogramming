using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
void bfs(int x1, int y1, int x2,int y2, int w, int h, vector<vector<int>> &rectangle) 
{
	queue<pair<int,int>> q;
	pair<int,int> s = std::make_pair(y1,x1);
	pair<int,int> wheretogo = std::make_pair(y2,x2);
	q.push(s); 
	vector<vector<bool>> used(w, vector<bool>(h, false));
	vector<pair<int,int>> p(w*h);
	vector<int> d(w*h);
	used[s.first][s.second] = true;
	p[s.first*w+s.second] = make_pair(-1,-1);
	while (!q.empty()) 
	{
		pair<int,int> now = q.front();
		// std::cout<<"now: "<<now.first<<" "<<now.second<<std::endl;
		q.pop();
		// std::cout<<"now: "<<now<<" ";
		if (rectangle[now.first][now.second]) 
		{
			for(int i = 0; i < 4; i++) 
			{
				pair<int,int> to = make_pair(0,0);
				// 	for(int k = 0; k < h; k++) 
				// 	{
				// 		for(int j = 0; j < w; j++) 
				// 			{
				// 				std::cout<<used[k][j]<<" ";	
				// 			}
				// 		std::cout<<std::endl;
				// 	} 
				// std::cout<<std::endl;
				// std::cout<<"i: "<<i<<std::endl;
				// std::cout<<"used:"<<std::endl;
					// 	for(int k = 0; k < h; k++) 
					// {
					// 	for(int j = 0; j < w; j++) 
					// 		{
					// 			std::cout<<used[k][j]<<" ";	
					// 		}
					// 	std::cout<<std::endl;
					// } 
				if (i == 0 && now.first != 0 && rectangle[now.first - 1][now.second] && !used[now.first - 1][now.second])
				{
					to = make_pair(now.first - 1, now.second);
					// std::cout<<"go";
				} else
				if (i == 1 && now.first != h-1 && rectangle[now.first + 1][now.second] && !used[now.first + 1][now.second])
				{
					to = make_pair(now.first + 1, now.second);
					// std::cout<<"go1";
				} else
				if (i == 2 && now.second != 0 && rectangle[now.first ][now.second - 1] && !used[now.first][now.second - 1])
				{
					to = make_pair(now.first, now.second - 1);
					// std::cout<<"go2";
				} else
				if (i == 3 && now.second != w - 1 && rectangle[now.first ][now.second + 1] && !used[now.first][now.second + 1])
				{
					to = make_pair(now.first, now.second + 1);
					// std::cout<<"go3";
				} else {
					continue;
				}
				// std::cout<<"to: "<<to.first<<" "<<to.second<<std::endl;
				p[to.first*w+to.second] = now;
				d[to.first*w+to.second] = d[now.first*w+now.second] + 1;
				used[to.first][to.second] = true;
				// std::cout<<wheretogo<<"  "<<i<<"  ";
				if (wheretogo == to) 
				{	
					vector<pair<int,int>> path;
					for(pair<int,int> v = wheretogo; v!= make_pair(-1,-1); v = p[v.first*w+v.second])
					{
						path.push_back(v);
					}
					reverse(path.begin(), path.end());
					std::cout<<"YES"<<std::endl;
					for(int i = 0; i< path.size(); i++) 
					{
						// std::cout<<path[i]<<" ";
						std::cout<<path[i].second + 1<<" "<<path[i].first + 1<<" "; 
					}
					break;
				}	
				q.push(to);
			}
		}
	}
	if (!used[wheretogo.first][wheretogo.second]) std::cout<<"NO";
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
	// for(int i = 0; i < h; i++) 
	// {
	// 	for(int j = 0; j < w; j++) 
	// 	{
	// 		if (i!=0 && rectangle[i - 1][j] && rectangle[i][j]) 
	// 		{
	// 			graph[i*w+j][(i-1)*w+j] = 1;
	// 			graph[(i-1)*w+j][i*w+j] = 1;
	// 		}
	// 		if (i != h - 1 && rectangle[i+1][j] && rectangle[i][j]) 
	// 		{
	// 			graph[i*w+j][(i+1)*w+j] = 1;
	// 			graph[(i+1)*w+j][i*w+j] = 1; 
	// 		}
	// 		if (j!=0 && rectangle[i][j-1] && rectangle[i][j]) 
	// 		{
	// 			graph[i*w+j][i*w+j-1] = 1;
	// 			graph[i*w+j-1][i*w+j] = 1; 
	// 		}
	// 		if (j!=w - 1 && rectangle[i][j+1] && rectangle[i][j]) 
	// 		{
	// 			graph[i*w+j][i*w+j+1] = 1;
	// 			graph[i*w+j+1][i*w+j] = 1;
	// 		}
	// 	}
	// } 
	bfs(x1 - 1, y1 - 1, x2 - 1, y2 - 1, w, h, rectangle);
}