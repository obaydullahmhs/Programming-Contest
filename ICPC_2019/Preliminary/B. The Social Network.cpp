///বিসমিল্লাহির_রহমানির_রহীম
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long,long long>, null_type,less<pair<long long,long long>>, rb_tree_tag,tree_order_statistics_node_update>
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
vector<int> par;
vector<ordered_set> times;

int unionFind(int u){

    if(par[u]==u){
        return u;
    }

    return par[u]=unionFind(par[u]);
}

bool sameSet(int u,int v){

    return unionFind(u)==unionFind(v);
}

void mergeUnion(int u,int v){

    int paru=unionFind(u);
    int parv=unionFind(v);

    if(paru==parv){
        return;
    }

    if(times[parv].size()>times[paru].size()){
        swap(paru,parv);
    }

    par[parv]=paru;

    for(auto t:times[parv]){
        times[paru].insert(t);
    }

    times[parv].clear();
}

void insertTime(int u,int tm,int q){

    int paru=unionFind(u);

    times[paru].insert({tm,q});

}

void solve(int cs)
{
    printf("Case %d:\n",cs);
    par.clear();
    times.clear();

    int n=nxt(),q=nxt();


    par.resize(n+1);
    times.resize(n+1);

    for(int i=1;i<=n;i++){
        par[i]=i;
    }

    int x=1;

    while(q--){
        int t=nxt();

        if(t==0){
            int u=nxt(),v=nxt();
            mergeUnion(u,v);
        }
        else if(t==1){
            int u=nxt(),tm=nxt();
            insertTime(u,tm,x);
        }
        else{
            int u=nxt(),l=nxt(),r=nxt();

            int parent=unionFind(u);


            int ub=times[parent].order_of_key({r,200000000}) - times[parent].order_of_key({l,0});

            printf("%d\n",ub);
        }
        x++;
    }

}

int main()
{
    Fast_Read
    Precision(10)
#ifdef obaydullah
    double start_time = clock();
    ///freopen ("output.txt","w",stdout);
    ///freopen ("input.txt","r",stdin);
#endif
    int tc=nxt(),cs=1;
    ///cin>>tc;
    while(tc--)
    {
        solve(cs++);
    }
#ifdef obaydullah
    double end_time = clock();
    cerr<<"Time = "<<fixed<<setprecision(10)<<(end_time - start_time) / CLOCKS_PER_SEC<<'\n';
#endif

    return 0;
}

