#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs;

inline ll lcm(ll a, ll b){
    return (a/__gcd(a, b))*b;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> v(m);
    for(int& in: v) cin >> in;

    int ans = 0;
    for(int i = 0; i < (1 << m); i++){
        int cnt = 0;
        ll mul = 1;
        for(int j = 0; j < m; j++){
            if(i & (1 << j)){
                mul = lcm(mul, v[j]);
                if(mul > n) {
                    cnt = 0;
                    break;
                }
                ++cnt;
            }
        }
        if(cnt){
            if(cnt & 1) ans += n / mul;
            else ans -= n / mul;
        }
    }
    cout << "Case " << ++cs << ": " << n - ans << "\n";
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

