#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &storeDfs){
    storeDfs.push_back(node);
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            dfs(x,vis,adj,storeDfs);
        }
    }
}
vector<int> dfsOfGraph(vector<int>adj[],int n){
    vector<int> storeDfs;
    vector<int> vis(n+1,0);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,vis,adj,storeDfs);
        }
    }
    return storeDfs;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans=dfsOfGraph(adj,n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    
}