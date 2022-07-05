#include <bits/stdc++.h>
using namespace std;

vector <int> topoSort(vector<int> adj[],int n){
 queue<int> q;
 vector <int> indegree(n,0);
 for(int i=0;i<n;i++){
    for(auto it:adj[i]){
        indegree[it]++;
    }
 }

for(int i=0;i<n;i++){
    if(indegree[i]==0){
        cout<<i<<"--\n";
        q.push(i);
    }
}

vector<int> topo;

while(!q.empty()){
    int node=q.front();
    q.pop();
    topo.push_back(node);
    for(auto it:adj[node]){
        indegree[it]--;
        if(indegree[it]==0){
            q.push(it);
        }
    }
}
return topo;

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

    vector<int> temp=topoSort(adj,n);

    for(auto x:temp){
        cout<<x<<" ";
    }
}