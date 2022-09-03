

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 40005;
vector<ll> w;
vector<int> dep;
vector<vector<int> > adj;
void dfs(int node, ll& es, ll& os, int& ec, int& oc, int h = 0, int par = -1){
  dep[node] = h;
  if(h & 1) os += w[node], oc++;
  else es += w[node], ec++;
  for(auto v: adj[node]){
    if(v == par) continue;
    dfs(v, es, os, ec, oc, h + 1, node);
  }
}
int cs;
void solve(){
  int n; scanf("%d", &n);
  dep.assign(n, -1);
  w.resize(n);
  adj.assign(n, vector<int>());
  for(int i = 0; i < n; i++) scanf("%d", &w[i]);
  for(int i = 1; i < n; i++){
    int a, b; scanf("%d %d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  ll es = 0, os = 0;
  int ec = 0, oc = 0;
  dfs(0, es, os, ec, oc);
  ll ans = numeric_limits<ll>::min()/10;
  int ou = 0;
  for(int i = 0; i < n; i++){
    if(dep[i] & 1) os -= w[i], oc--;
    else es -= w[i], ec--;
    ll sub = 0;
    if(dep[i] % 2 == 0) sub = (os - es);
    else sub = (es - os);
    if(dep[i] % 2 == 0) sub += ((ll)(ec - oc) * w[i]);
    else sub += ((ll)(oc - ec) * w[i]);
    if(sub > ans) ans = sub, ou = i;
    else if(sub == ans) ou = min(ou, i);
    if(dep[i] & 1) os += w[i], oc++;
    else es += w[i], ec++;
  }
  printf("Case %d: %d\n", ++cs, ou + 1);


}
int main(){

  int tc = 1; scanf("%d\n", &tc);
  while(tc--){
      solve();
  }

  return 0;
}
/**

**/
