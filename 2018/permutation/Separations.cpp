
#include<climits>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
using namespace std;
vector<int> a;
int size;
void generate(int last,int sum)
{
     if (sum==size) 
     {
          for (int i=0;i<=last;++i)
               cout<<a[i]<<" ";
           cout<<endl;
     }
     else
          for (int j=1; j<=min(a[last],size-sum);++j)
          {
               last++;
               a[last]=j;
               generate(last,sum+j);
               last--;
		}
}
int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin>>size;
	for (int i = 0; i < size; ++i)
	{
		a.push_back(0);
	}
	for (int j=1; j<=size;++j)
	{
    	 a[0]=j;
    	 generate(0,j); 
	}
}