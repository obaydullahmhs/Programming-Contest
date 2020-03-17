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
    string input,query[200];
    query[0]="http://www.lightoj.com/";
    int i=0,j=0;
    while(cin>>input&&input!="QUIT"){
        if(input=="VISIT"){
            string a;
            cin>>a;
            i++;
            query[i]=a;
            j=i;
            cout<<a<<nl;
        }
        else if(input=="BACK"){
            if(i==0) cout<<"Ignored"<<nl;
            else{
                i--;
                cout<<query[i]<<nl;
            }
        }
        else{
            if(i==j) cout<<"Ignored"<<nl;
            else{
                i++;
                cout<<query[i]<<nl;
            }
        }
    }
}
int main(){
    //Fast_Read
    Precision(10)
    #ifdef obaydullah
        double start_time = clock();
        freopen ("output.txt","w",stdout);
        ///freopen ("input.txt","r",stdin);
    #endif
    int tc=1,cs=0;
    cin>>tc;
    while(tc--){
      cout<<"Case "<<++cs<<":"<<nl;
      solve();
    }
    #ifdef obaydullah
        double end_time = clock();
        fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
    #endif
    return 0;
}

