
#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>

int main()
{
	int numbertops=0;
	std::cin>>numbertops;
	int array[numbertops][numbertops];
	int first,second;
	for (int k=0; k<numbertops; ++k)
		for (int i=0; i<numbertops; ++i)
		{
			if(k == i) array[k][i]=0; 
			else array[k][i]=INT_MAX;
		}
	for (int k=0; k<numbertops; ++k)
		for (int i=0; i<numbertops; ++i)
		{
			int first;
			std::cin>>first;
			if (first) array[k][i] = 1;
		}
	for (int k=0; k<numbertops; ++k)
		for (int i=0; i<numbertops; ++i)
			for (int j=0; j<numbertops; ++j)
				if (array[i][k] < INT_MAX && array[k][j] < INT_MAX)
					array[i][j] = min (array[i][j], array[i][k] + array[k][j]);

	long long summ=0;
	for (int k=0; k<numbertops; ++k)
		for (int i=0; i<numbertops; ++i)
			if(array[k][i] != INT_MAX) summ+=array[k][i];
			// cout<<array[k][i]<<" ";
	cout<<summ;
}