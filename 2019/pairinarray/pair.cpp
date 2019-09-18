#include <iostream>
#include <vector>

// Function to find a pair in an array with given sum using Sorting
void findSumm(std::vector<int> array, int summ) {
	// sort the array in ascending order
	std::sort(array.begin(), array.end());
	// maintain two indices pointing to end-points of the array
	int low = 0, high = array.size() - 1;
	//continue untill indices crosses
	while (low < high) {
		// std::cout<<low<<" "<<high<<" "<<array[low]<<" "<<array[high]<<" "<<std::endl;
		if (array[low] + array[high] == summ) {
			std::cout<<"Pair found!!"<<std::endl;
			return;
		}
		// increment low index if total is less than the desired sum
		// decrement high index is total is more than the sum
		(array[low] + array[high] < summ) ? low++ :high++; 
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