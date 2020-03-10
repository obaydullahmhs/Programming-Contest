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
    int h1,m1,h2,m2;
    while(cin>>h1>>m1>>h2>>m2){
        if(h1==0&&m1==0&&h2==0&&m2==0) break;
        int first=(h1*60)+m1;
        int second=(h2*60)+m2;
        int ans=second-first;
        if(ans<0) ans=1440+ans;
        cout<<ans<<endl;
    }

    return 0;
}

