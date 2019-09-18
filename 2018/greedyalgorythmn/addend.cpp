#include <iostream>
#include <vector>
int main()
{
    int n=0,i=1,size=0;
    std::vector<int> array;
    std::cin>>n;
    while(n!=0)
    {
        if(((n-i) >= (i+1)) ||  ((n-i) == 0))
            {
                array.push_back(i);
                n-=i;
                size++;
            }
        i++;
    }
    std::cout<<size<<std::endl;
    for(int j=0;j<array.size();j++)
    {
        std::cout<<array[j]<<" ";
    }
}