#include <iostream>
#include <vector>
int main()
{
	int n=0,k=0,helpint;
	std::vector<int> helpint2;
	std::vector<int> money;
	std::vector<int> help(3000,0);
	std::cin>>n;
	for (int i=0;i<n;i++)
	{
		std::cin>>helpint;
		helpint2.push_back(helpint);
	}	
	std::cin>>k;
	for (int i=0;i<k;i++)
	{
		std::cin>>helpint;
		money.push_back(helpint);
	}
	help[0]=1;
	for (int i=0;i<1000;i++)
	{	
		if(help[i]==1)	
			{	
				for (int j=0;j<n;j++)
				{
					help[i+helpint2[j]]=1;
				}
			}
	}
	for (int i=0;i<k;i++)
	{
		std::cout <<help[money[i]]<<" ";
	}
}