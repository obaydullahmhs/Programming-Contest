#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int cs=0;
void solve(){
    int s,d;
    cin>>s>>d;
    if((s+d)&1){
        cout<<"impossible"<<endl;
        return;
    }
    int x=(s+d)/2;
    int y=x-d;
    if(y<0){
        cout<<"impossible"<<endl;
        return;
    }
    if(x<y) swap(x,y);
    cout<<x<<" "<<y<<endl;
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

