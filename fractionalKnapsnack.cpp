#include<bits/stdc++.h>
using namespace std;

struct item
{
    int profit,weight;

    item(int profit,int weight)
    {
        this->profit=profit;
        this->weight=weight;
    }
};
bool cmp(item a,item b)
{
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}

double fracKnapsack(item p[],int c,int n)
{
    double totalValue=0;
    for(int i=0; i<n; i++)
    {
        if(p[i].weight<=c)
        {
            c-=p[i].weight;
            totalValue+=p[i].profit;
        }
        else
        {
            double frac=c/(double)p[i].weight;
            totalValue+=frac*p[i].profit;
            break;
        }
    }
    return totalValue;
}
int main()
{
    item p[]= {{10,2},{20,5},{7,2},{3,1}};
    int c=8;
    int n=sizeof(p)/sizeof(p[0]);
    sort(p,p+n,cmp);

    cout<<fracKnapsack(p,c,n);
    return 0;
}
