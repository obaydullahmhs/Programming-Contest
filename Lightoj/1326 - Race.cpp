#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
const ll M = 10056;
ll nCr[1005][1005], dp[1005];
ll generateNCR(){
    for(int i=1;i<=1003;i++) nCr[i][0] = 1, nCr[i][i] = 1;
    for(int i=2;i<=1003;i++){
        for(int j = 1;j<i;j++){
            nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1])%M;
        }
    }
}
void F(int horse){
    dp[0] = 1;
    for(int i=1;i<=horse;i++){
        for(int j = 1;j<=i;j++){
            dp[i] += (nCr[i][j]*dp[i-j]);
            dp[i]%=M;
        }
    }
}
int cs = 0;
void solve(){
    scanf("%d", &n);
    printf("Case %d: ", ++cs);
    printf("%lld\n", dp[n]);
}
int main() {
    generateNCR();
    F(1000);
    int tc=1;
    scanf("%d",&tc);
    while(tc--){
        solve();
    }
    return 0;
}
