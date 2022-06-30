#include<climits>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
//* * *
//3 4 5
bool nextcombination(std::vector<int> &array,int n)
{
	int size=array.size();
	for (int i = size-1; i >=0; i--)
		if((array[i]<(n-size+i+1))) 
		{
			++array[i];
			for (int j = i+1; j < size; ++j)
				array[j]=array[j-1]+1;
			return true;
		}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> array;
	for (int i = 1; i <=k; ++i)
	{
		array.push_back(i);
		cout<<i<<" ";
	}
	cout<<endl;
	while(nextcombination(array,n))
	{
		for (int j = 0; j < array.size(); ++j)
		{
			cout<<array[j]<<" ";
		}
		cout<<endl;
	}
}