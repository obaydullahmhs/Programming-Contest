#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e6+10;
int path[N];
void root(int n) {
    for(int i=0; i<=n; i++)
        path[i]=i;
}
int findUnion(int x) {      ///Find root of x
    if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
void mergeUnion(int x,int y) {
    path[findUnion(x)]=findUnion(y); ///making same root of both x and y
}
bool sameset(int x,int y) { ///check two element are in same set or not
    return findUnion(x)==findUnion(y);
}
struct data
{
    int u,v;
    ll w;
    data(){
        u=v=w=0;
    }
    data(int _u,int _v, ll _w){
        u=_u;v=_v;w=_w;
    }
    bool operator<(const data& ob){
        return w<ob.w;
    }
};
vector<data> graph;
ll mst(int n){
    sort(graph.begin(),graph.end());
    ll ans=0;
    int cnt=0;
    for(int i=0;i<graph.size();i++){
        if(!sameset(graph[i].u,graph[i].v)){
            ans+=graph[i].w;cnt++;
            mergeUnion(graph[i].u,graph[i].v);
        }
        if(cnt==n-1) break;
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    root(n+10);
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        graph.push_back(data(u,v,w));
    }
    cout<<mst(n)<<endl;


}
int main() {
	int tc=1;
	while(tc--){
        solve();
	}
	return 0;
}
