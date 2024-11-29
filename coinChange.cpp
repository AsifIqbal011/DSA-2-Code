#include<bits/stdc++.h>
using namespace std;

int coinchange(int c[],int n, int i)
{
    if(n==0)return 0;
    if(c[i]<=n)return 1+coinchange(c,n-c[i],i);        //remain update
    else return coinchange(c,n,i+1);                   //coin update
}

static bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int c[]= {50,20,10,25,5};
    int n=40;                //not giving optimal solution for 40
    int len=sizeof(c)/sizeof(c[0]);


    sort(c,c+len,cmp);
    cout<<coinchange(c,n,0);
    return 0;
}
