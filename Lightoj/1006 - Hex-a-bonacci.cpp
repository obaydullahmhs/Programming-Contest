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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    int cs=1;
    while(tc--){
        ll a,b,c,d,e,f,n;
        cin>>a>>b>>c>>d>>e>>f>>n;
        ll ar[n+5];
        ar[0]=a;
        ar[1]=b;
        ar[2]=c;
        ar[3]=d;
        ar[4]=e;
        ar[5]=f;
        for(ll i=6;i<=n;i++){
            ar[i]=ar[i-1]+ar[i-2]+ar[i-3]+ar[i-4]+ar[i-5]+ar[i-6];
            ar[i]=ar[i]%10000007;
        }
        cout<<"Case "<<cs<<": "<<ar[n]%10000007<<endl;
        cs++;

    }

    return 0;
}

