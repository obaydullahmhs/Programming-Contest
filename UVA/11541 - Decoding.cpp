#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int cs=0;
bool isLetter(char c){
    if(c>='A' && c<='Z') return true;
    return false;
}
void solve(){
    string s;
    cin>>s;
    int i=0;
    string ans="";
    while(i<s.size()){
        string t="";
        while(i<s.size() && isLetter(s[i])){
            t+=s[i++];
        }
        int num=0;
        while(i<s.size() && !isLetter(s[i])){
            num=num*10+s[i++]-'0';
        }
        for(int j=0;j<num;j++) ans+=t;
    }
    cout<<"Case "<<++cs<<": ";
    cout<<ans<<endl;
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

