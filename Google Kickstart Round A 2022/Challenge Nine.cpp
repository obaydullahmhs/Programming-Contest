
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cs;
void printCase(){
    cout << "Case #" << ++cs << ": ";
}
void solve(){
    string s; cin >> s;
    ll sum = 0;
    for(auto it: s){
        sum += (it - '0');
    }

    int num = 0;
    if(sum % 9){
        num = (9 - (sum % 9));
    }

    int pos = -1;
    for(int i = (num == 0? 1 : 0); i < s.size(); i++){
        if((s[i] - '0') > num){
            pos = i;
            break;
        }
    }
    if(pos == -1) s += (char)(num + '0');
    else s.insert(s.begin() + pos, (char)(num + '0'));
    printCase();
    cout << s << "\n";

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
