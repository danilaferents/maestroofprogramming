
#include<climits>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
#include <set>
#include <queue>
#include <string>
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
int whichnumberend;
int numbertops;
bool  deikstra(int whichtop, const vector < vector <pair<int,char>> > &graph,string &name)
{
	priority_queue <int> queue;
	vector<int> distances (numbertops+1,INT_MAX);
	set<char> letters;
	distances[whichtop]=0;
	queue.push(whichtop);
	while(!queue.empty())
	{
		int current=queue.top();
		queue.pop();
		if(current == whichnumberend) break;
		for (int i = 0; i < graph[current].size(); ++i)
		{
			int now=graph[current][i].first;
			char charnow=graph[current][i].second;
			if(distances[now] > (distances[current] + 1))
			{
				distances[now]=distances[current] + 1;
				letters.insert(charnow);
				queue.push(now);
			}
		}
	}
	bool what=true;
	// cout<<endl<<whichtop<<endl;
	for(int i=0;i<name.size();i++)
	{
		if (letters.find(name[i])==letters.end()) what=false;
		// cout<<i<<" ";
	}
	return what;
}
int main()
{
	string name,helpname="love";
	std::getline(std::cin, name);
	name=helpname+name;
	int whichnumberbegin;
	cin>>numbertops>>whichnumberbegin>>whichnumberend;
	vector < vector <pair<int,char> > > graph(numbertops+1);
	// numbertops=readInt();
	int first,second;
	char third;
	for (int i = 0; i <(numbertops-1); ++i)
	{
		// first=readInt();
		// second=readInt();
		// third=readChar();

		cin>>first>>second>>third;
		graph[first].push_back(make_pair(second,third));
		graph[second].push_back(make_pair(first,third));
	}
	
	if(deikstra(whichnumberbegin,graph,name)) cout<<"Surprise";
		else cout<<"Fail";
}