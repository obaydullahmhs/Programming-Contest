#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int cs=0;
void solve(){
    vector<int> v(4);
    for(int i=0;i<4;i++) cin>>v[i];
    sort(v.begin(),v.end());
    if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3]) cout<<"square"<<endl;
    else if(v[0]==v[1] && v[2]==v[3]) cout<<"rectangle"<<endl;
    else{
        ll sum=(ll)v[0]+(ll)v[1]+(ll)v[2];
        if(sum> (ll)v[3]) cout<<"quadrangle"<<endl;
        else cout<<"banana"<<endl;
    }
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

