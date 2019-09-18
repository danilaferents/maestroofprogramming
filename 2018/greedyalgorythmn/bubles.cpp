#include <iostream>
#include <vector>
#include <deque> 
#include <algorithm> 
int main()
{
	long long summ=0,n=0,help=0,size=0,allsize=0;;
	std::cin>>n>>summ;
	std::vector<long long> array;
	std::deque<long long> helparray;
	for (int j=0; j < n;j++)
	{
		std::cin>>help;
		array.push_back(help);
	}
	long long i=array.size()-1;
	std::sort(array.begin(),array.end());
	while((summ>0))
	{
		size=summ/array[i];
		allsize+=size;
		for (long long j=0;j < size;j++)
		{
			helparray.push_front(array[i]);
		}
		summ-=(array[i]*size);
		i--;
	}
	std::cout<<allsize<<std::endl;
	for (long long j=0;j < helparray.size();j++)
	{
		std::cout<<helparray[j]<<" ";
	}
}