#include <iostream>

using namespace std;

int main() {
	int x = 4, y = 9;

	if (!(x&1)) cout<<"Number "<<x<<" is even!"<<"\n";

	if (y&1) cout<<"Number "<<y<<" is not even"<<"\n";

	cout<<"22 and 26 = "<<(22 & 26)<<"\n";

	cout<<"22 or 26 = "<<(22 | 26)<<"\n";

	cout<<"22 xor 26 = "<<(22 ^ 26)<<"\n";

	x = 29;
	cout<<"x = "<<x<<" not x is: "<<~x<<"\n"; 

	//binary 

	x = 255;

	for(int k = 31; k >= 0; k--) {
		if (x & (1 << k)) cout<<"1";
		else cout<<"0";
	}

	cout<<"\n";

	x = x | (1 << 8);

	for(int k = 31; k >= 0; k--) {
		if (x & (1 << k)) cout<<"1";
		else cout<<"0";
	}

	cout<<"\n"<<"x = 256 + 255 =  "<<x<<"\n";

	x = 64;

	if ((x & (x - 1)) == 0) cout<<"x is power of 2!"<<"\n";
	else cout<<"x is not a power of 2!"<<"\n";

	cout<<(1LL<<35)<<"\n";


	cout<<"Количество нулей в двоичном представлении: "<<__builtin_clz(x)<<"\n";
	
	cout<<"Количество нулей в двоичном представлении в конце: "<<__builtin_ctz(x)<<"\n";

	cout<<"Количество единиц в двоичном представлении: "<<__builtin_popcount(x)<<"\n";

	cout<<"Четность количества единиц в двоичном представлении:  "<<__builtin_parity(x)<<"\n";

	 bitset<10> s, a , b , c;

	 s[0] = 1;

	 c = a & b;
}