#include <iostream>
#include "vector"
// Naive method to find a pair in an array with given sum
void findSumm(std::vector<int> array, int summ){
	// consider each element except last element
	for (int i = 0; i < array.size() - 1; ++i)
	{
		// start from i'th element till last element
		for (int j = i; j < array.size(); ++j)
		{
			// if desired sum is found, print it and return
			if (array[i] + array[j] == summ) 
			{
				std::cout<<"Pair found at index "<<i<<" and "<<j<<"("<<array[i]<<"+"<<array[j]<<");"<<std::endl;
				return;
			}
		}
	}
	//No pair has found
	std::cout<<"No such pair";
}
// Find pair with given sum in the array
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
	findSumm(array,summ);

}