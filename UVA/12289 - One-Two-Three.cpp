///বিসমিল্লাহির_রহমানির_রহীম
#include<bits/stdc++.h>
#define     pie                          acos(-1.0)
#define     N                            2000015
#define     eps                          1e-9
#define     ff                           first
#define     ss                           second
#define     nl                           '\n'
#define     mod                          1000000007
#define     sp                           ' '
#define     CLR(a)                       memset(a,0,sizeof(a))
#define     SET(a)                       memset(a,-1,sizeof(a))
#define     all(x)                       x.begin(),x.end()
#define     allr(x)                      x.rbegin(),x.rend()
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
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
#ifdef obaydullah
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************

void solve(){
    string s;
    cin>>s;
    if(sz(s)>3) cout<<3<<nl;
    else{
        int ok;
        if(s[0] == 'o' && s[1] == 'n' && s[2] == 'e') ok=0;
        else if(s[0] == 'o' && s[1] == 'n') ok=0;
        else if(s[0] == 'o' && s[2] == 'e') ok=0;
        else if(s[1] == 'n' && s[2] == 'e') ok=0;
        else if(s[0] == 't' && s[1] == 'w' && s[2] == 'o') ok=1;
        else if(s[0] == 't' && s[1] == 'w') ok=1;
        else if(s[0] == 't' && s[2] == 'o') ok=1;
        else if(s[1] == 'w' && s[2] == 'o') ok=1;
        cout<<ok+1<<nl;
    }
}
int main(){
    Fast_Read
    Precision(10)
    ///freopen ("output.txt","w",stdout);
    ///freopen ("input.txt","r",stdin);
    int tc=1;
    cin>>tc;
    while(tc--){
      solve();
    }

    return 0;
}

