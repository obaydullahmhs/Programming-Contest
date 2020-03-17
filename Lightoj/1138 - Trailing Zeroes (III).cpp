#include<stdio.h>
#include <algorithm>
inline int nxt(){int fun;scanf("%d",&fun); return fun;}
using namespace std;
typedef long long ll;
ll possible(ll n){
    ll a=5;
    ll ans=0;
    while(a<=n){
        ans+=(n/a);
        a*=5;
    }
    return ans;
}
int cs=0;
void solve()
{
    int q=nxt();
    ll low=0,high=100000000000000000LL;
    printf("Case %d: ",++cs);
    ll ans=-1;
    while(low<=high){
        ll mid=(low+high)>>1;
        ll check=possible(mid);
        if(q==check) {
            ans=mid;
            high=mid-1;
        }else if(check>q) high=mid-1;
        else low=mid+1;
    }
    printf((ans==-1)? "impossible\n":"%lld\n",ans);
}
int main()
{
    int tc=nxt();
    while(tc--)
    {
        solve();
    }
    return 0;
}
