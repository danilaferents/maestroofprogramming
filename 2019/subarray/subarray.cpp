#include <iostream>
#include  <unordered_set>
#include <vector>
bool findSumm(std::vector<int> numbers) {
	std::unordered_set<int> summs;

	summs.insert(0);

	int summ = 0;

	for (int i = 0; i < numbers.size(); ++i)
	{
		summ+=numbers[i];

		if (summs.find(summ) != summs.end()) {
			return true;
		} else {
			summs.insert(summ);
		}
	}
	return false;
}

int main() {
	std::vector<int> input;

	int size = 0;
	std::cin>>size;

	for (int i = 0; i < size; ++i)
	{
		int help;
		std::cin>>help;
		input.push_back(help);
	}

	std::cout<<findSumm(input);

}