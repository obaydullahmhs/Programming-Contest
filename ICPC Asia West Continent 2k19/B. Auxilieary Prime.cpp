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
bool mark[1000010];
void sieve(int n){
    for(int p=3; p*p<=n; p=p+2)
        if(mark[p]==0)
            for(int i=p*p; i<=n; i+=2*p)
                mark[i]=1;
}
void solve(){
    string s; cin>>s;
    int n = sz(s);
    for(int i = 0;i<n;i++){
        string sub = s;
        for(int j = (int)(i==0);j<10;j++){
            sub[i] = j + '0';
            int num = stoi(sub);
            if(num%2!=0 && !mark[num]){
                cout<<"yes\n";
                return;
            }
        }
    }
    cout<<"no\n";
}
int main(){

    Fast_Read
    Precision(10)
#ifdef obaydullah
    double start_time = clock();
    ///freopen ("output.txt","w",stdout);
    ///freopen ("input.txt","r",stdin);
#endif
    sieve(1000005);
    int tc=1; cin>>tc;
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
