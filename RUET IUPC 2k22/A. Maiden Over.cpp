#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cs;
void solve(){
  int n; cin >> n;
  int ans = 0;
  for(int i = 0; i < n; i++){
    int sum = 0;
    for(int in, j = 0; j < 6; j++){
      cin >> in;
      sum += in;
    }
    ans += (sum == 0);
  }
  cout << "Case " << ++cs << ": " << ans << "\n";
}
int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int tc = 1; cin>>tc;
  while(tc--){
    solve();
  }

  return 0;
}
/**

**/

