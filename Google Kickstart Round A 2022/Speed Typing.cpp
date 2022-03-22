
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cs;
void printCase(){
    cout << "Case #" << ++cs << ": ";
}
void solve(){
    string s, t; cin >> s >> t;

    int i = 0, j = 0;
    int ans = 0;
    while(i < s.size() && j < t.size()){
        if(s[i] == t[j]){
            i++, j++;
        }else j++, ans++;
    }
    ans += (t.size() - j);
    printCase();

    if(i == s.size()){
        cout << ans << "\n";
    }else cout << "IMPOSSIBLE\n";

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
