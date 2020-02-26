///বিসমিল্লাহির_রহমানির_রহীম
#include<bits/stdc++.h>
#define     pie                          acos(-1.0)
#define     N                            200015
#define     eps                          1e-9
#define     ff                           first
#define     ss                           second
#define     nl                           '\n'
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
const ll mod = (ll)1e9+7LL;
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
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
int cnt[31][N]={0},n,q;
void doCum(){
    for(int i=0;i<31;i++){
        for(int j=1;j<=n;j++){
            cnt[i][j]+=cnt[i][j-1];
        }
    }
}
ll query(int l,int r){
    ll ans=0;
    for(int i=0;i<31;i++){
        int one=(cnt[i][r]-cnt[i][l-1]);
        int zero=(r-l+1)-one;
        if(one){
            ll subans=bigmod(2LL,((ll)one-1LL),mod);
            subans*=bigmod(2LL,(ll)zero,mod);
            subans%=mod;
            subans*=bigmod(2LL,(ll)i,mod);
            subans%=mod;
            ans+=subans;
            ans%=mod;
        }
    }
    return ans;
}
void solve(){
    n=nxt(),q=nxt();
    for(int in,i=1;i<=n;i++){
        in=nxt();
        for(int j=0;j<31;j++) {
            if(ison(in,j)) cnt[j][i]++;
        }
    }
    doCum();
    while(q--){
        int l=nxt(),r=nxt();
        printf("%lld\n",query(l,r));
    }


}
int main(){
    //Fast_Read
    Precision(10)
    #ifdef obaydullah
        double start_time = clock();
        ///freopen ("output.txt","w",stdout);
        ///freopen ("input.txt","r",stdin);
    #endif
    int tc=1;
    ///cin>>tc;
    while(tc--){
      solve();
    }
    #ifdef obaydullah
        double end_time = clock();
        cerr<<"Time = "<<fixed<<setprecision(10)<<(end_time - start_time) / CLOCKS_PER_SEC<<'\n';
    #endif

    return 0;
}

