#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
int ans;
int vis[50][50];
vector<string> v;
int n,m;

bool isPossible(pii node){
    if(node.first>=n || node.second>=m||node.first<0 || node.second<0) return false;
    if(vis[node.first][node.second]==1) return false;
    return v[node.first][node.second]!='#';
}

void dfs(pii node){
    vis[node.first][node.second]=1;

    for(int i=0;i<4;i++){
        pii box(node.first+dx[i],node.second+dy[i]);

        if(isPossible(box)){
            ans++;

            dfs(box);
        }
    }
}

void bfs(pii node){
    queue<pii> q;
    vis[node.first][node.second]=1;
    q.push(node);
    while(q.size()){
        pii unbox=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            pii box(unbox.first+dx[i],unbox.second+dy[i]);
            if(isPossible(box)){
                ans++;
                q.push(box);
                vis[box.first][box.second]=1;
            }
        }
    }
}
int cs=0;
void solve(){

    v.clear();
    ans=0;
    memset(vis,-1,sizeof vis);

    scanf("%d %d",&n, &m);
    swap(n,m);

    pii node;


    for(int i=0;i<n;i++){
        char ar[30];
        scanf("%s",ar);
        for(int j=0;j<m;j++){
            if(ar[j]=='@') node=make_pair(i,j);
        }
        v.push_back(ar);
    }

    //bfs(node);
    dfs(node);

    printf("Case %d: %d\n",++cs,++ans);

}
int main() {

	int tc=1;
	scanf("%d",&tc);

	while(tc--){
        solve();
	}

	return 0;
}

