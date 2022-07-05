#include <bits/stdc++.h>
using namespace std;
bool checkForCycle(int node,int parent,vector<int>adj[],vector<int> &vis){
    vis[node]=true;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(checkForCycle(it,node,adj,vis)){
                return true;
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}

bool isCycle(vector <int> adj[],int n){
    vector<int> vis(n+1,0);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkForCycle(i,-1,adj,vis)){
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
        adj[v].push_back(u);
    }

    if(isCycle(adj,n)){
        cout<<"Cycle detected !";
    }
    else{
        cout<<"Cycle not detected !";
    }
    
}