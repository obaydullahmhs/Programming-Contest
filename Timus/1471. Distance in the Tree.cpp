#include <bits/stdc++.h>

using namespace std;

class LCA{
private:
    int N,LogV;
    vector<vector<int> > sparse;
    vector<int> depth;
    vector<int> dist;
public:
    vector<vector<pair<int,int>> > adj;
    LCA(){
        N=20000;
        LogV=20;
    }
    ///Initializing
    void init(int n){
        N=n;
        sparse=vector<vector<int> >(LogV+5,vector<int>(N+10,-1));
        depth=vector<int>(N+10,0);
        dist=vector<int>(N+10,0);
        adj=vector<vector<pair<int,int>> >(N+10);
    }
    ///DFS
    void dfs(int node, int par){
        for(auto it:adj[node]){
            if(it.first!=par){
                sparse[0][it.first]=node;
                depth[it.first]=depth[node]+1;
                dist[it.first]=dist[node]+it.second;
                dfs(it.first, node);
            }
        }
    }
    ///Sparse Table
    void sparseTable(){
        for(int i=1;i<22;i++){
            for(int j=1;j<=N;j++){
                int x=sparse[i-1][j];
                if(x!=-1) sparse[i][j]=sparse[i-1][x];
            }
        }
    }
    ///Level up
    int levelUp(int dif, int v){
            while(dif>0){
                int logDif=log2(dif);
                v = sparse[logDif][v];
                dif-=(1<<logDif);
            }
            return v;
    }
    ///Find LCA
    int findLCA(int u, int v){
        if(depth[u]>depth[v]) swap(u,v);
        v=levelUp(depth[v]-depth[u],v);
        if(u==v) return u;
        for(int i=LogV+2;i>=0;i--){
            int x=sparse[i][u];
            int y=sparse[i][v];
            if(x == -1 || y == -1) continue;
            if(x!=y){
                u=x;
                v=y;
            }
        }
        return sparse[0][u];
    }
    int Durotto(int u, int v){
        return dist[u]+dist[v]-2*dist[findLCA(u,v)];
    }

}lca;
void solve(){
    int n;
    cin>>n;

    lca.init(n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        lca.adj[u].emplace_back(v,w);
        lca.adj[v].emplace_back(u,w);
    }
    lca.dfs(0,-1);
    lca.sparseTable();
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca.Durotto(u,v)<<endl;
    }

}
int main() {
	int tc=1;
	//cin>>tc;
	while(tc--){
        solve();
	}
	return 0;
}
