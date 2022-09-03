#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int nxt(){
    int a;
    scanf("%d", &a);
    return a;
}
inline int lxt(){
    ll a;
    scanf("%lld", &a);
    return a;
}

void solve(){
    int n = nxt();

    vector<ll> v(n + 1);
    for(int i = 1; i <= n; i++) v[i] = lxt();
    vector<ll> ori = v;

    for(int i = n - 1; i > 0; i--) v[i] = v[i] + v[i + 1];
    ll sum = ori[1];
    ll ans = sum;
    set<ll> st;
    st.insert(v[1]);
    for(int i = 2; i <= n; i++){
        sum += ori[i];
        ans = max(ans, sum);
        ans = max(ans, sum + (*st.begin() - v[i]));
        ans = max(ans, sum + (*st.rbegin() - v[i]));
        st.insert(v[i]);
    }
    printf("%lld\n", ans);
}

int main(){

    int tc = 1; scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}
