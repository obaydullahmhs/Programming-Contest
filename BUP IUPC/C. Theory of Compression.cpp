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
bool isLetter(char c){
    if(c>='a'&&c<='z') return 1;
    else return 0;
}
bool isNumber(char c){
    if(c>='0' && c<='9') return 1;
    return 0;
}
int cs=0;
void solve()
{
    string s;
    cin>>s;
    vector<pair<pair<ll,ll>,pair<string,ll>> > mp;
    ll i=0,index=0;
    while(i<sz(s)){
        string temp="";
        while(isLetter(s[i])){
            temp+=s[i];
            i++;
        }
        ll num=0;
        while( i<sz(s) && isNumber(s[i])){
            num=num*10+(ll)(s[i]-'0');
            i++;
        }
        mp.push_back(make_pair(make_pair(index,index+(num*(sz(temp))-1)),make_pair(temp,num)));index+=(num*sz(temp));
    }
    int q;
    cin>>q;
    cout<<"Case "<<++cs<<":"<<nl;
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        if(r>=index){
            cout<<-1<<endl;
            continue;
        }
        ll low=0,high=sz(mp)-1,ind=-1;
        while(low<=high){
            ll mid=(low+high)/2;
            if(mp[mid].ff.ff<=l && mp[mid].ff.ss>=l){
                ind=mid;
                break;
            }
            if(mp[mid].ff.ss<l) low=mid+1;
            else if(mp[mid].ff.ff>l) high=mid-1;
        }
        string ans="";
        for(int j=ind;j<mp.size();j++){
            while(l<=r && l<=mp[j].ff.ss){
                for(int k=((l-mp[j].ff.ff)%sz(mp[j].ss.ff));k<mp[j].ss.ff.size();k++){
                    ans+=mp[j].ss.ff[k];l++;
                    if(l>r) break;
                }
                if(l>r) break;
            }
            if(l>r) break;
        }
        cout<<ans<<endl;
    }
}
int main()
{

    int tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}
