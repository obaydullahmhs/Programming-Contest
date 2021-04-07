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

int cs = 0;
vector<ll> primes;
void sieve(int n){
    vector<bool> mark(n+2,false);
    primes.push_back(2);
    for(int p=3;p*p<=n;p=p+2){
        if(mark[p]==0){
            for(int i=p*p;i<=n;i+=p*2){
                mark[i]=1;
            }
        }
    }
    for(int i=3;i<=n;i=i+2){
        if(!mark[i]){
            primes.push_back(i);
        }
    }
}

ll Range(ll stab, ll r){

    vector<ll> prime;
    for(int i = 0;i<primes.size() && primes[i]*primes[i]<=stab;i++){
        if(stab%primes[i]==0){
            prime.push_back(primes[i]);
            while(stab%primes[i]==0) stab/=primes[i];
        }
    }
    if(stab>1) prime.push_back(stab);

    vector<ll> cnt(10, 0);
    int n = prime.size();
    for(int i = 1;i<(1LL<<n);i++){
        ll sum = 1, pcnt = 0;
        for(int j = 0;j<n;j++){
            if(isOn(i, j)){
                sum *= prime[j];
                pcnt++;
            }
        }
        if(pcnt&1) cnt[1] += (r/sum);
        else cnt[0] += (r/sum);
    }

    return r - (cnt[1] - cnt[0]);


}
void solve(){
    ll a, b, m;
    scanf("%lld %lld %lld", &a, &b, &m);
    printf("Case %d: ",++cs);
    if(a>b) swap(a, b);
    ll x = b - a;
    ll upB = b + m;
    ll upL = b;
    if(a==1 && b==1){
        printf("1\n");
        return;
    }
    if(x==0){
        printf("0\n");
        return;
    }

    printf("%lld\n", Range(x, upB) - Range(x, upL - 1));

}
int main(){

    //Fast_Read
    Precision(10)
#ifdef obaydullah
    double start_time = clock();
    ///freopen ("output.txt","w",stdout);
    ///freopen ("input.txt","r",stdin);
#endif
    sieve(2000010);
    int tc=1; scanf("%d", &tc);
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

