#include<iostream>
#include<vector>
using namespace std;
int maxPriceWine(vector<int> wines)
{
    int n=wines.size();
    int price=0,i=0,j=n-1,days=1;
    while(i<=j)
    {
        if(wines[i]>=wines[j])
        {
            price+=wines[j]*days;
            j--;
        }
        else
        {
            price+=wines[i]*days;
            i++;
        }
        days++;
    }

    return price;
}

int main()
{
    vector<int> wines= {2,3,5,1,4};
    cout<<maxPriceWine(wines)<<endl;
    return 0;
}
