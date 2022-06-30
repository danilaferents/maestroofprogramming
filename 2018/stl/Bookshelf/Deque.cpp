#include <iostream>
#include <vector>
#include <algorithm> 
#include <deque>
using namespace std;
//
int main()
{
	deque <int> array;
	int n=0,first=0,second=0;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>first;
		switch(first)
		{
			case 1:
			{
				cin>>second;
				array.push_front(second);
				break;
			}
			case 2:
			{
				cin>>second;
				array.push_back(second);
				break;
			}
			case 3:
			{
				cout<<array.at(0)<<endl;
				array.pop_front();
				break;
			}
			case 4:
			{
				cout<<array.at(array.size()-1)<<endl;
				array.pop_back();
				break;
			}
		}
	}
}