#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
	int w,h;
	cin>>w>>h;
	char array[w][h];
	char help;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin>>help;
			array[i][j]=help;
		}
	}
	int ouri=-1,ourj=-1;
	for (int i = 1; i < (h-1); ++i)
	{
		for (int j = 1; j < (w-1); ++j)
		{
			if (array[i][j]=='#')
			{
				if((array[i+1][j] == '#') && (array[i-1][j] == '#') && (array[i][j+1] == '#') && (array[i][j-1] == '#'))
				{
					array[i][j]='w';
					ouri=i;
					ourj=j;
				}
			}
		}
	}
	if(ouri==(-1))
	{
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (array[i][j]=='#')
				{
					array[i][j]='b';
					ouri=i;
					ourj=j;
					break;
				}
			}
		}
	}
	for (int i = ouri; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			// cout<<i<<" "<<j<<" "<<endl;
			if((i>0)&&(i<(h-1))&&(j<(w-1))&&(j>0))
			{
				if (array[i][j]=='#')
					{
						if((array[i][j+1] == 'w') ||(array[i][j-1] == 'w') || (array[i+1][j] == 'w') || (array[i-1][j] == 'w'))
							array[i][j]='b';
						if((array[i][j+1] == 'b') ||(array[i][j-1] == 'b') || (array[i+1][j] == 'b') || (array[i-1][j] == 'b'))
							array[i][j]='w';
					}
					// if (array[i][j]=='#')
					// {
					// 	array[i][j]='b';
					// }
			}
			if((i==h-1)&&(j>0)&&(j<w-1))
			{
				 	if (array[h-1][j]=='#')
					{
						if((array[h-1][j+1] == 'w') || (array[h-1][j-1] == 'w') || (array[h-2][j] == 'w'))
							array[h-1][j]='b';
						if((array[h-1][j+1] == 'b') || (array[h-1][j-1] == 'b') || (array[h-2][j] == 'b'))
							array[h-1][j]='w';
					}
					// if (array[i][j]=='#')
					// {
					// 	array[i][j]='b';
					// }
			}
			if((i==0)&&(j>0)&&(j<w-1))
			{
				if (array[i][j]=='#')
				{
					if((array[0][j+1] == 'w') || (array[0][j-1] == 'w') || (array[1][j] == 'w'))
						array[0][j]='b';
					if((array[0][j+1] == 'b') || (array[0][j-1] == 'b') || (array[1][j] == 'b'))
						array[0][j]='w';
				}
				// if (array[i][j]=='#')
				// {
				// 	array[i][j]='b';
				// }
			}
			if((i>0)&&(i<h-1)&&(j==0))
			{
				if (array[i][j]=='#')
					{
						if((array[i][j+1] == 'w') || (array[i+1][j] == 'w') || (array[i-1][j] == 'w'))
							array[i][j]='b';
						if((array[i][j+1] == 'b') || (array[i+1][j] == 'b') || (array[i-1][j] == 'b'))
							array[i][j]='w';
					}
					// if (array[i][j]=='#')
					// {
					// 	array[i][j]='b';
					// }
			}
			if((i>0)&&(i<h-1)&&(j==w-1))
			{
				if (array[i][j]=='#')
					{
						if((array[i][j-1] == 'w') || (array[i+1][j] == 'w') || (array[i-1][j] == 'w'))
							array[i][j]='b';
						if((array[i][j-1] == 'b') || (array[i+1][j] == 'b') || (array[i-1][j] == 'b'))
							array[i][j]='w';
					}
					// if (array[i][j]=='#')
					// {
					// 	array[i][j]='b';
					// }
			}
			if((i==h-1)&&(j==w-1))
			{
				if (array[h-1][w-1]=='#')
				{
					if((array[h-2][w-1] == 'w') || (array[h-1][w-2] == 'w'))
								array[h][w]='b';
					if((array[h-2][w-1] == 'b') || (array[h-1][w-2] == 'b'))
								array[h][w]='w';
				}
				// if (array[h-1][w-1]=='#')
				// {
				// 	array[h-1][w-1]='b';
				// }
			}

			if ((i==h-1)&&(j==0))
			{
				if (array[h-1][0]=='#')
				{
					if((array[h-2][0] == 'w') || (array[h-1][1] == 'w'))
								array[h][0]='b';
					if((array[h-2][0] == 'b') || (array[h-1][1] == 'b'))
								array[h][0]='w';
				}
				// if (array[h-1][0]=='#')
				// {
				// 	array[h-1][0]='b';
				// }
			}
		}
	}
	for (int i = ouri; i >=0; i--)
	{
		for (int j =w-1; j >=0; j--)
		{
			// cout<<i<<" "<<j<<" "<<endl;
			// if ((i==1)&&(j==1))
			// {
			// 	cout<<array[i][j+1]<<" "<<array[i][j-1]<<" "<<array[i+1][j]<<" "<<(array[i-1][j])<<endl;
			// }
			if((i>0)&&(i<(h-1))&&(j<(w-1))&&(j>0))
			{
				if (array[i][j]=='#')
					{
						if((array[i][j+1] == 'w') || (array[i][j-1] == 'w') || (array[i+1][j] == 'w') || (array[i-1][j] == 'w'))
							array[i][j]='b';
						if((array[i][j+1] == 'b') || (array[i][j-1] == 'b') || (array[i+1][j] == 'b') || (array[i-1][j] == 'b'))
							array[i][j]='w';
					}
					// if (array[i][j]=='#')
					// {
					// 	array[i][j]='b';
					// }
			}
			if((i==0)&&(j>0)&&(j<w-1))
			{
				if (array[i][j]=='#')
				{
					if((array[0][j+1] == 'w') || (array[0][j-1] == 'w') || (array[1][j] == 'w'))
						array[0][j]='b';
					if((array[0][j+1] == 'b') || (array[0][j-1] == 'b') || (array[1][j] == 'b'))
						array[0][j]='w';
				}
				// if (array[i][j]=='#')
				// {
				// 	array[i][j]='b';
				// }
			}
			if((i>0)&&(i<h-1)&&(j==0))
			{
				if (array[i][j]=='#')
					{
						if((array[i][j+1] == 'w') || (array[i+1][j] == 'w') || (array[i-1][j] == 'w'))
							array[i][j]='b';
						if((array[i][j+1] == 'b') || (array[i+1][j] == 'b') || (array[i-1][j] == 'b'))
							array[i][j]='w';
					}
					// if (array[i][j]=='#')
					// {
					// 	array[i][j]='b';
					// }
			}
			if((i==h-1)&&(j>0)&&(j<w-1))
			{
				 	if (array[h-1][j]=='#')
					{
						if((array[h-1][j+1] == 'w') || (array[h-1][j-1] == 'w') || (array[h-2][j] == 'w'))
							array[h-1][j]='b';
						if((array[h-1][j+1] == 'b') || (array[h-1][j-1] == 'b') || (array[h-2][j] == 'b'))
							array[h-1][j]='w';
					}
					// if (array[i][j]=='#')
					// {
					// 	array[i][j]='b';
					// }
			}
			if((i>0)&&(i<h-1)&&(j==w-1))
			{
				if (array[i][j]=='#')
					{
						if((array[i][j-1] == 'w') || (array[i+1][j] == 'w') || (array[i-1][j] == 'w'))
							array[i][j]='b';
						if((array[i][j-1] == 'b') || (array[i+1][j] == 'b') || (array[i-1][j] == 'b'))
							array[i][j]='w';
					}
					// if (array[i][j]=='#')
					// {
					// 	array[i][j]='b';
					// }
			}
			if((i==0)&&(j==w-1))
			{
				if (array[i][j]=='#')
				{
					if((array[i+1][j] == 'w') || (array[i][j-1] == 'w'))
								array[i][j]='b';
					if((array[i+1][j] == 'b') || (array[i][j-1] == 'b'))
								array[i][j]='w';
				}
				// if (array[h-1][w-1]=='#')
				// {
				// 	array[h-1][w-1]='b';
				// }
			}
			if ((i==0)&&(j==0)) 
			{
				if (array[0][0]=='#')
				{
					if((array[0][1] == 'w') || (array[1][0] == 'w'))
								array[0][0]='b';
					if((array[0][1] == 'b') || (array[1][0] == 'b'))
								array[0][0]='w';
				}
				// if (array[0][0]=='#')
				// {
				// 	array[0][0]='b';
				// }
			}
			if ((i==h-1)&&(j==0))
			{
				if (array[h][0]=='#')
				{
					if((array[h-2][0] == 'w') || (array[h-1][1] == 'w'))
								array[h][0]='b';
					if((array[h-2][0] == 'b') || (array[h-1][1] == 'b'))
								array[h][0]='w';
				}
				// if (array[h-1][0]=='#')
				// {
				// 	array[h-1][0]='b';
				// }
			}

		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			// if (array[i][j]=='#')
			// {
			// 	array[i][j]='b';
			// }
			cout<<array[i][j];
		}
		cout<<endl;
	}
}