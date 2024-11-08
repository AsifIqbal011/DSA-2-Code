#include<iostream>
using namespace std;

int knapsack(int value[],int weight[],int c,int n)
{

    int dp[n+1][c+1];
    for(int i=0; i<=n; i++)
    {
        for(int k=0; k<=c; k++)
        {
            if(i==0||k==0) dp[i][k]= 0;
            else if(weight[i-1] <=k) dp[i][k]= max(dp[i-1][k],value[i-1]+dp[i-1][k-weight[i-1]]);
            else dp[i][k]=dp[i-1][k];

            }
    }
return dp[n][c];

}


int main()
{
    int value[]= {5,7,20,10,25};
    int weight[]= {1,3,2,2,4};
    int c=8;
    int n=sizeof(value)/sizeof(value[0]);       //number of item
    cout<<"max profit "<<knapsack(value,weight,c,n);
    return 0;
}
