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
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        ld v1,v2,v3,a1,a2;
        cin>>v1>>v2>>v3>>a1>>a2;
        ld d=((v1*v1)/(2*a1))+((v2*v2)/(2*a2));
        ld t1=v1/a1;
        ld t2=v2/a2;
        ld z=max(t1,t2)*v3;
        cout<<fixed<<setprecision(10)<<"Case "<<i<<": "<<d<<" "<<z<<endl;
    }

    return 0;
}

