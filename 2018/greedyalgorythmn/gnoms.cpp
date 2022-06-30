#include <iostream>
#include <vector>
#include<algorithm>
int main()
{
    int n=0;
    std::cin>>n;
    std::vector<int> vector1,vector2,vector3;
    int help=0;
    for (int i=0;i<n;i++)
    {
        std::cin>>help;
        vector1.push_back(help);
    }
    for (int i=0;i<n;i++)
    {
        std::cin>>help;
        vector2.push_back(help);
    }
    int max=0,maxi=0,summ=0,mini;
    for (int i=0;i<n;i++)
    {
         summ+=vector1[i];
        if (max<vector1[i])  
            {
                max=vector1[i];
                maxi=i;
            }
    }
    if((n==1) && (vector2[1]>0))
    {
        std::cout<<"1";
        return 0;
    }
    vector3.push_back(maxi);
    summ-=max;
    std::vector<int>::iterator result1 = std::min_element(vector2.begin(), vector2.end());
    std::vector<int>::iterator result;
    if (((summ) >= (max)) || (*result1 < (max-(summ))) || (vector2[maxi] <= summ)) 
    {
        std::cout<<"-1";
        return 0;
    }
    vector2.at(maxi)=0;
    vector1.at(maxi)=0;
    int ihelp=0;
    for(int i=0;i<n;i++)
    {
        result = std::max_element(vector2.begin(), vector2.end());
        ihelp=std::distance(vector2.begin(), result);
        summ-=vector1[ihelp];
        if(vector2[ihelp] <= summ) 
        {
            std::cout<<"-1";
            return 0;
        }
        vector2.at(ihelp)=0;
        vector3.push_back(ihelp);
    }
    for (int i=0;i<n;i++)
    {
        std::cout<<vector3[i]+1<< " ";
    }
}