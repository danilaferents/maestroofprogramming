#include<stdio.h>
#define MIN(x, y)  ((x) < (y) ? (x) : (y))
long a[100];
FILE *g;
 
void Partition(long n, long high, long pos)
{
   long i;
   if (n > 0)
   {
       for (i = 1; i <= high; i++)
       {
          a[pos] = i;
          Partition(n - i, MIN(i, n - i), pos + 1);
       }
   }
   else
   {
       for (i = 0; i < pos; i++)
          printf( "%ld ", a[i]);
       printf( "\n");
   }
}
 
int main()
{
   long n;
   printf("n = ");
   scanf("%ld", &n);
   Partition(n, n - 1, 0);
   return 0;
}
// #include<climits>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <map>
// using namespace std;
// vector<int> a;
// map<int,int> sum;
// int size;
// int summ=0;
// void Partition(int n, int high,int last,int howmany)
// {
//   if (n)
//   {
//       for (int i = 1; i <= high; i++)
//       {
//           if ((i != last) && (last!=0))
//           {
//             if (sum.find(howmany) !=sum.end())
//             {
//                  return;
//              }
//             else
//             {
//               sum[howmany] = sum[howmany] + 1;
//               howmany=1;
//             }
//           }
//           if ((i==last)||(last==0))
//           {
//             howmany+=1;
//           }
//           cout<<"n: "<<n<<" last: "<<last<<" i: "<<i<<" howmany: "<<howmany<<"summ: "<<summ<<endl;
//           for(auto i:sum)
//           cout<<"i: "<<i.first<<" value : "<<i.second<<endl;
//           Partition(n - i, min(i, n - i), i,howmany);
//           if (i != last)
//           {
//               auto t=sum.find(howmany);
//               if (t!=sum.end())
//               {
//               if (t->second==1) sum.erase(howmany);
//               if (t->second > 1) sum[howmany]-=1;
//             }
//           }
//           howmany--;
//       }
//     }
//    else
//    {
//     cout<<"n: "<<n<<" last: "<<last<<" howmany: "<<howmany<<endl;
//           for(auto i:sum)
//           cout<<"i: "<<i.first<<" value : "<<i.second<<endl;
//       if (sum.count(howmany) !=0)
//       {
//         return;
//       }
//       else
//       {

//          summ+=1;
//         return;
//     }
//    }

// }

// int main()
// {
//    ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cin>>size;
//   for (int i = 0; i < size; ++i)
//   {
//     a.push_back(0);
//   }
//   Partition(size,size,0,0);
//   std::cout << summ;
//   return 0;
// }
// #include<climits>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <map>
// using namespace std;
// int size;
// std::vector<int> array1;
// int countofsuch=0;
// bool checkthis()
// {
//     for (int i = 0; i < array1.size(); ++i)
//     {
//         for (int j = i; j < array1.size(); ++j)
//         {
//             if((array1[i]!=0)&&(array1[i]==array1[j])&&(i!=j)) return false;
//         }
//     }
//     return true;
// }
// void generate(int summ,int k,int last)
// {
//   if(summ > 0)
//   {

//       for (int i = summ; i > 0; --i)
//       {if(i!=last){
// //        for (int p = 0; p < k; ++p)
// //        {
// //          cout<<".";
// //        }
// //          cout<<"Inputtoarray: "<<summ/i<<" x "<<i<<"summ: "<<summ-(summ/i)*i<<endl;
//           if((summ/i>1)&&(summ%i==0)&&(i!=1))
//           {
//                 for (int j = summ/i; j >=1; --j)
//                 {
//                     array1.push_back(j);
//                     generate(summ-((j)*i),k+=1,i);
//                     array1.pop_back();
//                     k--;
//                 }
//           }
//           if((summ%i!=0) || (i==1) ||(summ/i==1))
//           {
//             array1.push_back(summ/i);
//             generate(summ-((summ/i)*i),k+=1,i);
//             array1.pop_back();
//             k--;
//           }
//       }}
//   }
//   else
//   {
// //      cout<<"here"<<endl;
// //      for (int i = 0; i < array1.size(); ++i)
// //      {
// //          cout<<array1[i]<<" ";
// //      }
// //      cout<<endl;
//       if(checkthis()) countofsuch++;
//   }

//     // if (sum==0)
//     // {
//     //     if(checkthis(last))
//     //     {
//     //         countofsuch++;
//     //     }
//     //     return;
//     // }
//     // for (int j=1; j<=sum;++j)
//     // {
//     //     // cout<<sum<<" ";
//     //     array1[j]+=1;
//     //     generate(last+=1,sum-j);
//     //     array1[j]--;
//     //     last--;
//       // }
// }
// int main()
// {
//    ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>size;
//     generate(size,1,101);
//     cout<<countofsuch;
// }

