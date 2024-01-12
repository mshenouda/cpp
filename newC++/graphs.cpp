#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include <map>
#include <limits.h>
#include "unionfind.h"

using namespace std;


int dfs(vector<vector<int>>& adjList, int& src, int dst, vector<int>& visited) {

    if (src == dst) return true;
    visited[dst] = true;
    for(auto& neighbor: adjList[dst]) {
        cout<<"src = "<<src<<" dst = "<<dst<<" neighbor = "<<neighbor<<endl;
        if (!visited[neighbor])
            if (dfs(adjList, src, neighbor, visited));
                return true;
    }
    return false;
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {

    vector<vector<int>> adjList(n);
    vector<int> visited(n, false);
    
    for(const auto& edge: edges) {
        int src = edge[0];
        int dst = edge[1];
        adjList[src].push_back(dst);
        adjList[dst].push_back(src);
    }

    // for(int i=0; i<n; i++) {
    //     cout<<"i ="<<i<<endl;
    //     for(const auto neighbor: adjList[i]) {
    //         cout<<"neighbor = "<<neighbor<<endl;
    //     }
    // }

    int result = 0;
    for(int i = 0; i<n; i++)
    {   int src = i;
        if (!visited[src]) {
            visited[src] = true;
            if (adjList[src].size() == 0) { //lone node
                cout<<"src = "<<src<<endl;
                ++result;
                continue;
            }
            for(int j=i+1; j<n; j++) {
                int dst = j;
                if(!visited[dst])
                    if(dfs(adjList, src, dst, visited))
                        ++result;
            }
        }
    }
    return result;
}

vector<vector<int>> doAdjListUnDirectd(vector<vector<int>>& edges) {    

    int n = edges.size();
    vector<vector<int>> adjList(n+1, vector<int>()); 
    for(const auto& edge : edges) {
        auto a = edge[0];
        auto b = edge[1];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    return adjList;
}

vector<vector<int>> doAdjListDirected(vector<vector<int>>& edges) {    

    int n = edges.size();
    vector<vector<int>> adjList(n+1, vector<int>()); 
    for(const auto& edge : edges) {
        auto src = edge[0];
        auto dst = edge[1];
        adjList[src].push_back(dst);
    }
    return adjList;
}


void traverseBFS(vector<vector<int>>& adjList, int start=0){
    
    
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;
    int root = start;
    q.push(root);
    visited[root] = true;

    vector<int> results;
    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        results.push_back(currNode);
        for(const auto& node: adjList[currNode]) {
            if (!visited[node]) {
                visited[node] = true;    
                q.push(node);
            }
        } 
    };     
    cout<<"Result = ";
    for(const auto& result: results)
        cout<<result<<" ";
    cout<<endl;
}

void dfs(vector<vector<int>>& adjList, vector<int>& result, vector<bool>& visited, int currNode) {
    
    if (visited[currNode]) return;
    visited[currNode] = true;
    result.push_back(currNode);
    for(const auto& node: adjList[currNode]) {
        if(!visited[node])
            dfs(adjList, result, visited, node);
    }
}

void traverseDFS(vector<vector<int>>& adjList, int n=6) {
    
    vector<bool> visited(n, false);
    vector<int> result;
    vector<vector<int>> allNodes;
    int cnt=0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            vector<int> tmp;
            dfs(adjList, tmp, visited, i);
            allNodes.push_back(tmp);
            ++cnt;
        }
    }
    cout<<"Componenets = "<<cnt<<endl;
    cout<<"Result = ";
    for(const auto& list: allNodes) {
        cout<<"list =";
        for(const auto& node: list)
            cout<<node<<" ";
    }
    cout<<endl;
}


bool Kahn(vector<vector<int>>& adj) {
    
    int size = adj.size();
    vector<int> indegree(size, 0);
    queue<int> q;
    int visited = 0;
    for(int i=0; i< size; i++){
        for(const auto& node: adj[i]) {
            ++indegree[node];
        }
    }
    
    for(int i=0; i<size; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int curr = q.front();
        ++visited;
        q.pop();
        for(const auto& newNode: adj[curr]) {
            --indegree[newNode];
            if(indegree[newNode] == 0)
                q.push(newNode);        
        }
    };
    cout<<"visited = "<<visited<<" size = "<<size<<endl;
    return (visited != size);
}

int findMinIndex(vector<bool>& visited, int u, int v) {
    int minIndex = 0;
    visited[v] = true;

    int min = INT_MAX;

    if (adj[u][v] < min) {
        key[v] = min;
        minIndex = v;
    }
    return minIndex;
}

void MinimumSpanningTree(vector<vector<int>>& adj)
{
    int V = adj.size();
    bool visited[V];
    int key[V];
    int parent[V];

    for(int i; i<V; i++) {
        visited[i] = false;
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    //start with root
    visited[0] = true;
    key[0] = 0;

    for(int u = 0; u<V-1; u++) {
        for(int v=0; v<V; v++) {
            if(adj[u][v] != 0 && !visited[v] && adj[u][v] < key[v]) {
                findMinIndex(visited);
                parent[v] = u;
                ke 
            }
        }
    }

}

int main() {

    int n = 6;
    //vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    //vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}, {4, 3},{3,2}};
    //vector<vector<int>> adjList = doAdjListUnDirectd(edges);
    vector<vector<int>> adjList = doAdjListDirected(edges);
    // traverseBFS(adjList, 0);  
    // traverseDFS(adjList);
    //UnionFind ds(5);
    // ds.BuildWithEdges(edges);
    // ds.PrintContents();
    cout<<(Kahn(adjList) ? "Cycle": "NoCycle")<<endl;

    // Graph g1(5);
    // g1.addEdge(1, 0);
    // g1.addEdge(0, 2);
    // g1.addEdge(2, 1);
    // g1.addEdge(0, 3);
    // g1.addEdge(3, 4);
    // g1.isCyclic() ? cout << "Graph contains cycle\n"
    //               : cout << "Graph doesn't contain cycle\n";
 
    // Graph g2(3);
    // g2.addEdge(0, 1);
    // g2.addEdge(1, 2);
    // g2.isCyclic() ? cout << "Graph contains cycle\n"
    //               : cout << "Graph doesn't contain cycle\n";

    
    return 0;
}


