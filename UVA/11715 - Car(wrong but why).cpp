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
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed);cout.precision(3);
    cout.tie(nullptr);cin.tie(nullptr);
    int cs,tc=0;
    while(cin>>cs){
        if(cs==0) break;
        double a,b,c;
        cin>>a>>b>>c;
        cout<<"Case "<<++tc<<": ";
        if(cs==1) cout<<(a+b)*c/2<<" "<<(b-a)/c<<endl;
        else if(cs==2) cout<<(a+b)*c/2<<" "<<(b-a)/c<<endl;
        else if(cs==3) cout<<sqrt(a*a+2*b*c)<<" "<<(sqrt(a*a+2*b*c)-a)/b<<endl;
        else if(cs==4) cout<<sqrt(a*a-2*b*c)<<" "<<(a-sqrt(a*a-2*b*c))/b<<endl;
    }

    return 0;
}

