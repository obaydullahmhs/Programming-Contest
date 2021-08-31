#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

namespace SuffixArray{
    class DaKasai{
    private:
        int n, m, Log;
        vector<vector<int> > sparse;
        vector<int> calLog, wa, wb, wws, wv, rnk, lcp, data, suf;

        inline bool cmp(const vector<int>& r, int a, int b, int l){
            return (r[a]==r[b]) && (r[a+l]==r[b+l]);
        }

        void DA(const vector<int>& r, vector<int>& sa, int n, int m){
            int i, j, p;
            vector<int> t;
            for(i = 0; i < m; i++) wws[i] = 0;
            for(i = 0; i < n; i++) wws[wa[i] = r[i]]++;
            for(i = 1; i < m; i++) wws[i] += wws[i - 1];
            for(i = n - 1; i >= 0; i--) sa[--wws[wa[i]]] = i;
            for(j = 1, p = 1; p < n; j *= 2, m = p){

                for(p = 0, i = n - j; i < n; i++) wb[p++] = i;
                for(i = 0; i < n; i++) if(sa[i] >= j) wb[p++] = sa[i] - j;
                for(i = 0; i < n; i++) wv[i] = wa[wb[i]];
                for(i = 0; i < m; i++) wws[i] = 0;
                for(i = 0; i < n; i++) wws[wv[i]]++;
                for(i = 1; i < m; i++) wws[i] += wws[i-1];
                for(i = n - 1; i >= 0; i--) sa[--wws[wv[i]]] = wb[i];
                for(t = wa, wa = wb, wb = t, p = 1, wa[sa[0]] = 0, i = 1; i < n; i++)
                    wa[sa[i]] = cmp(wb, sa[i-1], sa[i], j)? p - 1 : p++;
            }
        }

        void calheight(const vector<int>& r, const vector<int>& sa, int n){
            int i, j, k = 0;
            for(i = 1; i <= n; i++) rnk[sa[i]] = i;
            for(i = 0; i < n; lcp[rnk[i++]] = k)
                for(k?k--:0, j = sa[rnk[i]-1]; r[i+k] == r[j+k]; k++);
        }

        void Deal (const string& s){
            int n = s.size();
            for(int i = 0; i < n; i++)
                data[i] = (int)s[i];
            data[n] = 0;
            DA(data, suf, n + 1, 128);
            calheight(data, suf, n);
            for(int i = 0; i < n; i++) {
                suf[i] = suf[i+1];
                lcp[i] = lcp[i+1];
                sparse[0][i] = lcp[i];
            }
            ///here rank said in which position a suffix is situated
            ///in the sorted suffix list.

            /// suf is sorted suffix of given string
            ///lcp[i] = lcp(suf[i], suf[i-1])
        }

        void preProcess(){
            for(int i=2;i<=n;i++) calLog[i] = 1 + calLog[i/2];
            for(int i=1;i<=Log;i++)
                for(int j=0;j+(1<<(i-1))<n;j++)
                    sparse[i][j] = min(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
        int getValue(int l, int r){
            if(l>r) return 0;
            int k = calLog[r-l+1];
            return min(sparse[k][l], sparse[k][r-(1<<k)+1]); ///checking first 2^k element and last 2^k
        }


    public:
        void init(int _n){
            n = _n, m = max(130, n), Log = 1 + log2(n),calLog.assign(n + 5,0),sparse.assign(Log+1,vector<int>(n + 5,0)),
            wa.resize(n + 5), wb.resize(n + 5), wws.resize(m + 5), wv.resize(n + 5), rnk.resize(n + 5),
            lcp.resize(n + 5), data.resize(n + 5), suf.resize(n + 5);
        }

        void KasaiStart(const string& s){
            Deal(s);
            preProcess();
        }

        inline int getLCP(int l, int r){
            assert(l != r);
            if(l > r) swap(l, r);
            return getValue(l + 1, r);

            ///lcp[i] = lcp(suf[i], suf[i-1])
            ///lcp(i, j) = min(lcp[i + 1], lcp[i + 2], ...., lcp[j])
        }
        inline int getSuf(int x){
            return suf[x];
        }
        inline int getRank(int x){
            return rnk[x];
        }
        vector<int> SuffixVector(){
            return suf;
        }
        vector<int> LCPVector(){
            return lcp;
        }

    };

}
using namespace SuffixArray;

DaKasai kasai;

int n;
string s;
vector<vector<int> > dp;

int F(int pos, int prev){
    if(pos >= n) return 0;

    int& ret = dp[pos][prev];
    if(ret != -1) return ret;
    ret = 0;
    if(prev == n)
        ret = (n - kasai.getSuf(pos)) + F(pos + 1, pos);

    else if(kasai.getSuf(pos) > kasai.getSuf(prev))
        ret = (n - kasai.getSuf(pos) - kasai.getLCP(pos, prev)) + F(pos + 1, pos);

    ret = max(ret, F(pos + 1, prev));
    return ret;

}
void solve(){

    cin >> n >> s;
    kasai.init(n);
    kasai.KasaiStart(s);

    dp.assign(n + 2, vector<int> (n + 2, -1));

    cout << F(0, n) << "\n";

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
