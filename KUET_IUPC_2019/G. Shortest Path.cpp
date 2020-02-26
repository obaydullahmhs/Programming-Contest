
#include<bits/stdc++.h>
#define     N                            2000015
#define     ff                           first
#define     ss                           second

using namespace std;
typedef pair<int,int> pii;
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}

class DSU{

private:
    vector<int> path;
public:
    DSU(){
        path=vector<int>(2e5+25);
        root(2e5+20);
    }
    DSU(int n){
        path=vector<int>(n+25);
        root(n+20);
    }
    void root(int n) {
        for(int i=0; i<=n; i++)
            path[i]=i;
    }
    int findUnion(int x) {
        if(path[x]==x) return x;
        return path[x]=findUnion(path[x]);

    }
    void mergeUnion(int x,int y) {
        path[findUnion(x)]=findUnion(y);
    }
    bool sameSet(int x,int y) {
        return findUnion(x)==findUnion(y);
    }
};
vector<pii> adj[N];
int occurance[N];
int dis[N],vis[N];
int bfs(int node){
	queue<int> q;
	q.push(node);
	vis[node]=1;
	int lastNode=-1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(pii v:adj[u]){
			if(vis[v.ff]==0){
				q.push(v.ff);
				vis[v.ff]=1;
				lastNode=v.ff;
				dis[v.ff]=dis[u]+v.ss;
			}
		}
	}

	return lastNode;
}
int cs=0;
void solve(){

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		adj[i].clear();dis[i]=0;vis[i]=0;occurance[i]=0;
	}
	DSU dsu(n);
	map<pii,int> mp;
	map<int,int> cycle;
	for(int i=0;i<m;i++){
		int u=nxt(),v=nxt(),w=nxt();
		dsu.mergeUnion(u,v);
		occurance[u]++,occurance[v]++;
		mp[{u,v}]=w;
		mp[{v,u}]=w;
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
	}
	set<int> st;
	for(int i=1;i<=n;i++){
		if(occurance[i]==1){
			st.insert(i); ///checking linear
		}
	}
	while(!st.empty()){
		int x=*st.begin();
		int y=bfs(x);
		if(st.find(x)!=st.end()) ///linear distance
			st.erase(x);
		if(st.find(y)!=st.end())
			st.erase(y);
	}
	for(int i=1;i<n;i++){		///cycle distance
		if(vis[i]==0){
			if(adj[i].size()<2) continue;
			pii pp=adj[i].back();
			adj[i].pop_back();
			int y=bfs(i);
			int distance=dis[y];
			distance+=mp[{i,y}];
			int parentOfNode=dsu.findUnion(i);
			cycle[parentOfNode]=distance;
			adj[i].push_back(pp);
		}
	}
	printf("Case %d:\n",++cs);
	int q=nxt();
	while(q--){
		int u=nxt(),v=nxt();
		if(!dsu.sameSet(u,v)) printf("-1\n");
		else{
			int parentOfNode=dsu.findUnion(u);
			if(cycle.find(parentOfNode)==cycle.end()){
				printf("%d\n",abs(dis[v]-dis[u]));
			}
			else{
				int distance=abs(dis[v]-dis[u]);
				printf("%d\n",min(cycle[parentOfNode]-distance,distance));
			}
		}
	}





}

int main()

{

  int tc=nxt();

  while(tc--)

  {

    solve();

  }

  return 0;

}

