#include <bits/stdc++.h>


void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, set<int>> &adjList, vector<int> &components){

    components.push_back(node);
    vis[node]=1;

    for(auto i: adjList[node]){
        if(!vis[i]){
           dfs(i,vis,adjList,components); 
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,set<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> vis;

    //traversing all components of graph

    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> components;
            dfs(i,vis,adjList,components);
            ans.push_back(components);
        }
    }
    return ans;

}