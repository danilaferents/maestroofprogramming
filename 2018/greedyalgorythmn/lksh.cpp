#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int contain=0,n=0,m=0,help=0,size=0,ihelp=0;
	std::cin>>contain>>n;
	std::vector<int> array;
	std::vector<int> helparray;
	for (int j=0; j < n;j++)
	{
		std::cin>>help;
		array.push_back(help);
	}
	std::vector<int>::iterator result;
	while((contain>0) && (size<n))
	{
		result = std::max_element(array.begin(), array.end());
        ihelp=std::distance(array.begin(), result);

		contain-=array[ihelp];
		array.at(ihelp)=0;
		helparray.push_back(ihelp+1);
		size++;
	}
	if (contain<=0)
	{
		std::cout<<size<<std::endl;
		for (int j=0;j < size;j++)
		{
			std::cout<<helparray[j]<<" ";
		}
	}
	else 
	{
		std::cout<<"-1";
	}
}