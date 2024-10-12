#include<iostream>
using namespace std;
int maxPriceWine(int dp[][10],int prices[],int i,int j, int year)
{

    if(i>j){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];        //already visited
    }
    int sell_left= year*prices[i]+ maxPriceWine(dp,prices,i+1,j,year+1);
    int sell_right= year*prices[j]+ maxPriceWine(dp,prices,i,j-1,year+1);

    return dp[i][j]=max(sell_left,sell_right);
}

int main()
{
    int dp[10][10]={0};
    int prices[]= {2,3,5,1,4};
    int n=sizeof(prices)/sizeof(prices[0]);
    cout<<maxPriceWine(dp,prices,0,n-1,1)<<endl;
    return 0;
}
