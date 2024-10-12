#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class Node
{
public:
    string name;
    list<string> nbrs;

    Node(string name)
    {
        this->name =name;
    }
};

class Graph
{
    unordered_map<string,Node*> m;

public:
    Graph(vector <string> cities)
    {
        for(auto city: cities)
        {
            m[city]= new Node(city);
        }
    }

    void addEdge(string x, string y,bool undir=false)
    {
        m[x]->nbrs.push_back(y);
        if(undir)
        {
            m[y]->nbrs.push_back(x);
        }
    }

    void print()
    {
        for(auto cityPair: m)
        {
            auto city= cityPair.first;
            Node *node= cityPair.second;
            cout<<city<<"-->";
            for(auto nbr: node->nbrs)
            {
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    vector<string> cities= {"Dhaka","Khulna","USA","UK","Finland","Iceland"};
    Graph g(cities);
    g.addEdge("Dhaka","Khulna");
    g.addEdge("UK","Iceland");
    g.addEdge("USA","UK");
    g.addEdge("USA","Khulna");
    g.addEdge("Dhaka","Iceland",true);
    g.addEdge("Dhaka","Finland");
    g.addEdge("Finland","USA");

    g.print();
    return 0;
}
