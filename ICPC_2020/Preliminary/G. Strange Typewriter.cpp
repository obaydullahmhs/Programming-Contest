///Author: M Obaydullah

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MOD [] = {1000000007LL, 2117566807LL, 1000000007LL, 1000000037LL};
const long long BASE[] = {1572872831LL, 1971536491LL, 1000003LL, 31};

const int N = 1e5 + 5;
class FrontHash{    /// For Front Hash
private:
    long long base, M, len;
    int hashing[N], P[N]; /// P for base power table

public:

    void init(const string& s, const long long& _base, const long long _M){ /// 0 based

        this->base = _base;
        this->M = _M;
        this->len = s.size();

        long long calculateHash = 0;
        P[0] = 1;
        for(int i = 1; i <=len; i++)
            P[i] = ((long long)P[i - 1] * this->base) % this->M;   /// Power of base

        for(int i = 0; i < len; i++){       ///front hashing array of string s

            calculateHash = (calculateHash * this->base) + s[i];
            calculateHash %= this->M;
            this->hashing[i] = calculateHash;
        }

    }

    inline int getFrontHash(int l, int r){   ///0 based

        int ret = this->hashing[r];
        if(l > 0){
            ret = (ret - (long long)this->P[r - l + 1] * (long long)this->hashing[l - 1]) % this->M;  /// (r - l  + 1) length of the substring
            if(ret < 0) ret += this->M;
        }

        return ret;
    }
};

inline int StringHash(const string& s, const long long& b, const long long& M){

    long long ans = 0;
    for(const char& it: s){
        ans = (ans * b) + it;
        ans %= M;
    }

    return ans;
}

int cs;
char ar[N];
void solve(){

    int n; scanf("%d", &n);
    vector<unordered_set<int> > hashing(N);
    unordered_set<int> st;

    for(int i = 0;i<n;i++){

        scanf("%s", ar);
        string x = ar;
        st.insert(x.size());
        hashing[x.size()].insert(StringHash(x, BASE[0], MOD[0]));
    }

    vector<int> kon(st.begin(), st.end());

    scanf("%s", ar);
    string s = ar;
    int m = s.size();

    FrontHash F; F.init(s, BASE[0], MOD[0]);

    vector<int> dp(m + 5, INT_MAX/3);
    dp[0] = 0;
    for(int i = 0;i < m; i++){
        for(int j = 0;j<kon.size();j++){

            int l = i - kon[j] + 1;
            int r = i;
            if(l < 0) continue;
            ll ret = F.getFrontHash(l, r);
            if(hashing[kon[j]].count(ret))
                dp[i + 1] = min(dp[i + 1], dp[l] + 1);
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

    int tc = 1; scanf("%d", &tc);
    while(tc--){
        solve();
    }

    return 0;
}
/**

**/
