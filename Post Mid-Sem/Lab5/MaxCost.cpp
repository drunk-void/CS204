#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

class Graph {
    ll V;
    vector<vector<ll>> adj;
    void DFSUtil(int, bool visted[]);
    public :
        Graph(int V);
        void addEdge(int v, int w);
        void DFS(int v); 
};

Graph::Graph(int V) {
    this->V=V;
    
}