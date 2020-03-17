#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define    N        2000005
#define    ESP      1e-9
#define    pii      pair<int,int>
#define    vi       vector<int>
#define    vl       vector<ll>
#define    pb       push_back
#define    pp       pop_back
#define    ff       first
#define    ss       second
ld pie=acos(-1);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        ld r1,r2,h,p;
        cin>>r1>>r2>>h>>p;
        ld y=(p*(r1-r2)/h);
        ld H=(((r2+y)*h)/(r1-r2));
        ld x=r2*h/(r1-r2);
        ld ans=(1.0/3.0)*pie*(((r2+y)*(r2+y)*H)-(r2*r2*x));
        cout<<fixed<<setprecision(10)<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}

