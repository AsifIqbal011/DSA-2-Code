#include<iostream>
#include<list>
#include<queue>
#include<vector>
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

    void addEdge(int i,int j)
    {
        l[i].push_back(j);
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

    void topological_sort()
    {
        vector<int> indegree(v,0);

        for(int i=0; i<v; i++)
        {
            for(auto nbr: l[i])
            {
                indegree[nbr]++;        //counting nbr for every node linerly
            }
        }
        queue<int> q;
        for(int i=0; i<v; i++)
        {
             if(indegree[i]==0)         //when no prerequisite left, push it to queue
                {
                    q.push(i);
                }
        }
        while(!q.empty())
        {
            int node= q.front();
            cout<<node<<" ";             //print the node, who have 0 indegree
            q.pop();                     //pop node from front

            for(auto nbr: l[node])
            {
                indegree[nbr]--;        //decrease indress by 1, of all nbr of the node that we pop already
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
    }

};

int main()
{
    Graph g(8);             //must be directed acyclic graph
    g.addEdge(0,7);
    g.addEdge(1,2);
    g.addEdge(4,5);
    g.addEdge(1,3);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(7,4);
    g.addEdge(6,7);

    g.print();
    g.topological_sort();
    return 0;
}

