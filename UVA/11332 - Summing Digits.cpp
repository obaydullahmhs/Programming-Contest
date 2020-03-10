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
void Function(ll n){
    ll sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    if(sum/10!=0) Function(sum);
    else cout<<sum<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10);
    cout.tie(nullptr); cin.tie(nullptr);
    ll n;
    while(cin>>n&&n!=0){
       Function(n);
    }
    return 0;
}

