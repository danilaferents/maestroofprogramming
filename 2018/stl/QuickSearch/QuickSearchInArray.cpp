#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	int help;
	vector<int> array;
	for (int i=0;i<n;i++)
	{
		cin>>help;
		array.push_back(help);
	}
	sort(array.begin(),array.end());
	int k=0,First=0,Second=0;
	cin>>k;
	//uper bound вернет число больше чем правая граница или end(), что нам подходит, т.к. , значит,  все числа меньше правой границы.
	//lower bound вернет число не больше чем левая граница или указатель на начало, если таких нет, что тоже нам подходит т.к. , значит,  все числа не меньше чем левая граница.
	//Значит их разность и будет количеством чисел!!!
	for (int i=0;i<k;i++)
	{
		cin>>First>>Second;
		cout<<(upper_bound (array.begin(), array.end(), Second)-array.begin())-(lower_bound (array.begin(), array.end(), First)-array.begin())<<" ";
	}
}
