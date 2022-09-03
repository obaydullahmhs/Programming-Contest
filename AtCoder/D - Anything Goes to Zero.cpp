/**বিসমিল্লাহির রহমানির রহীম **/

#include<bits/stdc++.h>
#define     pi                           acos(-1.0)
#define     eps                          1e-9
#define     ff                           first
#define     ss                           second
#define     nl                           '\n'
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

template<class T>
istream& operator>>(istream& is, vector<T>& input){
  for(T& in:input) is >> in; return is;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &input){
  bool isFirst=true;for(const T& out:input){if(isFirst){os<<out;isFirst=false;}else os<<" "<<out;}return os;
}

///******************************************START******************************************

class FrontHash{    /// For Front Hash
private:
    long long base, M, len;
    vector<long long> hashing, P; /// P for base power table

public:

    void init(const string& s, const long long& _base, const long long _M){ /// 0 based

        this->base = _base;
        this->M = _M;
        this->len = s.size();
        this->P.assign(len + 5, 0);
        this->hashing.assign(len + 5, 0);

        long long calculateHash = 0;
        P[0] = 1;
        for(int i = 1; i <=len; i++)
            P[i] = (P[i - 1] * this->base) % this->M;   /// Power of base

        for(int i = 0; i < len; i++){       ///front hashing array of string s

            calculateHash = (calculateHash * this->base) + s[i] - '0';
            calculateHash %= this->M;
            this->hashing[i] = calculateHash;
        }

    }

    long long getFrontHash(int l, int r){   ///0 based
        if(r < l) return 0;
        long long ret = this->hashing[r];
        if(l > 0){
            ret = (ret - this->P[r - l + 1] * this->hashing[l - 1]) % this->M;  /// (r - l  + 1) length of the substring
            if(ret < 0) ret += this->M;
        }

        return ret;
    }
    long long merge(int x1, int y1, int x2, int y2, int c, int len){
      ll r1 = getFrontHash(x1, y1);
      ll r2 = getFrontHash(x2, y2);
      ll ans = r1*2 + c;
      ans %= M;
      ans = (ans * P[len] + r2) % M;
      return ans;
    }
};
void solve(){
  int n; cin >> n;
  string s; cin >> s;
  FrontHash f1, f2;
  int cnt = count(all(s), '1');
  if(cnt - 1 > 0) f1.init(s, 2, cnt - 1);
  f2.init(s, 2, cnt + 1);
  for(int i = 0; i < n; i++){
    int nn = cnt;
    if(s[i] == '0') ++nn;
    else --nn;
    if(nn == 0) cout << 0 << "\n";
    else if(nn == cnt + 1){
      ll ret = f2.merge(0, i - 1, i + 1, n - 1, (s[i] =='0'? 1:0), n - i -1);
      ll ans = 1;
      while(ret){
        ++ans;
        ret %= __builtin_popcountll(ret);
      }
      cout << ans << "\n";

    } else{
      ll ret = f1.merge(0, i - 1, i + 1, n - 1, (s[i] =='0'? 1:0), n - i -1);
      ll ans = 1;
      while(ret){
        ++ans;
        ret %= __builtin_popcountll(ret);
      }
      cout << ans << "\n";
    }
  }
}
int main(){

  Fast_Read
  Precision(10)
#ifdef obaydullah
  double start_time = clock();
  ///freopen ("output.txt","w",stdout);
  ///freopen ("input.txt","r",stdin);
#endif
  int tc = 1; //cin >> tc;
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
