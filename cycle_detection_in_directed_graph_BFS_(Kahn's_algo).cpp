#include <bits/stdc++.h>
using namespace std;

bool isCyclic(vector<int> adj[],int n){
 queue<int> q;
 vector <int> indegree(n,0);
 for(int i=1;i<=n;i++){
    for(auto it:adj[i]){
        indegree[it]++;
    }
 }

for(int i=1;i<=n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}

int cnt=0;

while(!q.empty()){
    int node=q.front();
    cout<<node<<"\n";
    q.pop();
    
    cnt++;
    for(auto it:adj[node]){
        indegree[it]--;
        if(indegree[it]==0){
            q.push(it);
        }
    }
}
if(cnt==n) 
return false;
else 
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
    }

    if(isCyclic(adj,n)){
        cout<<"Cycle Detected !"<<"\n";
    }
    else{
        cout<<"Cycle not detected !"<<"\n";
    }
}