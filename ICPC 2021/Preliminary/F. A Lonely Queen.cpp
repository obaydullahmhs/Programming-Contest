#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e16;
ll n, m, p, q, sx, sy, Dx, Dy;
ll dx[]={-1, -1, -1,  0, 0, 1, 1, 1};
ll dy[]={-1,  0,  1, -1, 1,-1, 0, 1};
ll C[8];

vector<vector<vector<tuple<ll, ll, ll> > > > T;
vector<vector<bool> > obs;

bool isValid(ll x, ll y){
  if(x >= 0 && y >= 0 && x < n && y < m && obs[x][y] == false) return true;
  return false;
}
vector<vector<vector<vector<ll> > > > dp;
ll F(ll id, ll x, ll y, bool z){
  if(x == (Dx - 1) && y == (Dy - 1)){
    if(z) return 0;
    return C[id];
  }
  ll& ret = dp[id][x][y][z];
  if(ret != -1) return ret;
  ret = inf;
  if(z == 0){
    for(ll i = 0; i < 8; i++){
      if(isValid(x + dx[i], y + dy[i])){
        if(i == id){
          ret = min(ret, F(i, x + dx[i], y + dy[i], 0));
          ret = min(ret, C[id] + F(i, x + dx[i], y + dy[i], 1));
          continue;
        }
        ret = min(ret, C[id] + F(i, x + dx[i], y + dy[i], 0));
        ret = min(ret, C[id] + C[i] + F(i, x + dx[i], y + dy[i], 1));
      }
    }
    for(auto it: T[x][y]){
      ret = min(ret, C[id] + get<0>(it) + F(8, get<1>(it), get<2>(it), 1));
    }
    return ret;
  }
  for(ll i = 0; i < 8; i++){
    if(isValid(x + dx[i], y + dy[i])){
      ret = min(ret, F(i, x + dx[i], y + dy[i], 0));
      ret = min(ret, C[i] + F(i, x + dx[i], y + dy[i], 1));
    }
  }
  for(auto it: T[x][y]){
    ret = min(ret, get<0>(it) + F(8, get<1>(it), get<2>(it), 1));
  }

  return ret;

}

ll cs;
void solve(){
  scanf("%lld %lld %lld %lld", &n, &m, &p, &q);
  scanf("%lld %lld %lld %lld", &sx, &sy, &Dx, &Dy);
  for(ll i = 0; i < 8; i++) scanf("%lld", &C[i]);
  T.assign(n, vector<vector<tuple<ll, ll, ll> > >(m, vector<tuple<ll, ll, ll>>()));
  obs.assign(n, vector<bool>(m, false));
  for(ll i = 0; i < p; i++){
    ll xxx[5];
    for(ll j = 0; j < 5; j++){
      scanf("%lld", &xxx[j]);
    }
    xxx[0]--, xxx[1]--, xxx[2]--, xxx[3]--;
    T[xxx[0]][xxx[1]].push_back(make_tuple(xxx[4], xxx[2], xxx[3]));
  }
  for(ll i = 0; i < q; i++){
    ll xx, yy; scanf("%lld %lld", &xx, &yy);
    xx--, yy--;
    obs[xx][yy] = true;
  }

  dp.assign(10, vector<vector<vector<ll> > >(n + 2, vector<vector<ll> >(m + 2, vector<ll>(3, -1))));

  printf("Case %d: ", ++cs);
  ll ret = F(8, sx - 1, sy - 1, 1);
  if(ret >= (ll)inf/2) ret = -1;
  printf("%lld\n", ret);

}
int main(){

  ll tc = 1; scanf("%d", &tc);
  while(tc--){
    solve();
  }

  return 0;
}
/**
1
4 7 1 14
2 3 4 7
1 1 1 1 1 1 1 1
2 2 4 6 1
1 1
1 2
1 3
1 4
2 1
2 4
3 1
3 2
3 3
3 4
3 5
3 6
3 7
4 5

1
3 6 3 8
1 1 3 6
1 1 1 1 1 1 1 1
1 2 1 5 1
1 2 3 2 1
1 2 3 5 1
1 3
2 1
2 2
2 3
2 4
2 5
2 6
3 4

**/
