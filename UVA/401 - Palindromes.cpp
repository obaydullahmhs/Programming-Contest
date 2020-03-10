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
    while(cin>>s){
        bool notpal=0,pal=0;
        string alpha="A   3  HIL JM O   2TUVWXY5",num="01SE Z  8 ";
        for(int i=0,j=sz(s)-1;i<=j;i++,j--){
            if(s[i]!=s[j]) notpal=1;
            if(s[i]>='A'&&s[i]<='Z'){
                if(s[j]!=alpha[s[i]-'A']) pal=1;
            }
            else{
                if(s[j]!=num[s[i]-'0']) pal=1;
            }
        }
        cout<<s<<" -- is ";
        if(notpal){
            if(pal) cout<<"not a palindrome."<<nl<<nl;
            else cout<<"a mirrored string."<<nl<<nl;
        }
        else{
            if(pal) cout<<"a regular palindrome."<<nl<<nl;
            else cout<<"a mirrored palindrome."<<nl<<nl;
        }
    }
}
int main(){
    Fast_Read
    Precision(10)
    ///freopen ("output.txt","w",stdout);
    ///freopen ("input.txt","r",stdin);
    int tc=1;
    ///cin>>tc;
    while(tc--){
      solve();
    }

    return 0;
}

