
#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
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
} 
int main()
{
	int numbertops=0,numberribs;
	numbertops=readInt();
	numberribs=readInt();
	int array[numbertops][numbertops];
	int first,second;
	for (int k=0; k<numbertops; ++k)
		for (int i=0; i<numbertops; ++i)
		{
			if(k == i) array[k][i]=0; 
			else array[k][i]=INT_MAX;
		}
	for(int i=0;i<numberribs;i++)
	{
		first=readInt();
		second=readInt();
		if (first!=second)
		{
			array[first-1][second-1]=1;
			array[second-1][first-1]=1;
		}
	}
	for (int k=0; k<numbertops; ++k)
		for (int i=0; i<numbertops; ++i)
			for (int j=0; j<numbertops; ++j)
				if (array[i][k] < INT_MAX && array[k][j] < INT_MAX)
					array[i][j] = min (array[i][j], array[i][k] + array[k][j]);

	long long summ=0;
	for (int k=0; k<numbertops; ++k)
		for (int i=0; i<numbertops; ++i)
		{
			if(array[k][i] != INT_MAX) summ+=array[k][i];
			// cout<<array[k][i]<<" ";
		}
	cout<<summ/2;
}