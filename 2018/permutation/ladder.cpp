#include<climits>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <vector>
#include <algorithm>
using namespace std;
int summladders(int currl,int currh,int l,int h)
{
	int summ=0;
	if((currl>l)||(currh>h)) return 0;
	if ((currl==l)&&(currh==h)) return 1;
	summ+=summladders(currl+1,currh+1,l,h);
	summ+=summladders(currl+1,currh+2,l,h);
	return summ;
}
int main()
{
	int l,h;
	cin>>l>>h;
	int summ=summladders(0,0,l,h);
	cout<<summ;
}