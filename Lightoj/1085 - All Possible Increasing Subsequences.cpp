#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll M = 1000000007LL;
template<typename T>
istream& operator>>(istream& is, vector<T>& input){
    for(T& in:input) is >> in; return is;
}
template<typename T>
class fenwick{
    int n;
    vector<T> tree;
public:
    fenwick():n(2e5,0),tree(n+5,0){}
    fenwick(int _n):n(_n),tree(n+5,0){}
    void init(int _n){n = -n, tree.assign(n+5,0);}
    void Update(int pos, T val, int limit){
        while(pos<=limit){
            tree[pos]+=val;
            tree[pos]%=M;
            pos+=pos&(-pos);
        }
    }
    T Query(int pos){
        T sum=0;
        while(pos>0){
            sum+=tree[pos];
            pos-=pos&(-pos);
            sum%=M;
        }
        return sum;
    }
};
int cs = 0;
void solve(){
    int n;cin>>n;
    vector<ll> v(n);
    cin>>v;fenwick<ll> fen(n);
    set<ll> st(v.begin(),v.end());
    map<ll, int> mp;int val = 0;ll ans = 0;
    for(auto it:st)  mp[it] = ++val;
    for(int i=0;i<n;i++){
        ll sub = fen.Query(mp[v[i]]-1) + 1;
        ans+=sub; ans%=M;
        fen.Update(mp[v[i]], sub%M, n);
    }
    cout<<"Case "<<++cs<<": "<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
