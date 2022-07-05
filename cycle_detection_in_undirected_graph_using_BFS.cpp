#include <bits/stdc++.h>
using namespace std;
bool checkForCycle(int s,vector<int>adj[],vector<int> &vis, int n){
    queue<pair<int,int>> q;

    vis[s]=true;
    q.push({s,-1});

    while(!q.empty()){
        int node=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=true;
                q.push({it,node});
            }
            else if(par!=it){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector <int> adj[],int n){
    vector<int> vis(n+1,0);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkForCycle(i,adj,vis,n))
            return true;
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