
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs;
void solve(){
  int a, b, c, k; cin >> a >> b >> c >> k;
  cout << "Case " << ++cs<<": ";
  if((a + b + c) % 3 != 0){
    cout << "Fight\n";
    return;
  }
  if(abs(a - b) % k == 0 && abs(a - c) % k == 0 && abs(b - c) % k == 0) cout << "Peaceful\n";
  else cout << "Fight\n";
}
int main(){

  Fast_Read
  Precision(10)

  int tc = 1; cin >> tc;
  while(tc--){
      solve();
  }


  return 0;
}
/**

**/
