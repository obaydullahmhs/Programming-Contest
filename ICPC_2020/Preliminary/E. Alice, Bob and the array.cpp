
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
const int N = 100005;
ll ar[N];
int cs = 0;
void solve(){
    int n; scanf("%d", &n);
    for(int i = 0;i<n;i++) scanf("%lld", &ar[i]);
    ll mx = *max_element(ar, ar + n);
    printf("Case %d: ",++cs);
    if(mx <= 0){
        printf("%lld %lld\n",mx, 0);
        return;
    }
    int op = 0;
    int x = 0, y = n - 1;
    while(x < n && ar[x]<=0) x++;
    while(y>=0 && ar[y]<=0) y--;
    int cnt = 0;
    for(int i = x;i<=y;i++){
        if(ar[i]>=0){
            if(ar[i]==0 && cnt>0){
                cnt++;
            }else{
                if(cnt) op++;
                cnt = 0;
            }
        }else{
            cnt++;
        }
    }
    if(cnt) op++;
    ll sum = 0;
    for(int i = 0;i<n;i++){
        if(ar[i]>=0) sum += ar[i];
    }
    printf("%lld %d\n", sum, op);

}
int main(){

    //Fast_Read
    Precision(10)
#ifdef obaydullah
    double start_time = clock();
    ///freopen ("output.txt","w",stdout);
    ///freopen ("input.txt","r",stdin);
#endif
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
