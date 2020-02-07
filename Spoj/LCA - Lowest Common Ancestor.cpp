#include <bits/stdc++.h>

using namespace std;

const int N=50005;

vector<int> adj[N];
int depth[N],sparse[25][N],n;

void dfs(int node, int par){
    for(int it:adj[node]){
        if(it!=par){

            sparse[0][it]=node;
            depth[it]=depth[node]+1;
            dfs(it, node);
        }
    }
}

void sparseTable(){
    for(int i=1;i<22;i++){
        for(int j=1;j<=n;j++){
            int x=sparse[i-1][j];
            if(x!=-1) sparse[i][j]=sparse[i-1][x];
        }
    }
}

int levelUp(int u, int v){
    int dif=depth[v]-depth[u];
    while(dif>0){
        int logDif=log2(dif);
        v = sparse[logDif][v];

        dif-=(1<<logDif);
    }
    return v;
}

int findLCA(int u, int v){
    if(depth[u]>depth[v]) swap(u,v);
    v=levelUp(u,v);
    if(u==v) return u;
    for(int i=21;i>=0;i--){
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

int cs=0;
void CLEAR(){
    for(int i=1;i<N;i++) adj[i].clear();
    memset(sparse, -1, sizeof sparse);
    memset(depth, -1, sizeof depth);
}

void solve(){

    CLEAR();

    cin>>n;

    for(int i=1;i<N;i++) adj[i].clear();

    for(int i=0;i<n;i++){

        int m;
        cin>>m;

        for(int j=0;j<m;j++){

            int in;
            cin>>in;

            adj[in].push_back(i+1);
            adj[i+1].push_back(in);

        }

    }

    dfs(1,-1);
    sparseTable();

    cout<<"Case "<<++cs<<":"<<endl;

    int q;
    cin>>q;

    while(q--){

        int a,b;
        cin>>a>>b;

        cout<<findLCA(a,b)<<endl;

    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

	int tc=1;
	cin>>tc;

	while(tc--){

        solve();

	}

	return 0;
}

