 #include <iostream>
#include<climits>
#include <vector>
#include <algorithm> 
#include <cstdio>
#include <cstring>
#define MAX 100010
using namespace std;
long long tree[4*MAX];
long long array1[MAX];
void build(int u, int l, int r)
{
	if (l == r)
		return void(tree[u] = array1[l]);
	int middle = (l + r) / 2;
	build (u << 1,l,middle);
	build(u << 1 | 1,middle + 1, r);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
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
long long getsumm(int u, int l, int r, int L, int R,int constl,int constr)
{
	if (L > R) return 0;
	if ((l == L) && (r == R) && (L=R))
	{
		cout<<(l-constl)%2<<endl;
		if (((l-constl)%2 == 0)) return (tree[u]);
		else return(-tree[u]);

	}
	int middle = (l + r) / 2;
	return getsumm(u << 1, l, middle, L, min(middle,R),constl,constr) + getsumm(u << 1 | 1, middle + 1, r, max(L,middle+1), R,constl,constr);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K;
	int n;
	cin>>n;
	int letter;
	long long first,second;
	memset(tree,0,sizeof(tree));
	for (int i = 1; i <=n; ++i)
	{
		cin>>array1[i];
	}
	build(1,1,n);
	cin>>K;
	for (int i = 0; i < K; ++i)
	{
		cin>>letter;
		cin>>first>>second;
		switch(letter)
		{
			case 0:
			{
				// array1[first] = second;
				update(1,1,n, first, second);
				break;
			}
			case 1:
			{
				cout<<getsumm(1, 1, n, first, second,first,second)<<endl;
				break;
			}
		}
	}
	
	return 0;
}