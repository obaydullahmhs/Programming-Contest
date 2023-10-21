#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int cs;

void print(vector<ll>& a) {

  for(auto v : a) {
    cout << v << " ";
  }

  cout << "\n";
}

vector<ll> sum;
ll getSum(int i, int j) {
  if(i == 0) return sum[j];
  return sum[j] - sum[i - 1];
}
bool isReverseSame(deque<ll>& a, deque<ll>& b) {
  int n = a.size();
  int i = 0, j = n - 1;
  while(i < n && a[i] == b[j]) {
    i++;
    j--;
  }
  if(i == n) return true;
  return false;
}
void addSum(ll value) {
  if(sum.empty()) {
    sum.push_back(value);
  } else {
    sum.push_back(sum.back() + value);
  }
}

void solve() {
  sum.clear();
  int n; cin >> n;
  deque<ll> a(n), b(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  cout << "Case #" << ++cs << ": ";


  // a[i] < b[i] then sum.push_back 0, a[i] > b[i] then pb 1, a[i] = b[i] then pb -1
  for(int i = 0; i < n; i++) {
    if(a[i] < b[i]) {
      addSum(0);
    } else if (a[i] > b[i]) {
      addSum(1);
    } else {
      addSum(n);
    }
  }
  int ci = 0, ans = 0;

  if(getSum(ci, ci + (n / 2) - 1) == 0 && getSum((ci + n) - (n / 2) , ci + n - 1) == (n / 2)) {
    bool ok = true;
    if(n & 1) {
      if(getSum(ci + (n / 2), ci + (n / 2)) != n) {
        ok = false;
      }
    }
    if(isReverseSame(a, b) && ok) {
      cout << ans << "\n";
      return;
    }
  }

  for(int i = 0; i < 3*n; i++) {
    ci++;
    ans++;
    ll x = a.front();
    ll y = b.front();
    a.pop_front();
    b.pop_front();
    if(y < x) {
      addSum(0);
    } else if (y > x) {
      addSum(1);
    } else {
      addSum(n);
    }
    a.push_back(y);
    b.push_back(x);
//   print(sum);
//   cout << getSum(ci, ci + (n / 2) - 1) << " vs " << getSum((ci + n) - (n / 2) , ci + n - 1) << "\n";
    if(getSum(ci, ci + (n / 2) - 1) == 0 && getSum((ci + n) - (n / 2) , ci + n - 1) == (n / 2)) {
      if(n & 1) {
        if(getSum(ci + (n / 2), ci + (n / 2)) != n) {
          continue;
        }
      }
      if(isReverseSame(a, b)) {
        cout << ans << "\n";
        return;
      }
    }
  }
  cout << "-1\n";
}
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   freopen("meta_game_input.txt", "r", stdin);
   freopen("outputforB.txt", "w", stdout);
  int tc = 1; cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
