
/**বিসমিল্লাহির রহমানির রহীম **/

#include<bits/stdc++.h>
#define     pi                           acos(-1.0)
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
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
typedef long long ll;

template < class T> inline T bitOn(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitOff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T isOn(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T lcm(T a, T b){return (a/__gcd(a, b)) * b;}
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
template<class T>
istream& operator>>(istream& is, vector<T>& input){
    for(T& in:input) is >> in; return is;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &input){
    bool isFirst=true;for(const T& out:input){if(isFirst){os<<out;isFirst=false;}else os<<" "<<out;}return os;
}
///******************************************START******************************************
const int MX = (int)1e6 + 5;
const long long MOD[]  = {1000000007LL, 2117566807LL,1000000007LL};
const long long BASE[] = {1572872831LL, 1971536491LL,1000003LL};
long long pwr0[MX],pwr1[MX],HASH0[MX],HASH1[MX];
int cs = 0;
void init()
{
    pwr0[0]=1;//pwr1[0]=1;
    for(int i=1;i<MX;i++)
    {
        pwr0[i]=(pwr0[i-1] * BASE[0]) % MOD[0];
        //pwr1[i]=(pwr1[i-1] * BASE[1]) % MOD[1];
    }
}

void Construct(string &s)
{
    HASH0[0]=0;//HASH1[0]=0;
    for(int i=1;i<=s.size();i++)
    {
        HASH0[i]=(HASH0[i-1] * BASE[0] + s[i-1]) % MOD[0];
        //HASH1[i]=(HASH1[i-1] * BASE[1] + s[i-1]) % MOD[1];
    }
}
ll SubHash(const string& s){
    ll h = 0;
    for(int i = 0;i<s.size();i++){
        h += (s[i]*pwr0[sz(s) - 1 - i])%MOD[0];
        if(h >= MOD[0]) h-=MOD[0];
    }
    return h;
}
long long GetForwardHash0(int l,int r)
{
    long long hash0 = (HASH0[r] - HASH0[l-1]* pwr0[r-l+1]) % MOD[0];
    if(hash0<0) hash0+=MOD[0];
    return hash0;
}
char ar[MX];
void solve(){
    int n; scanf("%d", &n);
    vector<unordered_set<ll> > StrinhHash(1000005);
    unordered_set<int> st;
    for(int i = 0;i<n;i++){
        scanf("%s", ar);
        string x = ar;
        st.insert(sz(x));
        ll h = SubHash(x);
       // debug(h);
        StrinhHash[sz(x)].insert(h);
    }
    vector<int> kon(all(st));
    scanf("%s", ar);
    string s = ar;
    Construct(s);
    int m = sz(s);
    vector<int> dp(m + 5, INT_MAX/3);
    dp[0] = 0;
    for(int i = 0;i < m; i++){
        for(int j = 0;j<kon.size();j++){
            int l = i - kon[j] + 1;
            int r = i;
            if(l<0) continue;
            ll ret = GetForwardHash0(l + 1, r + 1);
           // debug(l, r, ret);
            if(StrinhHash[kon[j]].count(ret)){
                dp[i + 1] = min(dp[i + 1], dp[l] + 1);
            }
        }
    }
    printf("Case %d: ",++cs);
    if(dp[m]==INT_MAX/3){
        printf("impossible\n");
    }
    else{
        printf("%d\n", dp[m]);
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
    init();
    int tc = 1; scanf("%d", &tc);
    while(tc--){
        solve();
    }
#ifdef obaydullah
    double end_time = clock();
    cerr<<"Time = "<<fixed<<setprecision(10)<<(end_time - start_time) / CLOCKS_PER_SEC<<'\n';
#endif

    return 0;
}
/**

**/
