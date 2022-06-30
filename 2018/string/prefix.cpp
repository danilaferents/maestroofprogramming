#include <cmath>
#include <iostream>
#include <algorithm> 
#include <vector> 
#include <string> 
using namespace std;
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
int main()
{
	string instring1;
	cin>>instring1;
	vector<int> sizes;
	sizes = prefix_function(instring1);
	cout<<instring1.size()-sizes[instring1.size()-1];
}