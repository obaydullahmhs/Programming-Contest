#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace SuffixArray{  ///0 based string

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
                for(swap(wa, wb), p = 1, wa[sa[0]] = 0, i = 1; i < n; i++)
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
            if(l == r) return 1e7;
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
template<typename T>
class mergeSortTree{    /** 1 - Base **/
private:

    int n;
    vector< vector<T> > tree;

    virtual inline T segValue(const vector<T>& v, T val, T val1){  /// queryType
        return upper_bound(v.begin(), v.end(), val1) - lower_bound(v.begin(), v.end(), val);    ///number of elements less than or equal to val
    }

    void buildTree(int node, int lo, int hi,const vector<T>& v){

        if(lo == hi){

            tree[node].push_back(v[lo]);
            return;
        }

        buildTree(node<<1, lo, (lo + hi)>>1, v);
        buildTree(1|(node<<1), 1 + ((lo + hi)>>1), hi, v);

        tree[node].resize(tree[node<<1].size() + tree[1|(node<<1)].size());
        merge(tree[node<<1].begin(), tree[node<<1].end(), tree[1|(node<<1)].begin(), tree[1|(node<<1)].end(), tree[node].begin());
    }

    T query(int node, int lo, int hi, int i, int j, T val, T val1){

        if(i > hi || j < lo) return 0;
        if(lo >= i && hi <= j){
            return segValue(tree[node], val, val1);
        }

        return query(node<<1, lo, (lo + hi)>>1, i, j, val, val1) + query(1|(node<<1), 1 + ((lo + hi)>>1), hi, i, j, val, val1);
    }


public:

    void init(int _n){
       n = _n;   tree.resize(4*_n, vector<T>());
    }
    void buildTree(const vector<T>& v){
        buildTree(1, 1, n, v);
    }
    T query(int l, int r, T val, T val1){
        return query(1, 1, n, l, r, val, val1);
    }
};
using namespace SuffixArray;
int n;
string s;
int findAnswer(int ni, int len, int a, int b, mergeSortTree<int>& mrg, DaKasai& kasai){
  int rr = kasai.getRank(ni) - 1;
  int lo = 0, hi = rr, l = rr, r = rr;
  while(lo <= hi){
    int mid = (lo + hi) >> 1;
    if(kasai.getLCP(mid, rr) >= len) l = mid, hi = mid - 1;
    else lo = mid + 1;
  }
  lo = rr, hi = n - 1;
  while(lo <= hi){
    int mid = (lo + hi) >> 1;
    if(kasai.getLCP(rr, mid) >= len) r = mid, lo = mid + 1;
    else hi = mid - 1;
  }
  int ans = mrg.query(l + 1, r + 1, a, b);
  return ans;
}
void solve(){
  cin >> s;
  n = s.size();
  DaKasai kasai;
  mergeSortTree<int> mrg;
  mrg.init(n);
  kasai.init(n);
  kasai.KasaiStart(s);
  vector<int> M(1, 0);
  for(int i = 0; i < n; i++){
    M.push_back(kasai.getSuf(i) + 1);
  }
  mrg.buildTree(M);
  int q; cin >> q;
  while(q--){
    int l1, r1, l, r; cin >> l1 >> r1 >> l >> r;
    int ni = l - 1;
    int len = r - l + 1;
    cout << findAnswer(ni, len, l1, r1 - len + 1, mrg, kasai) << "\n";
  }
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

