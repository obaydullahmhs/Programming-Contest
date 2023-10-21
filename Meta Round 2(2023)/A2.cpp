#include "bits/stdc++.h"
using namespace std;


int cs;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0 , 0};

void bfs(int s1, int s2, int n, int m, vector<string>& a, vector<vector<int>>& vis, vector<vector<int> >& ans) {
  queue<pair<int, int> > q;
  q.push({s1, s2});
  int sub = 1;
  int fx = -1, fy = -1;
  set<pair<int, int> > st;
  while(!q.empty()) {
    auto u = q.front();
    q.pop();
    int x = u.first;
    int y = u.second;
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if(a[nx][ny] == '.') {
          st.emplace(nx, ny);
          fx = nx;
          fy = ny;
        } else if (a[nx][ny] == 'W' && vis[nx][ny] == 0) {
          vis[nx][ny] = 1;
          sub++;
          q.push({nx, ny});
        }
      }
    }
  }
  if(st.size() == 1) {
    ans[fx][fy] += sub;
  }
}
void solve() {

  int n, m; cin >> n >> m;
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<pair<int, int> > white;
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      if(a[i][j] == 'W') {
        white.emplace_back(i, j);
      }
    }
  }

  vector<vector<int>> vis(n, vector<int>(m, 0));
  vector<vector<int>> ans(n, vector<int>(m, 0));

  for(auto u : white) {
    if(vis[u.first][u.second] == 0) {
      vis[u.first][u.second] = 1;
      bfs(u.first, u.second, n, m, a, vis, ans);
    }
  }

  int mx = 0;
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      mx = max(mx, ans[i][j]);
    }
  }
  cout << "Case #" << ++cs << ": ";
  cout << mx << endl;
}
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   freopen("ready_go_part_2_input.txt", "r", stdin);
   freopen("outputforA2.txt", "w", stdout);
  int tc = 1; cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
