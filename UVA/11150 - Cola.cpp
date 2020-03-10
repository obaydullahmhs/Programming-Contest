#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define    pie      acos(-1.0)
#define    N        2000005
#define    ESP      1e-9
#define    pii      pair<int,int>
#define    vi       vector<int>
#define    vl       vector<ll>
#define    pb       push_back
#define    pp       pop_back
#define    ff       first
#define    ss       second
int main()
{
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10);
    cout.tie(nullptr); cin.tie(nullptr);
   // freopen ("myfile.txt","w",stdout);
    ll n;
    while(cin>>n){
        ll ans=n;
        if(n==2) n++;
        while(n>2){
           ans+=n/3;
           ll t=n/3;
           n=n%3+t;
           if(n==2) n++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


