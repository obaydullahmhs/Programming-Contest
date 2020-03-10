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
        ll a,b,c;
        cin>>a>>b>>c;
        if(a+b<=c||a+c<=b||b+c<=a){
            cout<<"Case "<<i<<": Invalid"<<endl;
        }
        else if(a==b&&b==c&&c==a){
            cout<<"Case "<<i<<": Equilateral"<<endl;
        }
        else if(a==b||b==c||c==a){
            cout<<"Case "<<i<<": Isosceles"<<endl;
        }
        else cout<<"Case "<<i<<": Scalene"<<endl;
    }
    return 0;
}

