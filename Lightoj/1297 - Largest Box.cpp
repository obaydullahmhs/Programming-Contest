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
ld w,l;
ld area(ld &x){
    ld ans=(l-2.0*x)*(w-2.0*x)*x;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10);
    cout.tie(nullptr); cin.tie(nullptr);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cin>>l>>w;
        ld total=l+w;
        ld x2=(total-sqrt((total*total)-(3*l*w)))/6.0;
        ld ans=area(x2);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}

