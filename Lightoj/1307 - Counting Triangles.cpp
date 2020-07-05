#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cs = 0;
void solve(){
    int n; scanf("%d", &n);
    vector<ll> v(n);
    for(int i=0;i<n;i++) scanf("%lld", &v[i]);
    sort(v.begin(),v.end());
    ll ans = 0;
    for(int i = n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            ll sum = v[i]-v[j]+1;
            auto it = lower_bound(v.begin(),v.end(),sum);
            if(it==v.end()) continue;
            int ind = it-v.begin();
            if(ind>=j) continue;
            ans+=(j-ind);
        }
    }
    printf("Case %d: %lld\n",++cs, ans);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ///freopen("output.txt","w",stdout);
    int tc=1; scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}

