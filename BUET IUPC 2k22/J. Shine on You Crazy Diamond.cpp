#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> primes;
void sieve(int n){
    vector<bool> mark(n+2,false);
    primes.push_back(2);
    for(int p=3;p*p<=n;p=p+2){
        if(mark[p]==0){
            for(int i=p*p;i<=n;i+=p*2){
                mark[i]=1;
            }
        }
    }
    for(int i=3;i<=n;i=i+2){
        if(!mark[i]){
            primes.push_back(i);
        }
    }
}
const int inf = 1e8;
void solve(){
  int n; cin >> n;
  vector<int> cnt(1000006, 0), pcnt(1000006, 0);
  for(int i = 0; i < n; i++){
    int in; cin >> in;
    vector<int> p;
    for(int j = 0; primes[j] * primes[j] <= in; j++){
      if(in % primes[j] == 0){
        p.push_back(primes[j]);
        cnt[primes[j]]++;
        while(in % primes[j] == 0) in /= primes[j];
      }
    }
    if(in > 1) cnt[in]++, p.push_back(in);
    sort(p.begin(), p.end());
    for(int j = 0; j < p.size(); j++){
      for(int k = j + 1; k < p.size(); k++){
        if(p[j] * p[k] <= 1000000) pcnt[p[j] * p[k]]++;
      }
    }
  }
  pair<int, int> ans(inf, inf);
  int mx = 0;
  for(auto it: primes){
    if(cnt[it] > mx){
      mx = cnt[it];
      ans.first = it;
    }
  }
  vector<pair<int, int> > sub;
  for(int it: primes){
    if(it > 1000){
      sub.emplace_back(cnt[it], it);
    }
  }
  sort(sub.begin(), sub.end());
  if(sub.back().first + sub[sub.size() - 2].first > mx){
    mx = sub.back().first + sub[sub.size() - 2].first;
    ans.first = sub.back().second;
    ans.second = sub[sub.size() - 2].second;
  }
  for(int i = 0; i < 170; i++){
    for(int j = i + 1; j < primes.size(); j++){
      if(primes[i] * primes[j] > 1000000) break;
      int val = cnt[primes[i]] + cnt[primes[j]] - pcnt[primes[i] * primes[j]];
      if(val > mx){
        mx = val;
        ans.first = primes[i];
        ans.second = primes[j];
      }
    }
  }

  cout << n - mx << "\n";
  cout << ans.first << " " << ans.second << "\n";

}
int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  sieve(1000005);
  int tc = 1; //cin>>tc;
  while(tc--){
    solve();
  }

  return 0;
}
/**

**/
