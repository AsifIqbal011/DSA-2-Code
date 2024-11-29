#include<iostream>
#include <queue>
using namespace std;
int V = 5;
int visited[5];
int G[5][5] =
{
    {0,1,0,0,1},
    {1,0,0,1,1},
    {0,0,0,1,0},
    {0,1,1,0,1},
    {1,1,0,1,0}
};
void BFS(int v)
{
    queue<int> Q;
    visited[v] = 1;
    cout<<v<<" ";
    Q.push(v);

    while(!Q.empty())
    {
        int current = Q.front();
        Q.pop();
        for(int j=0; j<V; j++)
        {
            if(G[current][j]==1 && visited[j]==0)
            {
                visited[j] = 1;
                cout<<j<<" ";
                Q.push(j);
            }
        }

    }
}
int main()
{
    BFS(0);
}
