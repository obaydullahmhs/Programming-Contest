#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define    pie      acos(-1)
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
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed);cout.precision(2);
    cout.tie(nullptr);cin.tie(nullptr);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        ld C,d;
        cin>>C>>d;
        cout<<"Case "<<i<<": ";
        C=((9.0/5.0)*C)+32.0+d;
        ld ans=((5.0*C)-(32.0*5.0))/9;
        cout<<ans<<endl;

    }

    return 0;
}
