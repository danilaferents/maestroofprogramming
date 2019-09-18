#include <iostream>
#include <vector>
#include <unordered_map>

//Function to print all subarrays with 0 summ
void findAllSubarrays(std::vector<int> arr) {

	//create multimap to store end index and summ
	std::unordered_multimap<int, int> summs;

	//insert 0 to map to handle when subarray 
	//with 0 summ is in the first index
	summs.insert(std::pair<int, int>(0, -1));
	int summ = 0;


	for (int i = 0; i < arr.size(); ++i)
	{
		summ += arr[i];
		if (summs.find(summ) != summs.end()) {

			auto iter = summs.find(summ);

			//find all subarrays with exact summ
			while (iter != summs.end() && iter->first == summ) {
				std::cout<<"Subarray: [ "<<iter->second + 1<<" : "<<i<<" ]"<<std::endl;
				iter++;
			}
		}

		//insert current summ
		summs.insert(std::make_pair(summ, i));	
	}
}

int main() {
	
	std::vector <int> arr;

	int n = 0;
	std::cin>>n;

	for (int i = 0; i < n; ++i)
	{
		int help;
		std::cin>>help;
		arr.push_back(help);
	}

	findAllSubarrays(arr);

} 