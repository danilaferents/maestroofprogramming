#include <iostream>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
int main()
{
	ordered_set<int> array;
	string input;
	int help=0,n=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>input>>help;
		if ((input == "+1") || (input == "1"))
		{
			array.insert(help);
			continue;
		}
		if (input == "-1")
		{
			array.erase(help);
			continue;
		}
		if (input == "0")
		{
			auto it=array.end();
			cout<<*array.find_by_order(array.size()-help)<<endl;
			continue;
		}
	}
}