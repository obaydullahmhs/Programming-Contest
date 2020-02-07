#include<bits/stdc++.h>
#define     pie                          acos(-1.0)
#define     N                            2000005
#define     esp                          1e-9
#define     pb                           push_back
#define     ff                           first
#define     ss                           second
#define     nl                           '\n'
#define     mod                          1000000007
#define     sp                           " "
#define     CLR(a)                       memset(a,0,sizeof(a))
#define     SET(a)                       memset(a,-1,sizeof(a))
#define     mp                           make_pair
#define     all(x)                       x.begin(),x.end()
#define     sz(x)                        (int)(x).size()
#define     Fast_Read                    ios_base::sync_with_stdio(false); cin.tie(nullptr);  cout.tie(nullptr);
#define     Precision(x)                 cout.setf(ios::fixed); cout.precision(x);
#define     bug                          cout<<"debug"<<nl;
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
int main(){
    Fast_Read
    Precision(10)
    //freopen ("output.txt","w",stdout);
    //freopen ("input.txt","r",stdin);
    ll n,m;
    cin>>n>>m;
    if(m>=n) cout<<2L*(n-1L)<<nl;
    else cout<<2L*(m-1L)+1L<<nl;

    return 0;
}
