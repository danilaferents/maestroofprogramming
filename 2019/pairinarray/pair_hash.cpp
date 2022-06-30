#include<unordered_map>
#include <iostream>
#include <vector>
void findSumm(std::vector<int> array, int summ) {
	std::unordered_map<int, int> help;

	for (int i = 0; i < array.size(); ++i)
	{
		if (help.find(summ - array[i]) != help.end()) {
			std::cout<<"Pair found at index "<<i<<" and "<<help[summ - array[i]]<<"("<<array[i]<<"+"<<summ - array[i]<<");"<<std::endl;
			return;
		}
		help[array[i]] = i;
	}
	std::cout<<"Pair not found!";
}
int main() {
	std::vector<int> array;
	int help,size;
	std::cin>>size;
	for (int i = 0; i < size; ++i)
	{
		std::cin>>help;
		array.push_back(help);
	}

	int summ;

	std::cin>>summ;
	findSumm(array, summ);
}