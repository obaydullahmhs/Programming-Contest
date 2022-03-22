
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cs;
void printCase(){
    printf("Case #%d: ", ++cs);
}
ll dp[14][2][110][110];
ll F(ll pos, bool canUse, int mul, int sum, string& s, int& tt){
    if(sum < 0) return 0;
    if(pos >= s.size()){
        if(mul == 0 && sum == 0) return 1;
        return 0;
    }
    ll& ret = dp[pos][canUse][mul][sum];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= (canUse? 9:(s[pos] - '0')); i++){
        bool subCanUse = canUse;
        if(subCanUse == false && i < (s[pos] - '0')) subCanUse = true;
        int subMul = mul;
        int subSum = sum - i;
        if(subSum != tt) subMul = mul * i;
        ret += F(pos + 1, subCanUse, subMul%tt, subSum, s, tt);
    }
    return ret;
}
void solve(){

    ll a, b;
    scanf("%lld %lld", &a, &b);
    string aa = to_string(a - 1);
    string bb = to_string(b);
    int nn = aa.size();
    int mm = bb.size();

    int lastT = 9*(int)bb.size();
    ++lastT;
    ll ans = 0;
    for(int i = 1; i < min(110, lastT); i++){
        memset(dp, -1, sizeof dp);
        int ii = i;
        ans += F(0, 0, 1, ii, bb, ii);
    }
    lastT = 9*(int)aa.size();
    lastT++;
    for(int i = 1; i < min(110, lastT); i++){
        int ii = i;
        memset(dp, -1, sizeof dp);
        ans -= F(0, 0, 1, ii, aa, ii);
    }

    printCase();
    printf("%lld\n", ans);


}
int main(){

//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1; scanf("%d", &tc);
    while(tc--){
        solve();
    }

    return 0;
}
/**

**/
