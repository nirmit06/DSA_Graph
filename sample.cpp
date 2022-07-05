#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;

    vector <pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        //If graph is undirected
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

        //If graph is directed
        adj[u].push_back({v,w});
    }
}