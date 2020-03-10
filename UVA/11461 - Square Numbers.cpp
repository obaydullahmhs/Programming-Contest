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
    ll a,b;
    while(cin>>a>>b&&(a!=0&&b!=0)){
        ll sq=sqrt(a);
        if(sq*sq==a){
            cout<<(ll)sqrt(b)-sq+1<<endl;
        }
        else{
            cout<<(ll)sqrt(b)-sq<<endl;
        }
    }
    return 0;
}

