#include <bits/stdc++.h> 

void prepareAdjList(unordered_map<int, set<int>> &adjList,vector<pair<int, int>> edges){

for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;


// here we can use list in place of set in declaring adjList , In that 
//case we have to just do adjList[u].push_back(v).

    adjList[u].insert(v);
    adjList[v].insert(u);


}
}

void bfs(unordered_map<int,bool> &visited, unordered_map<int, set<int>> &adjList, vector<int> &ans, int node){
    queue <int> q;
    q.push(node);

    visited[node]=1;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }


}


vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here

    unordered_map<int, set<int>> adjList;
    unordered_map<int,bool> visited;
    vector<int> ans;


    prepareAdjList(adjList,edges);

// traversing all components of the graph

for(int i=0;i<vertex;i++){
    if(!visited[i]){
        bfs(visited,adjList,ans,i);
    }
}
return ans;
}