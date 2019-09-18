#include <iostream>
#include <vector>
#include <algorithm> 
#include <set> 
#include <map> 
#include <math.h> 
using namespace std;
#include <cstdio>
#include <cassert>

/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;


struct Fraction { 
    int num, den; 
};  

struct cmp
{
	bool operator() (const Fraction &first,const Fraction &sec)
	{
		if(sec.den==0) return true;
		long long Y = (long long) first.num * (long long)sec.den  - (long long) sec.num * (long long)first.den; 
   		return (Y > 0) ? true : false; 
	}
};
// Get max of the two fractions 
bool maxFraction(const Fraction &first,const Fraction &sec) 
{ 
	if(sec.den==0) return true;
   long long Y = (long long) first.num * (long long)sec.den  - (long long) sec.num * (long long)first.den; 
  
    return (Y > 0) ? true : false; 
} /*
int gcd (int a, int b) 
{
    while (a != b)
      if (a > b) a -= b; else b -= a;
    return a;
}*/
int main()
{
	map<int, Fraction> array;
	set<Fraction,cmp> degree;
	int n=0,first=0,second=0;
	n=readInt();
	for (int i=0;i<n;i++)
	{ 
		first=readInt();
		second=readInt();
		//int helpev=gcd(first,second);
		Fraction help={second,first};
		Fraction &temp1=array[first];
		if (maxFraction(help,temp1))  temp1=help;
	}
	int k=0;
	auto it=array.begin();
	while(it != array.end())
	{
		degree.insert(it->second);
		it++;
	}
	cout<<degree.size()<<endl;
}
