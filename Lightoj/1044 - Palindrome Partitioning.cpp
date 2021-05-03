#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MOD [] = {1000000007LL, 2117566807LL, 1000000007LL, 1000000037LL};
const long long BASE[] = {1572872831LL, 1971536491LL, 1000003LL, 31};

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

            calculateHash = (calculateHash * this->base) + s[i];
            calculateHash %= this->M;
            this->hashing[i] = calculateHash;
        }

    }

    long long getFrontHash(int l, int r){   ///0 based

        long long ret = this->hashing[r];
        if(l > 0){
            ret = (ret - this->P[r - l + 1] * this->hashing[l - 1]) % this->M;  /// (r - l  + 1) length of the substring
            if(ret < 0) ret += this->M;
        }

        return ret;
    }
};

class BackHash{     /// For Back Hash
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

        for(int i = len - 1; i >= 0; i--){       ///back hashing array of string s

            calculateHash = (calculateHash * this->base) + s[i];
            calculateHash %= this->M;
            this->hashing[i] = calculateHash;
        }

    }

    long long getBackHash(int l, int r){   ///0 based

        long long ret = this->hashing[l];
        if(r + 1 < len){
            ret = (ret - this->P[r - l + 1] * this->hashing[r + 1]) % this->M;  /// (r - l  + 1) length of the substring
            if(ret < 0) ret += this->M;
        }

        return ret;
    }
};
const int N = 1005;
int dp[N], cs;
void solve(){

    string s; cin >> s;
    int n = s.size();

    FrontHash F; F.init(s, BASE[0], MOD[0]);
    BackHash B; B.init(s, BASE[0], MOD[0]);

    for(int i = 0; i <= n; i++) dp[i] = INT_MAX - 5;

    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j >= 0; j--){
            if(F.getFrontHash(j, i) == B.getBackHash(j, i)){
                dp[i + 1] = min(dp[i + 1], 1 + dp[j]);
            }
        }
    }
    cout << "Case "<< ++cs << ": " << dp[n] << "\n";
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1; cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}
/**

**/

