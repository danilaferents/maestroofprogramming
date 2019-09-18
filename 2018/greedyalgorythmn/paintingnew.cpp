#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void copy(vector<vector<char>> &array,vector<vector<char>> &array1,int h,int w)
{
	for (int i = 0; i <=h; ++i)
	{
		for (int j = 0; j <=w; ++j)
		{
			array[i][j]=array1[i][j];
		}
	}
}
int dfs(vector<vector<char>> &array,int i,int j)
{
	int summ=0;
	if((array[i][j+1] == 'w') ||(array[i][j-1] == 'w') || (array[i+1][j] == 'w') || (array[i-1][j] == 'w'))
	{
		array[i][j]='b';
		summ++;
	}
	if((array[i][j+1] == 'b') ||(array[i][j-1] == 'b') || (array[i+1][j] == 'b') || (array[i-1][j] == 'b'))
		array[i][j]='w';

	if (array[i][j+1]=='#')
	{
		summ+=dfs(array,i,j+1);
	}
	if (array[i][j-1]=='#')
	{
		summ+=dfs(array,i,j-1);
	}
	if (array[i-1][j]=='#')
	{
		summ+=dfs(array,i-1,j);
	}
	if (array[i+1][j]=='#')
	{
		summ+=dfs(array,i+1,j);
	}
	return summ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int w,h;
	cin>>w>>h;
	char help;
	vector<vector<char>> array(h+2);
	vector<vector<char>> array1(h+2);
	for (int i = 0; i <=(h+1); ++i)
	{
		for (int j = 0; j <=(w+1); ++j)
		{
			array[i].push_back('.');
			array1[i].push_back('.');
		}
	}
	for (int i = 1; i <=h; ++i)
	{
		for (int j =1; j <=w; ++j)
		{
				cin>>help;
				array[i][j]=help;
				array1[i][j]=help;
		}
	}
	for (int i = 1; i <=h; ++i)
	{
		for (int j = 1; j<=w; ++j)
		{
			if (array[i][j] == '#')
			{
				array[i][j]='b';
				int summ= dfs(array,i,j)+1;
				array1[i][j]='w';
				int summ1= dfs(array1,i,j);
				if (summ>=summ1) copy(array1,array,h+1,w+1); //даунич я же еще думал что == надо рассмотреть но нет упрямое чмо пусть тебе это будет уроком
				if (summ<summ1) copy(array,array1,h+1,w+1);
			}
		}
	}
	for (int i = 1; i <=h; ++i)
	{
		for (int j = 1; j <=w; ++j)
		{
			cout<<array[i][j];
		}
		cout<<endl;
	}
	
}