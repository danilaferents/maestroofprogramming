 #include <iostream>
#include<climits>
#include <vector>
#include <algorithm> 
#include <cstdio>
#include <cstring>
#define MAX 100010
using namespace std;
long long tree[4*MAX];
// void build(int u, int l, int r)
// {
// 	if (l == r)
// 		return void(tree[u] = array1[l]);
// 	int middle = (l + r) / 2;
// 	build (u << 1,l,middle);
// 	build(u << 1 | 1,middle + 1, r);
// 	tree[u] = tree[u << 1] + tree[u << 1 | 1];
// }
void update(int u, int l, int r, int i, long long x)
{
	if (l == r)
		return void(tree[u] = x);
	else
	{
		int middle = (l + r) / 2;
		if (i <= middle) update(u << 1, l , middle, i, x);
		else update(u << 1 | 1, middle + 1, r, i, x);
		tree[u] = tree[u << 1] + tree[u << 1 | 1];
	}	
}
long long getsumm(int u, int l, int r, int L, int R)
{
	if (L > R) return 0;
	if ((l == L) && (r == R))
		return (tree[u]);
	int middle = (l + r) / 2;
	return getsumm(u << 1, l, middle, L, min(middle,R)) + getsumm(u << 1 | 1, middle + 1, r, max(L,middle+1), R);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K;
	int n;
	cin>>n>>K;
	char letter;
	long long first,second;
	memset(tree,0,sizeof(tree));
	// for (int i = 1; i <=n; ++i)
	// {
	// 	array1[i] = 0;
	// }
	// build(1,1,n);
	for (int i = 0; i < K; ++i)
	{
		cin>>letter;
		cin>>first>>second;
		switch(letter)
		{
			case 'A':
			{
				// array1[first] = second;
				update(1,1,n, first, second);
				break;
			}
			case 'Q':
			{
				cout<<getsumm(1, 1, n, first, second)<<endl;
				break;
			}
		}
	}
	
	return 0;
}