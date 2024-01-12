#include "unionfind.h"

UnionFind::UnionFind(int size) {
    this->size = size;
    count = 0;
    parent = new int [size];
    rank = new int [size];
    for(int i=0; i<size; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}

void UnionFind::BuildWithEdges(vector<vector<int>>& edges) {
    for(const auto& edge: edges) {
        int a = edge[0];
        int b = edge[1];
        Union(a, b);
    }

}

int UnionFind::Find(int a) {
    if (parent[a] == a) return a;
    return Find(parent[a]);
}

void UnionFind::Union(int a, int b) {

    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA == rootB) return;
    if (rank[a] < rank[b]) {
        parent[a] = b;
        ++rank[a];
    }
    else 
    {
        parent[b] = a;
        ++rank[b];
    }
}

void UnionFind::PrintContents() {
    
    for(int i=0; i<size; i++) { 
        Map[parent[i]].push_back(i);
    }
    cout<<"Contents = "<<Map.size()<<endl;
    for(const auto& key: Map) {
        cout<<"Key ="<<key.first<<": ";
        for(const auto& val: key.second) {
            cout<<val<<" ";
        } 
        cout<<endl;
    }
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
 
    // Add w to v’s list.
    adj[v].push_back(w);
 
    // Add v to w’s list.
    adj[w].push_back(v);
}
 
// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
 
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
 
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[*i]) {
            if (isCyclicUtil(*i, visited, v))
                return true;
        }
 
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
            return true;
    }
    return false;
}
 
// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{
 
    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++) {
 
        // Don't recur for u if
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}


