#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
//идея задачи состоит в том, чтобы взять последовательность k чисел:
// если поставить на конец 0 то нас устроить любая хорошая последовательность чисел размера к-1 
//а если стоит 1 на конце то если перед ней стоит нолик то устроит последовательность к-1 
// если все плохо и стоят на конце две единицы то перед ними берем ноль и хорошую последовательность k-3 чисел
//задача свелась к нахождению n числа трибоначчи
int main()
{
	int n=0;
	cin>>n;
	long long a=0,b=0,c=1;
	for (int i=0;i<=(n);i++)
	{
		c=a+b+c;
		b=c-a-b;
		a=c-b-a;
		c%=12345;
	}
	cout<<c;
	return 0;
}