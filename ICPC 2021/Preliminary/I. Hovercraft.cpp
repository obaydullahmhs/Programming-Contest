#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-4;
double isValid(double mid, double l, double w){
  double pani = mid;
  double bb = l - mid;
  double ex = pani * pani - bb * bb;
  ex = sqrt(ex);
  if(ex > w) return l + w + l;
  double ans = mid + mid + (w - ex);
  return ans;
}
void solve(double l, double r){
  double lo = l / 2.0, hi = l, sub = l + r;
  for(int i = 0; i < 120; i++){
    double mid = (lo + hi) / 2.0;
    double ret1 = isValid(mid, l, r);
    double ret2 = isValid(mid + eps, l, r);
    sub = min({sub, ret1, ret2});
    if(ret1 > ret2) lo = mid;
    else hi = mid;
  }
  cout << fixed << setprecision(4) << sub << "\n";
}
int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  double l, w;
  while(cin >> l >> w){
    if(l == 0.0 && w == 0.0) break;
    solve(l, w);
  }

  return 0;
}
/**

**/
