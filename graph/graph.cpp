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

    void bfs(int source)
    {
        cout<<"BFS: ("<<source<<"): ";
        queue<int> q;
        bool *visited= new bool[v] {0};

        q.push(source);
        visited[source]=true;

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
                    visited[nbr]=true;
                }
            }
        }
        cout<<endl;
    }

    void dfsHelper(int source,bool *visited){
        visited[source]= true;
        cout<<source<<",";

        for(int nbr: l[source]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
    }
    void dfs(int source){
    cout<<"DFS: ("<<source<<"): ";
    bool *visited= new bool[v] {0};
    dfsHelper(source,visited);
    cout<<endl;
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

    void topological_sort(){
        vector<int> indegree(v,0);
        queue<int> q;
        for(int i=0;i<v;i++){
            for(auto nbr: l[i]){
                indegree[nbr]++;
            }
        }
        for(int i=0; i<v; i++)
        {
             if(indegree[i]==0)         //when no prerequisite left, push it to queue
                {
                    q.push(i);
                }
        }
        while(!q.empty()){
            int node= q.front();
            cout<<node<<" ";
            q.pop();

            for(auto nbr: l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
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
    g.addEdge(3,7,false);
    g.addEdge(3,0,false);  //directed
    g.dfs(7);
  //  g.bfs(7);
    g.dfs(4);
    g.bfs(6);
    g.print();
    g.topological_sort();
    return 0;
}
