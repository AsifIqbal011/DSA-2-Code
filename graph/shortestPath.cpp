#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int v;
    list<int> *l;
public:
    Graph(int v)
    {
        this->v=v;
        l= new list<int>[v];
    }

    void addEdge(int i,int j,bool undir=true)
    {
        l[i].push_back(j);

        if(undir)
        {
            l[j].push_back(i);
        }
    }

    void bfs(int source, int dest=-1)
    {
        cout<<"BFS: ("<<source<<"): ";
        queue<int> q;
        bool *visited= new bool[v] {0};
        int *dist = new int[v]{0};
        int *parent = new int[v];

        q.push(source);
        visited[source]=true;
        parent[source]= source;
        dist[source]= 0;

        while(!q.empty())
        {
            int f= q.front();
            cout<<f<<",";
            q.pop();

            for(auto nbr: l[f])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    parent[nbr]=f;
                    dist[nbr]=dist[f]+1;
                    visited[nbr]=true;
                }
            }
        }
        cout<<endl;
        for(int i=0;i<v;i++){
            cout<<"shortest path of: "<<i<<" is "<<dist[i]<<endl;
        }

        if(dest!=-1){
            int temp= dest;
            cout<<"THE PATH: ";
            while(temp!=source){
                cout<<temp<<"<-";
                temp=parent[temp];
            }
            cout<<source<<endl;
        }



    }

    void print()
    {
        for(int i=0; i<v; i++)
        {
            cout<<i<<"-->";
            for(auto node: l[i])
            {
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(4,5);
    g.addEdge(1,3);
    g.addEdge(2,0);
    g.addEdge(3,4);
    g.addEdge(4,6);
    g.addEdge(0,6);
    g.addEdge(3,7);
    g.addEdge(3,0,false);  //directed

    g.bfs(1,5);
    g.print();

    return 0;
}

