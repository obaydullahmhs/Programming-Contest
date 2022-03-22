#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cs;
void printCase(){
    cout << "Case #" << ++cs << ": ";
}
template < class T> inline T bitOn(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitOff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T isOn(T n,T pos){return (bool)(n & ((T)1<<pos));}

bool check5(int num){
    for(int i = 0; i < 2; i++){
        if(isOn(num, i) != isOn(num, 4 - i)) return false;
    }
    return true;
}
bool check6(int num){
    for(int i = 0; i < 3; i++){
        if(isOn(num, i) != isOn(num, 5 - i)) return false;
    }
    return true;
}
int n;
string s;
vector<vector<int> > dp;
int F(int pos, int last){
    if(pos > 4 && check5(last)){
        return false;
    }
    if(pos > 5 && check6(last)){
        return false;
    }
    if(pos >= n) return true;
    int& ret = dp[pos][last];
    if(ret != -1) return ret;
    ret = 0;
    int sub = last;
    sub <<= 1;
    sub = bitOff(sub, 6);
    if(s[pos] == '?'){
        ret |= F(pos + 1, sub);
        sub |= 1;
        ret |= F(pos + 1, sub);
    }else{
        if(s[pos] == '1') sub |= 1;
        ret |= F(pos + 1, sub);
    }
    return ret;
}
void solve(){
    cin >> n;
    cin >> s;
    dp.assign(n + 5, vector<int>(135, -1));
    printCase();
    if(F(0, 0)) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";


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

