#include <bits/stdc++.h>
using namespace std;
bool checkForCycle(int node,vector<int>adj[],int vis[],int dfsVis[]){
    vis[node]=1;
    dfsVis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(checkForCycle(it,adj,vis,dfsVis)){
                return true;
            }
        }
        else if(dfsVis[it]==1){
            return true;
        }
    }
    dfsVis[node]=0;
    return false;
}

bool isCycle(vector <int> adj[],int n){
    int vis[n+1];
    int dfsVis[n+1];
    memset(vis,0,sizeof(vis));
    memset(dfsVis,0,sizeof(dfsVis));

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkForCycle(i,adj,vis,dfsVis)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);    
    }

    if(isCycle(adj,n)){
        cout<<"Cycle detected !";
    }
    else{
        cout<<"Cycle not detected !";
    }
    
}