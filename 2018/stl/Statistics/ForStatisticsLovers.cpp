#include <iostream>
#include <vector>
#include <algorithm> 
#include <map> 
#include <set> 
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	int help; 
	map <int,set<int>>  array;
	set<int> helparray;
	for (int i=0;i<n;i++)
	{
		cin>>help;
		array[help].insert(i+1);
	}
	int k=0,First=0,Second=0,Third=0;
	cin>>k;
	cout<<endl;
	//в map каждому значению соответсвует set из номеров городов с данным значением.
    //Чтобы проверить: достаю номер не меньше, чем нижняя граница того, что нужно найти и , если этот город меньше или равен правой границе, то , значит, верно и вывожу true.
	//если же указатель на конец значит такого города не нашлось и вывожу false
	for (int i=0;i<k;i++)
	{
		cin>>First>>Second>>Third;
		int k=0;
		auto p=array[Third].lower_bound(First);
		if ((*p <= Second) && (p!= array[Third].end())) k=1;
		if (k) cout<<"1";
		else cout<<"0";
		k=0;
	}
}
