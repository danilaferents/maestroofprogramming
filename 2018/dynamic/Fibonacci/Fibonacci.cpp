#include <iostream>
int main()
{
	long long a=1,b=1;
	int i=1,n;
	std::cin >> n;
	while (i<n)
	{
		a=a+b;
		b=a-b;
		i++;
	}
	std::cout<<a;
}