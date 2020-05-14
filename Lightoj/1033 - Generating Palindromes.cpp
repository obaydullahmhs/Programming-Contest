#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string a, b, p;
const int N = 105;
int lena, lenb, dp[N][N];
int LCS(){
    for(int i = 1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                if(dp[i-1][j]>dp[i][j-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[lena][lenb];
}
int cs = 0;
void solve(){
    cin>>a;
    b = a;
    reverse(b.begin(), b.end());
    lena = a.size(), lenb = b.size();
    cout<<"Case "<<++cs<<": ";
    cout<<lena - LCS()<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}

