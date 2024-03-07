#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class UnionFind {
    public:
        UnionFind(int);
        int Find(int);
        void Union(int, int);
        void BuildWithEdges(vector<vector<int>>&);
        void PrintContents();

    private:
        int size;
        int count;
        int *parent;
        int *rank;
        unordered_map<int, vector<int>> Map;
};


class Graph {
 
    // No. of vertices
    int V;
 
    // Pointer to an array
    // containing adjacency lists
    list<int>* adj;
    bool isCyclicUtil(int v, bool visited[], int parent);
 
public:
    // Constructor
    Graph(int V);
 
    // To add an edge to graph
    void addEdge(int v, int w);
 
    // Returns true if there is a cycle
    bool isCyclic();
   
};
 