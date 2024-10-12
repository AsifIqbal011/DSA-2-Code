#include<iostream>
#include<vector>
#include <map>
#include <list>
#include<climits>
using namespace std;
int minCoin(int m,vector<int> coins)
{
    vector<int> dp(m+1,INT_MAX);
    map<int, list<int> > coinList;
    dp[0]=0;
    for(int i=1; i<=m; i++)
    {
        for(int c: coins)
        {
            if(i-c>=0 && dp[i-c]!=INT_MAX)
            {
                if(dp[i]>=dp[i-c]+1)
                {
                    coinList[i].clear();
                    dp[i]=dp[i-c]+1;
                    coinList[i].push_back(c);

                    auto it = coinList.find(i-c);
                    if (it != coinList.end())
                    {
                        for (int value : it->second)
                        {
                             coinList[i].push_back(value);
                        }
                    }
                }

            }
        }
    }
    auto it = coinList.find(m);
    if (it != coinList.end())
    {
        for (int value : it->second)
        {
            cout << value << " ";
        }
        cout<<endl;
    }

    return dp[m]!=INT_MAX ?dp[m]:-1;
}
int main()
{
    int m;
    vector<int>coins= {1,5,7,10};
    cout<<"We have coin: 1,5,7,10 only"<<endl;
    cout<<"Enter value:";
    cin>>m;
    int k=minCoin(m,coins);
    cout<<"Minimun coins for "<<m<<" is: "<<k<<endl;
    return 0;
}
