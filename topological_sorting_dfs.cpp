#include <bits/stdc++.h>
using namespace std;

void topoSort(int node,vector<int> &vis,stack <int> &st,vector<int> adj[]){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it]){
            topoSort(it,vis,st,adj);
        }
    }
    st.push(node);
}
vector<int> dfs(vector <int> adj[],int n){
    vector <int> vis(n,0);
    stack <int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(i,vis,st,adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);    
    }

    vector<int> temp=dfs(adj,n);

    for(auto x:temp){
        cout<<x<<" ";
    }
}