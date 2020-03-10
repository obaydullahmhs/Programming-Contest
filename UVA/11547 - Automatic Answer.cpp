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
    ll tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        ll a;
        cin>>a;
        a*=567;
        a/=9;
        a+=7492;
        a*=235;
        a/=47;
        a-=498;
        a/=10;
        a%=10;
        cout<<abs(a)<<endl;

    }
    return 0;
}

