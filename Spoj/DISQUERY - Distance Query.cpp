#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class LCA{
private:
    int N,LogV; const int inf = INT_MAX/3;
    vector<vector<int> > sparse, maxsparse, minsparse;
    vector<vector<pair<int, int> > > adj;
    vector<int> depth;
public:
    LCA(int _N):N(_N),LogV(log2(N)+1), sparse(LogV+2, vector<int>(N+2,-1)),maxsparse(LogV+2, vector<int>(N+2,-1)),
    minsparse(LogV+2, vector<int>(N+2,inf)),depth(N+2,0), adj(N+2){}
    inline void addEdge(int u, int v, ll w){
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    void dfs(int node, int par, int val){
        if(par!=-1){
            sparse[0][node] = par;
            minsparse[0][node]=val;
            maxsparse[0][node]=val;
            depth[node]=depth[par]+1;
        }
        for(int i = 1; i < LogV+2; i++) {
            if(sparse[i - 1][node] != -1) {
                sparse[i][node] = sparse[i-1][sparse[i - 1][node]];
                maxsparse[i][node] = max(maxsparse[i - 1][node], maxsparse[i-1][sparse[i - 1][node]]);
                minsparse[i][node] = min(minsparse[i - 1][node], minsparse[i-1][sparse[i - 1][node]]);
            }
            else {
                break;
            }
        }
        for(auto it:adj[node]){
            if(it.first!=par){
                dfs(it.first, node,it.second);
            }
        }
    }
    inline pair<int, int> findLCA(int u, int v){
        pair<int, int> ans(-1, inf);
        if(depth[u]>depth[v]) swap(u,v);
        for(int i = LogV+1; i >= 0; i--) {
            if(sparse[i][v] != -1 && depth[sparse[i][v]] >= depth[u]) {
                ans.second = min(ans.second, minsparse[i][v]);
                ans.first = max(ans.first, maxsparse[i][v]);
                v = sparse[i][v];
            }
        }
        if(u==v){
            return ans;
        }
        for(int i = LogV+1; i >= 0; i--) {
            if(sparse[i][v] != sparse[i][u]) {
                ans.second = min(ans.second, minsparse[i][v]);
                ans.first = max(ans.first, maxsparse[i][v]);
                ans.second = min(ans.second, minsparse[i][u]);
                ans.first = max(ans.first, maxsparse[i][u]);
                v = sparse[i][v];
                u = sparse[i][u];
            }
        }
        ans.second = min(ans.second, minsparse[0][v]);
        ans.first = max(ans.first, maxsparse[0][v]);
        ans.second = min(ans.second, minsparse[0][u]);
        ans.first = max(ans.first, maxsparse[0][u]);
        return ans;
    }

};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    LCA lca(n);

    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        lca.addEdge(u,v,w);
    }

    lca.dfs(1,-1, 0);

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        pair<int, int> ans = lca.findLCA(a,b);
        cout<<ans.second<<" "<<ans.first<<"\n";
    }

	return 0LL;
}
