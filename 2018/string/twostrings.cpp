#include <cmath>
#include <iostream>
#include <algorithm> 
#include <vector> 
#include <string> 
using namespace std;
vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
int main()
{
	string instring1,instring2;
	cin>>instring1>>instring2;
	vector<int> sizes;
	string s = instring2+"#"+instring1;
	sizes = z_function(s);
	int k = 0;
	vector<int> result;
	for (int i = instring2.size()+1; i <= instring2.size()+instring1.size(); ++i)
	{
		if (sizes[i] == instring2.size())
		{
			k++;
			result.push_back(i - instring2.size());
		}
	}
	cout<<k<<endl;
	for(auto i:result)
	{
		cout<<i<<" ";
	}

}