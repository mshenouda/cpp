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


vector<int> traverseBFS(vector<vector<int>>& adjList, int start=0){
    
    
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;
    int root = start;
    q.push(root);

    vector<int> results;
    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        visited[currNode] = true;
        results.push_back(currNode);
        for(const auto& node: adjList[currNode]) {
            if (!visited[node])
            q.push(node);
        } 
    };     
    cout<<"Result = ";
    for(const auto& result: results)
        cout<<result<<" ";
    cout<<endl;
    return results;
}

void traverseDFS() {


}

int main() {

    int n = 6;
    //vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    vector<vector<int>> adjList = doAdjListDirected(edges);
    vector<int> result = traverseBFS(adjList);   
    return 0;
}


