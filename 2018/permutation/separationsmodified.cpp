
#include<climits>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <set>
using namespace std;
vector<int> a;
set<int> sum;
int size1;
int summ=0;
void Partition(int n, int high,int last,int howmany)
{ 
  if(n!=0)
  {
    for (int i = 1; i <=high; ++i)
    {
        // cout<<"BEFORE"<<endl;
        // cout<<"n: "<<n<<" last: "<<last<<" i: "<<i<<" howmany: "<<howmany<<" summ: "<<summ<<endl;
        if ((last == i) || (last == 0))
        {
          Partition(n-i,min(n-i,i),i,howmany+1);;
        }
        if ((last!=i) && (last != 0))
        {
          if (sum.find(howmany) != sum.end())
            continue;
          else
          {
            sum.insert(howmany);
            Partition(n-i,min(n-i,i),i,1);
          }
        }
        // cout<<"AFTER"<<endl;
        // cout<<"n: "<<n<<" last: "<<last<<" i: "<<i<<" howmany: "<<howmany<<" summ: "<<summ<<endl;
        // for(auto i:sum)
        //   cout<<"i: "<<i<<endl;
        // // Partition(n-i,min(n-i,i),i,howmany);
        // cout<<"AFTERREC"<<endl;
        // cout<<"n: "<<n<<" last: "<<last<<" i: "<<i<<" howmany: "<<howmany<<" summ: "<<summ<<endl;
        if (last != i) sum.erase(howmany);
        // cout<<"AFTERRECDEL"<<endl;
        // cout<<"n: "<<n<<" last: "<<last<<" i: "<<i<<" howmany: "<<howmany<<" summ: "<<summ<<endl;
        
    } 
  }
  else
  {
      // cout<<"n: "<<n<<" last: "<<last<<" howmany: "<<howmany<<" summ: "<<summ<<endl;
      // cout<<endl<<endl<<endl;
     if (sum.find(howmany) != sum.end())
     {
        // howmany--;
        return;
     }
      else
      {
        // howmany--;
        summ++;
        return;
      }
  }
}
int main()
{
   ios_base::sync_with_stdio(0); 
  cin.tie(0);
  cin>>size1;
  for (int i = 0; i < size1; ++i)
  {
    a.push_back(0);
  }
  Partition(size1,size1,0,0);
  std::cout << summ;
  return 0;
}