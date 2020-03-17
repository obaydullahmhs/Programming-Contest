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
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10);
    cout.tie(nullptr); cin.tie(nullptr);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    ll n;
    cin>>n;
    ll sq=ceil(sqrt(n));
    ll mark=(((sq-1)*(sq-1)+1)+(sq*sq))/2;
    cout<<"Case "<<i<<": ";
    //cout<<sq<<" "<<mark<<endl;
    if(sq%2){
        if(n>=mark) cout<<sq-(n-mark)<<" "<<sq<<endl;
        else cout<<sq<<" "<<sq-(mark-n)<<endl;
    }
    else{
        if(n>=mark) cout<<sq<<" "<<sq-(n-mark)<<endl;
        else cout<<sq-(mark-n)<<" "<<sq<<endl;

    }
    }

    return 0;
}

