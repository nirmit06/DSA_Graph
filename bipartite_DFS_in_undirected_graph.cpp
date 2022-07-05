#include <bits/stdc++.h>
using namespace std;
bool bipartiteDfs(int node,vector<int>adj[],int color[]){
    if(color[node]==-1) color[node]=1;

    for(auto it:adj[node]){
        if(color[it]==-1){
            color[it]=1-color[node];
            if(!bipartiteDfs(it,adj,color)){
                return false;
            }
        }
        else if(color[it]==color[node]){
            return false;
        }
    }
    return true;

}

bool isBipartite(vector <int> adj[],int n){
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bipartiteDfs(i,adj,color))
            return false;
        }
    }
    return true;
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

    if(isBipartite(adj,n)){
        cout<<"Graph is bipartite !";
    }
    else{
        cout<<"Graph is not bipartite !";
    }


    
}