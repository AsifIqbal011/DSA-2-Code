#include<iostream>
using namespace std;

int knapsack(int wts[],int prices[],int N,int W)
{
    if(N==0 || W==0)
    {
        return 0;
    }
    int inc=0,exc=0;
    if(wts[N-1]<=W)
    {
        inc=prices[N-1]+ knapsack(wts,prices,N-1,W-wts[N-1]);     //N-1 indexed wt ke niye
    }
    exc=knapsack(wts,prices,N-1,W);  //N-1 indexed wt ke na niye
    return max(inc,exc);            //je price ta beshi hobe seta return korbe
}

int main()
{
    int wts[]={2,7,4,3};
    int prices[]={5,14,20,10};
    int N=4,W=12;
    cout<<knapsack(wts,prices,N,W);

    return 0;
}
