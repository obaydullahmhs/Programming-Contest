#include<bits/stdc++.h>


using namespace std;

const int inf=INT_MAX/3;
const int N=2e5+10;
vector<pair<int,int>> adj[N], weight;
void Clear(int n){
    for(int i=0;i<=n+10;i++) adj[i].clear();
    weight.assign(n+10,make_pair(0,0));
}
void dfs(int node=1, int par=-1){

    for(auto it:adj[node]){
        if(it.first!=par){
            dfs(it.first,node);
            if(adj[it.first].size()==1){
                priority_queue<int> pq;
                pq.push(it.second);pq.push(weight[node].first);pq.push(weight[node].second);
                weight[node].first=pq.top();pq.pop();weight[node].second=pq.top();
            }else{
                int x=weight[it.first].first+it.second;
                priority_queue<int> pq;
                pq.push(x);pq.push(weight[node].first);pq.push(weight[node].second);
                weight[node].first=pq.top();pq.pop();weight[node].second=pq.top();
            }
        }

    }

}
int cs=0;
void solve(){
    int n;
    cin>>n;
    Clear(n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w; u++,v++;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    dfs();

    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,weight[i].first+weight[i].second);
    }
    cout<<"Case "<<++cs<<": ";
    cout<<ans<<endl;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int tc;
    cin>>tc;

    while(tc--){
        solve();
    }

}
