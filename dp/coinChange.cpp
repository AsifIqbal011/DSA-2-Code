#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minCoin(int m,vector<int> coins)
{
    vector<int> dp(m+1,INT_MAX);
    dp[0]=0;
    for(int i=1; i<=m; i++)
    {
        for(int c: coins)
        {
            if(i-c>=0 && dp[i-c]!=INT_MAX)
            {
                dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
    }
    return dp[m]!=INT_MAX ?dp[m]:-1;
}
int main()
{
    int m;
    vector<int>coins= {1,5,7,10};
    cout<<"Enter value:";
    cin>>m;
    cout<<"Minimun coins for "<<m<<" is: "<<minCoin(m,coins);
    return 0;
}
