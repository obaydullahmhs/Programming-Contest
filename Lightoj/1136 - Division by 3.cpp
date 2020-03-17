#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll divisonCheck(ll n){
    ll ans=n/3LL;
    ans*=2LL;
    if(n%3LL==2LL) ans++;
    return ans;
}
int main(){
    int tc,cs=0;
    cin>>tc;
    while(tc--){
        ll a,b;
        cin>>a>>b;
        cout<<"Case "<<++cs<<": ";
        cout<<divisonCheck(b)-divisonCheck(a-1)<<endl;

    }

}
