#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    int mx=-1;
    for(int in,i=0;i<n;i++){
        cin>>in;
        mx=max(mx,in);
        mp[in]++;
    }
    if(mp[mx]==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}
int main() {
	int tc=1;
	cin>>tc;
	while(tc--){
        solve();
	}
	return 0;
}

