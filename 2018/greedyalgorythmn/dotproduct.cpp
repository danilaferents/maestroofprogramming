#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    int n=0;
    std::cin>>n;
    std::vector<long long> summs;
    for (int i=0;i<n;i++)
    {
        int size=0;
        int help=0;
        std::cin>>size;
        std::vector<long long> vector1,vector2;
        for (int j=0;j<size;j++)
        {
            std::cin>>help;
            vector1.push_back(help);
        }
        for (int j=0;j<size;j++)
        {
            std::cin>>help;
            vector2.push_back(help);
        }
        std::sort(vector1.begin(),vector1.end());
        std::sort(vector2.rbegin(),vector2.rend());
        long long summ=0;
        for (int j=0;j<size;j++)
        {
            summ+=(vector1[j]*vector2[j]);
        }
        summs.push_back(summ);
    }
    for (int i=0;i<n;i++)
    {
        std::cout<<"Case #"<<(i+1)<<": "<<summs[i]<<std::endl;
    }   
}