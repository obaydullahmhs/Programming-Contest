
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace Hashing{

  const int N = 1e6 + 5; /// accordingly
  const int MOD[] = {1000000007, 2117566807};
  const int BASE[] = {1572872831LL, 1971536491};
  int basepow[2][N];

  void prepare_pow(int t){
    basepow[t][0] = 1;
    for(int i = 1; i < N; ++i) {
      basepow[t][i] = (1LL * basepow[t][i - 1] * BASE[t]) % MOD[t];
    }
  }

  struct Hash{
    int type;
    int length;
    int hash_value;
    Hash(): type(0), length(0), hash_value(0){}
    Hash(int x, int y, int z): type(x), length(y), hash_value(z){}
    Hash operator +(const Hash &rhs) const{
      return Hash(type, length + rhs.length, (1LL * hash_value * basepow[type][rhs.length] + rhs.hash_value) % MOD[type]);
    }
    Hash operator -(const Hash &rhs) const{
      return Hash(type, length - rhs.length, ((1LL * hash_value - 1LL * basepow[type][length - rhs.length] * rhs.hash_value) % MOD[type] + MOD[type]) % MOD[type]);
    }
    bool operator ==(const Hash &rhs) const{
      return (length == rhs.length && hash_value == rhs.hash_value);
    }
  };


}
using namespace Hashing;
vector<vector<int> > adj;
char s[1000005];
void dfs(int node, int par, stack<Hash>& S, deque<Hash>& Q, int& ans){
  if(S.empty()) S.push(Hash(0, 1, s[node])), Q.push_front(Hash(0, 1, s[node]));
  else S.push(S.top() + Hash(0, 1, s[node])), Q.push_front(Hash(0, 1, s[node]) + Q.front());
  if(Q.front() == S.top()) ++ans;
  for(auto it: adj[node]){
    if(it == par) continue;
    dfs(it, node, S, Q, ans);
  }
  Q.pop_front();
  S.pop();
}
int cs;
void solve(){
  int n; scanf("%d", &n);
  scanf("%s", s);
  adj.assign(n, vector<int>());
  for(int i = 1; i < n; i++){
    int a, b; scanf("%d %d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  deque<Hash> Q;
  stack<Hash> S;
  int ans = 0;
  dfs(0, -1, S, Q, ans);
  int g = __gcd(ans, n);
  ans /= g;
  n /= g;
  printf("Case %d: %d/%d\n", ++cs, ans, n);
}
int main(){

  prepare_pow(0);
  int tc = 1; scanf("%d", &tc);
  while(tc--){
      solve();
  }


  return 0;
}
/**

**/
