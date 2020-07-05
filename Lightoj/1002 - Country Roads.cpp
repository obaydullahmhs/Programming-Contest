#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int cs = 0;
const int inf = INT_MAX/2;
vector<vector<pair<int, int> > > adj;
void addEdge(int u, int v, int w){
    adj[u].emplace_back(v,w);
    adj[v].emplace_back(u,w);
}
void dijsktra(int start, vector<int>& ans){
    priority_queue<pair<int, int> > pq;
    pq.emplace(0, start); ans[start] = 0;
    while(!pq.empty()){
        auto out = pq.top(); pq.pop(); out.first = -out.first;
        for(auto in:adj[out.second]){
            if(max(ans[out.second],in.second)<ans[in.first]){
                ans[in.first] = max(ans[out.second], in.second);
                pq.emplace(-ans[in.first],in.first);
            }
        }
    }
}
void solve(){
    int n, k; scanf("\n%d %d",&n, &k);
    adj.clear(); adj.resize(n);
    for(int i = 0;i<k;i++){
        int u, v, w; scanf("%d %d %d",&u, &v, &w);
        addEdge(u,v,w);
    }
    int start; scanf("%d",&start);
    vector<int> ans(n, inf);
    dijsktra(start, ans);
    printf("Case %d:\n",++cs);
    for(int it:ans){
        if(it==inf) printf("Impossible\n");
        else printf("%d\n", it);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int tc=1; scanf("%d",&tc);
    while(tc--){
        solve();
    }
    return 0;
}
