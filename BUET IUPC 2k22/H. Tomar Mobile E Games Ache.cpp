#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int nxt(){
    int a;
    scanf("%d", &a);
    return a;
}
inline int lxt(){
    ll a;
    scanf("%lld", &a);
    return a;
}
int n = 16, m = 20;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int bfs(int x, int y, int x1, int y1){
    queue<pair<int, int> > q;
    q.emplace(x, y);
    vector<vector<int> > d(n + 1, vector<int>(m + 1, -1));
    d[x][y] = 0;
    while(q.size()){
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            vx %= n;
            vy %= m;
            if(vx < 0) vx += n;
            if(vy < 0) vy += m;
            if(d[vx][vy] == -1){
                d[vx][vy] = d[ux][uy] + 1;
                q.emplace(vx, vy);
            }
        }
    }
    return d[x1][y1];
}
void solve(){
    int x = nxt(), y = nxt(), x1 = nxt(), y1 = nxt();
    printf("%d\n", bfs(--x, --y, --x1, --y1));
}

int main(){

    int tc = 1; scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}
