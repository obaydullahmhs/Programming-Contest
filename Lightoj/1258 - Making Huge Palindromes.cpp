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
class PrefixPalindrome{
private:
    int n;
    int sz;
    string pal,str;
    vector<int> lps;
public:
    PrefixPalindrome(){
        n=1e5;str="";
        sz=0;pal="";
    }
    PrefixPalindrome(int _n){
        n=_n;str="";
        sz=0;pal="";
    }
    void Assign(){
        pal="";sz=0;
        lps.assign(n,0);
    }
    void preProcess(){
        Assign();
        int i=0,j=1;
        while(j<n){
            if(str[i]==str[j]){
                lps[j]=i+1;
                i++,j++;
            }else{
                if(i!=0){
                    i=lps[i-1];
                }else{
                    lps[j]=0;
                    j++;
                }
            }
        }
        sz=lps[n-1];
    }
    void makeString(string str){
        (this->str)=str;
        (this->str)+='#';
        reverse(str.begin(),str.end());
        (this->str)+=str;
        n=(this->str).size();
        preProcess();
    }
    void longestPrefixPalindrome(const string& str){
        makeString(str);
    }
    int shorteshStringForPalindrome(const string& str){
        longestPrefixPalindrome(str);
        return sz(str)-sz+sz(str);
    }


}kmp;
int cs=0;
void solve(){
    string s;
    cin>>s;
    reverse(all(s));
    cout<<"Case "<<++cs<<": "<<kmp.shorteshStringForPalindrome(s)<<endl;
}
int main()
{
    Fast_Read;
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
