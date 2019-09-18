#include<cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
using namespace std;
long long array1[8]={0,0,0,0,0,0,0,0};
long long summarray(long long n)
{
	long long summ=0;
	for (int j = 0;  j < n; ++j)
	{
		summ+=pow(array1[j],3);
	}
	return summ;
}
bool checkandprint(long long n,bool &iftrue,long long oursumm)
{
	if (summarray(n)==oursumm) 
	{
		iftrue=true;
		for (int j = 0;  j< n; ++j)
		{
			  cout<<array1[j]<<" ";
		}
		return true;
	}
	return false;
}
void permutation(bool &iftrue,long long n)
{
	for (long long i =pow(n,1.0/3); i >=1 ; --i)
	{
		array1[0]=i;
		if(checkandprint(1,iftrue,n)) return;
		for (int j = pow(n-summarray(1),1.0/3); j >=1 ; --j)
		{	
			array1[1]=j;
			if(checkandprint(2,iftrue,n)) return;
			for (int k = pow(n-summarray(2),1.0/3); k >=1 ; --k)
			{	
				array1[2]=k;
				if(checkandprint(3,iftrue,n)) return;
				for (int d = pow(n-summarray(3),1.0/3); d >=1 ; --d)
				{	
					array1[3]=d;
					if(checkandprint(4,iftrue,n)) return;
					for (int e = pow(n-summarray(4),1.0/3); e >=1 ; --e)
					{	
						array1[4]=e;
						if(checkandprint(5,iftrue,n)) return;
						for (int f = pow(n-summarray(5),1.0/3); f >=1 ; --f) //для последних двух перебор не нужен тк мало чисел требующих разложение на 8 цифр и те которые требуют содержат 1(15,22,50,114,167,175,186,212,231,238,303,364,420,428,454)
						{	
							array1[5]=f;
							if(checkandprint(6,iftrue,n)) return;
							int g = pow(n-summarray(6),1.0/3);
							array1[6]=g;
							if(checkandprint(7,iftrue,n)) return;
							array1[7]=pow(n-summarray(7),1.0/3);
							if(checkandprint(8,iftrue,n)) return;
						}
					}
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin>>n;
	bool iftrue=false;
	permutation(iftrue,n);
	if (!iftrue) cout<<"IMPOSSIBLE";
}