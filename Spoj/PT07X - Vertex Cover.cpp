#include <bits/stdc++.h>

using namespace std;
#define debug(a)  cout<<#a<<" "<<a<<endl;
typedef long long ll;
const int N=1e5+10;
vector<int> adj[N];
int cnt[2][N];
void addEdge(int u, int v){
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}
void dfs(int node, int par=-1){
    cnt[1][node]=1;
    for(auto it:adj[node]){
        if(it==par) continue;
        dfs(it,node);
        cnt[0][node]+=cnt[1][it];
        cnt[1][node]+=min(cnt[1][it],cnt[0][it]);
    }
}
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    dfs(1);
    cout<<min(cnt[0][1],cnt[1][1])<<endl;

}
int main() {
	int tc=1;
	while(tc--){
        solve();
	}
	return 0;
}

