

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cs;
void solve(){
  int a, b, c; cin >> a >> b >> c;
  cout << "Case " << ++cs<<": ";
  if((a + b + c) % 3 == 0) cout << "Peaceful\n";
  else cout << "Fight\n";
}
int main(){


  int tc = 1; cin >> tc;
  while(tc--){
      solve();
  }


  return 0;
}
/**

**/
