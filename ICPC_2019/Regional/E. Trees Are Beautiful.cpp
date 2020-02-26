/*
Autor: Obaydullah
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e4+25;
vector<pair<int,ll>> adj[N];
priority_queue<pair<ll,ll>> pq;
ll weight[N];
ll subNode[N];
void dfs(ll node,ll par){
    subNode[node]=1;
    for(auto it:adj[node]){
        if(it.first!=par){
            weight[it.first]=it.second;
            dfs(it.first,node);
            subNode[node]+=subNode[it.first];
        }
    }
}
void Clear(){
    while(!pq.empty()) pq.pop();
    for(ll i=0;i<N;i++) adj[i].clear();
    memset(weight,0,sizeof weight);
    memset(subNode,0, sizeof subNode);
}
int cs=0;
void solve(){
    int n;
    cin>>n;
    Clear();

    for(ll i=1;i<n;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    dfs(1,1);
    ll allPairSum=0;

    for(ll i=2;i<=n;i++){
        int downSub=subNode[i];
        int upSub=n-downSub;
        ll contribution=downSub*upSub;
        allPairSum+=(contribution*weight[i]);
        if(weight[i]<0) pq.push(make_pair(contribution,-weight[i]));
    }

    ll ans=0;
    while (allPairSum<0)
    {
        assert(!pq.empty());
        auto unBox=pq.top();pq.pop();
        ll need=(abs(allPairSum)+unBox.first-1)/unBox.first;
        need=min(need,unBox.second);
        ans+=need;
        allPairSum+=(need*unBox.first);
    }
    cout<<"Case "<<++cs<<": ";
    cout<<ans<<endl;

}
int main() {

    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int tc=1;
	cin>>tc;
	while(tc--){
        solve();
	}
	return 0;
}
