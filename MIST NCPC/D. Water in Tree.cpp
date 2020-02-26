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
vector<int> adj[N];
vector<int> order,FirstNode,orderIndex;
void init(int n){
    for(int i=0;i<=n+100;i++) adj[i].clear();
    FirstNode.assign(n+100,-1);
    orderIndex.assign(n+100,0);
    order.clear();
    order.push_back(-1);
}
void AddEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Sort(int n){
    for(int i=0;i<n+100;i++){
        sort(all(adj[i]));
    }
}
void dfs(int node=1, int par=-1){

    for(auto it:adj[node]){

        if(it!=par){
            dfs(it,node);
            order.push_back(it);
            if(adj[it].size()==1){
                if(FirstNode[node]==-1){
                    FirstNode[node]=it;
                }
                FirstNode[it]=it;
            }
            else{
                if(FirstNode[node]==-1){
                    FirstNode[node]=FirstNode[it];
                }
            }
        }
    }

}
int cs=0;
void solve(){
    int n=nxt();
    init(n);

    for(int i=0;i<n-1;i++){
        int u=nxt(),v=nxt();
        AddEdge(u,v);
    }
    Sort(n);
    dfs();
    order.push_back(1);
    if(n==1) FirstNode[1]=1;
    for(int i=1;i<order.size();i++){
        orderIndex[order[i]]=i;
    }
    set<int> st;
    for(int i=1;i<=n;i++) st.insert(i);
    int q=nxt();
    printf("Case %d:\n",++cs);
    while(q--){
        int inn=nxt();
        if(inn==1){
            int u=nxt(),x=nxt();
            int first=FirstNode[u];
            int ind=orderIndex[first];
            auto lt=st.lower_bound(ind);
            for(int i=1; i<=x && lt!=st.end() && *lt<=orderIndex[u];  i++){
                st.erase(lt);
                lt = st.lower_bound(ind);
            }
        }else{
            int u=nxt();
            u=orderIndex[u];
            if(st.find(u)!=st.end()) printf("0\n");
            else printf("1\n");
        }

    }

}
int main()
{
    //Fast_Read
    Precision(10)
#ifdef obaydullah
    double start_time = clock();
    ///freopen ("output.txt","w",stdout);
    ///freopen ("input.txt","r",stdin);
#endif
    int tc=nxt();
    while(tc--)
    {
        solve();
    }
#ifdef obaydullah
    double end_time = clock();
    cerr<<"Time = "<<fixed<<setprecision(10)<<(end_time - start_time) / CLOCKS_PER_SEC<<'\n';
#endif

    return 0;
}
