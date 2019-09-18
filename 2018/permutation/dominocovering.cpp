#include<climits>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int getsumm(std::vector<vector<int>> &array,int w,int h)
{
	int summ=0;
	for (int i = 1; i <=w; ++i)
	{
		for (int j = 1; j <=h; ++j)
		{
			summ+=array[i][j];
		}
	}
	return summ;
}
bool getempty(std::vector<vector<int>> &array,pair<int,int> &pairour,int w,int h)
{
	for (int i = 1; i<=w; ++i)
	{
		for (int j = 1; j<=h; ++j)
		{
			if (array[i][j]==0) 
			{
				pairour.first=i;
				pairour.second=j;
				return true;
			}
		}
	}
	return false;
}
int recursion(std::vector<vector<int>> &array,int w,int h)
{	

	int summ=0;
	pair<int,int> ourpair;
	
	if(!getempty(array,ourpair,w,h))
	{
		int currsumm=getsumm(array,w,h);
		if (currsumm==h*w) return 1;
		else return 0;
	}
	if((array[ourpair.first][ourpair.second+1]!=0)&&(array[ourpair.first][ourpair.second]==0)&&(array[ourpair.first][ourpair.second-1]!=0)&&(array[ourpair.first-1][ourpair.second]!=0)&&(array[ourpair.first+1][ourpair.second]!=0))
	return 0;
	if ((array[ourpair.first][ourpair.second+1]!=2)&&(array[ourpair.first][ourpair.second+1]==0))
	{
		array[ourpair.first][ourpair.second]=1;
		array[ourpair.first][ourpair.second+1]=1;
		summ+=recursion(array,w,h);
		array[ourpair.first][ourpair.second]=0;
		array[ourpair.first][ourpair.second+1]=0;
	}
	if ((array[ourpair.first][ourpair.second-1]!=2)&&(array[ourpair.first][ourpair.second-1]==0))
	{
		array[ourpair.first][ourpair.second]=1;
		array[ourpair.first][ourpair.second-1]=1;
		summ+=recursion(array,w,h);
		array[ourpair.first][ourpair.second]=0;
		array[ourpair.first][ourpair.second-1]=0;
	}
	if ((array[ourpair.first+1][ourpair.second]!=2)&&(array[ourpair.first+1][ourpair.second]==0))
	{
		array[ourpair.first+1][ourpair.second]=1;
		array[ourpair.first][ourpair.second]=1;
		summ+=recursion(array,w,h);
		array[ourpair.first+1][ourpair.second]=0;
		array[ourpair.first][ourpair.second]=0;
	}
	if ((array[ourpair.first-1][ourpair.second]!=2)&&(array[ourpair.first-1][ourpair.second]==0))
	{
		array[ourpair.first-1][ourpair.second]=1;
		array[ourpair.first][ourpair.second]=1;
		summ+=recursion(array,w,h);
		array[ourpair.first-1][ourpair.second]=0;
		array[ourpair.first][ourpair.second]=0;
	}
	return summ;
}
int main()
{
	int w,h;
	cin>>w>>h;
	vector<vector<int>> array(w+2);
	for (int i = 0; i <=h+1; ++i)
	{
		array[0].push_back(2);
	}
	for (int i = 1; i <=w; ++i)
	{
		for (int j = 0; j <=h+1; ++j)
		{
			if (j==0 || j==h+1) array[i].push_back(2);
			else array[i].push_back(0);
			
		}
	}
	for (int i = 0; i <=h+1; ++i)
	{
		array[w+1].push_back(2);
	}
	// for (int i = 0; i <=w+1; ++i)
	// {
	// 	for (int j = 0; j <=h+1; ++j)
	// 	{
	// 		cout<<array[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	if((w%2==1) && (h%2==1)) cout<<"0";
	else 
	{
		cout<<recursion(array,w,h);
	} 
}