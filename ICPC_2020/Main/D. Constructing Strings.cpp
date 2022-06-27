#include<bits/stdc++.h>

using namespace std;

const int N = 500005;
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

int n, q;

struct HashSegmentTree{ ///0 Based
  Hash *tree;
  HashSegmentTree(){}
  HashSegmentTree(int _n){
    init(_n);
  }
  void init(int _n){
    tree = (Hash*)calloc((_n + 5) << 1, sizeof(Hash));
  }
  Hash combine(Hash x, Hash y) {
    return x + y;
  }
  void update(int p, int val) {
    p += n;
    tree[p] = Hash(0, 1, val);
    for(; p >>= 1; ) {
      tree[p] = combine(tree[p << 1], tree[p << 1 | 1]);
    }
  }
  Hash query(int l, int r) {
    Hash resl, resr;
    resl = Hash(0, 0, 0);
    resr = Hash(0, 0, 0);
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resl = combine(resl, tree[l++]);
      if(r & 1) resr = combine(tree[--r], resr);
    }
    return combine(resl, resr);
  }
}up, down;

int ncomp;
int id[N];
vector<int> comp[N];

void change(int p, int v) {
  id[p] = v;
  comp[v].push_back(p);
  up.update(p, v);
  down.update(n - p - 1, v);
}

void join(int x, int y) {
  if(x == y) return;
  ncomp--;
  if(comp[x].size() > comp[y].size()) swap(x, y);
  for(int v : comp[x]) change(v, y);
}
template <class T> inline T bigmod(T p, T e, T m){
    T ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
    }
    return (T)ret;
}
const long long M = 998244353;
int cs;
void solve(){
  cin >> n >> q;
  up.init(n);
  down.init(n);
  for(int i = 0; i < n; ++i) id[i] = i;

  for(int i = 0; i < n; ++i) change(i, id[i]);

  ncomp = n;
  for(int t = 0; t < q; ++t) {
    int L, R; cin >> L >> R;
    L--; R--;

    while(L < R) {
      if(up.query(L, R) == down.query(n - R - 1, n - L - 1)) break;
      int lo = 0, hi = (R - L) >> 1, ans = -1;
      while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        Hash x = up.query(L, L + mid);
        Hash y = down.query(n - R - 1, n - (R - mid) - 1);
        if(x == y) lo = mid + 1;
        else ans = mid, hi = mid - 1;
      }
      if(ans == -1) break;
      join(id[L + ans], id[R - ans]);
      L += ans + 1;
      R -= ans + 1;
    }
  }
  cout << "Case " << ++cs << ": " << bigmod(26LL, (long long)ncomp, M) << "\n";

}

int main() {

  ios_base::sync_with_stdio(false); cin.tie(NULL);

  prepare_pow(0);

  int tc = 1; cin >> tc;
  while(tc--){
    solve();
  }


  return 0;
}
