#include <iostream>
#include <vector>
#include<algorithm>
int main()
{
    int n=0;
    std::cin>>n;
    std::vector<std::pair<std::pair<int,int>,int> > vector1(n);
    int help1=0;
    for (int i=0;i<n;i++)
    {
        std::cin>>help1;
        vector1[i].first.first=help1;
        vector1[i].second=i;
    }
    for (int i=0;i<n;i++)
    {
        std::cin>>help1;
        vector1[i].first.second=help1;
    }

    std::sort(vector1.begin(), vector1.end(), [](const std::pair<std::pair<int,int>,int> &left, const std::pair<std::pair<int,int>,int> &right)
        {
            return (left.first.first+left.first.second) > (right.first.first+right.first.second);
        });
    int help=vector1[0].first.second;
    for (int i=1;i<n;i++)
    {
        help=std::min(help-(vector1[i].first.first),vector1[i].first.second);
        if (help<=0)
        {
            std::cout<<"-1";
            return 0;
        }
    }
    for (int i=0;i<n;i++)
    {
        std::cout<<vector1[i].second+1<<" ";
    }

}