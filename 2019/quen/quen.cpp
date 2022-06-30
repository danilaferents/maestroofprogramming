#include <iostream>
#include <vector>

using namespace std;

vector<int> col(8,0), diag1(16,0), diag2(16,0);
int kcount = 0;
//На вход подается координата строк на доске - y 
void search(int y, int n) {
	//если мы исчерпали строки, то мы прошли все поле
	if (y == n) {
		kcount++;
	}

	//проходим по каждому столбцу - x
	for(int x = 0; x < n; x++) {

		//проверяем попадаем ли мы по столбцу, нисходящей или восходящей диагонали в поле боя другого ферзя. 
		if (col[x] || diag1[x + y] || diag2[n - 1 + (x - y)]) continue;

		//ставим ферзя 
		col[x] = diag1[x + y] = diag2[n - 1 + (x - y)] = 1;

		//увеличиваем y 
		search(y + 1, n);

		//убираем ферзя
		col[x] = diag1[x + y] = diag2 [n - 1 + (x - y)] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 8;
	// std::cin>>n;

	search(0, n);

	cout<<"\n"<<kcount<<"\n";


}

//для 4x4

//col
// 0 1 2 3 
// 0 1 2 3 
// 0 1 2 3 
// 0 1 2 3 

//diag1 
//0 1 2 3 
//1 2 3 4 
//2 3 4 5 
//3 4 5 6 

//diag 2
//3 4 5 6 
//2 3 4 5
//1 2 3 4 
//0 1 2 3 