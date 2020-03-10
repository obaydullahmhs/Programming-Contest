///বিসমিল্লাহির_রহমানির_রহীম
#include<bits/stdc++.h>
#define     pie                          acos(-1.0)
#define     N                            2000005
#define     esp                          1e-9
#define     pii                          pair<int,int>
#define     pb                           push_back
#define     pp                           pop_back
#define     ff                           first
#define     ss                           second
#define     nl                           "\n"
#define     mod                          1000000007
#define     sp                           " "
#define     clr(a)                       memset(a,0,sizeof(a))
#define     set(a)                       memset(a,-1,sizeof(a))
#define     mp                           make_pair
#define     all(x)                       x.begin(),x.end()
#define     sz(x)                        (int)(x).size()
#define     Fast_Read                    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define     Precision(x)                 cout.setf(ios::fixed); cout.precision(x);
using namespace std;
int dx[]= {0,0,1,-1,-1,-1,1,1};
int dy[]= {1,-1,0,0,-1,1,1,-1};
typedef long long ll;
typedef long double ld;
ll check(ll n)
{
    ll originalInteger = n,reversedInteger=0;
    while( n!=0 )
    {
        ll remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }
    if (originalInteger == reversedInteger)
       return 1;
    else
        return 0;
}
ll rev(ll n){
    ll reversedInteger=0;
    while( n )
    {
        ll remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }
    return reversedInteger;
}
int main()
{
    Fast_Read
    Precision(10)
    // freopen ("output.txt","w",stdout);
    //freopen ("input.txt","r",stdin);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        ll action=0,orginal=n;
        bool ok=0;
        while(!ok){
            ll t=rev(n);
            n=n+t;
            ok=check(n);
            action++;
        }
        cout<<action<<sp<<n<<nl;

    }

    return 0;
}

