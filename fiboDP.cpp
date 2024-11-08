#include<iostream>
using namespace std;

int fibo(int n,int memo[])
{
    if(n==0 || n==1) return memo[n]= n;
    else return memo[n]=fibo(n-1,memo)+fibo(n-2,memo);
}

int memorization(int n)
{
    int memo[n+1];
    for(int i=0; i<=n; i++)
    {
        memo[i]=-1;
    }
    int ans=fibo(n,memo);

  //  for(int i=0; i<=n; i++)
  //  {cout<<memo[i]<<" ";}
  //  cout<<endl;

    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<memorization(n);

    return 0;
}
