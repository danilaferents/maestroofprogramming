#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i=0;
	int n=2;

	while (i<120)
	{
       n*=n;
       n%=10000;
       cout << n+1 << endl;
       i++;

	}

}