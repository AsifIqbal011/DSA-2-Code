#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

class Graph {
    int v;
    list<pair<int, int>> *l;

public:
    Graph(int v) {
        this->v = v;
        l = new list<pair<int, int>>[v];
    }

    void addEdge(int i, int j, int wt, bool undir = true) {
        l[i].push_back({j, wt});
        if (undir) {
            l[j].push_back({i, wt});
        }
    }

    int dijkstra(int src, int dest) {
        vector<int> dist(v, INT_MAX);
        set<pair<int, int>> s;

        dist[src] = 0;
        s.insert({src, 0 });

        while (!s.empty()) {
            auto it = s.begin();
            int node = it->first;
            int disTillNow = it->second;
            s.erase(it);

            for (auto nbrPair : l[node]) {
                int nbr = nbrPair.first;
                int currentEdge = nbrPair.second;

                if (disTillNow + currentEdge < dist[nbr]) {
                    auto f = s.find({nbr, dist[nbr]});
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    dist[nbr] = disTillNow + currentEdge;
                    s.insert({nbr, dist[nbr]});
                }
            }
        }

        for (int i = 0; i < v; i++) {
            cout << "Node " << i << "  Dist " << dist[i] << endl;
        }
        return dist[dest];
    }

    void print() {
        for (int i = 0; i < v; i++) {
            cout << i << "-->";
            for (auto node : l[i]) {
                cout << "(" << node.first << ", " << node.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0,1,10);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(4,3,4);
    g.addEdge(3,2,2,false);
   // g.addEdge(3,4,3);
    g.addEdge(4,5,2);
    g.addEdge(6,5,3);
    g.addEdge(6,0,8);
    g.print();

    int start,EndPoint;
    cout<<"Enter start,End point: ";
    cin>>start>>EndPoint;
    cout << "Shortest distance from "<<start<<" to "<<EndPoint<<" :  "<<endl<< g.dijkstra(start,EndPoint) << endl;

    return 0;
}
