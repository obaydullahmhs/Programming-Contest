#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<typename T>
class fenwick{
    int n;
    vector<T> tree;
public:
    fenwick():n(2e5),tree(n+5,0){}
    fenwick(int _n):n(_n),tree(n+5,0){}
    void init(int _n){n = -n, tree.assign(n+5,0);}
    void Update(int pos, T val, int limit){
        while(pos<=limit){
            tree[pos]+=val;
            pos+=pos&(-pos);
        }
    }
    T Query(int pos){
        T sum=0;
        while(pos>0){
            sum+=tree[pos];
            pos-=pos&(-pos);
        }
        return sum;
    }
};
int cs = 0;
void solve(int n){
    vector<ll> v(n+1);
    set<int> ind;
    fenwick<ll> fen(n);
    for(int i=1;i<=n;i++){
        cin>>v[i]; fen.Update(i,v[i],n);
        ind.insert(i);
    }
    int q; cin>>q;
    cout<<"Case #"<<++cs<<":\n";
    while(q--){
        int choose; cin>>choose;
        int l, r; cin>>l>>r;
        if(l>r) swap(l, r);
        if(choose){
            cout<<fen.Query(r)-fen.Query(l-1)<<"\n";
        }else{
            int x = l-1;
            while(true){
                if(ind.upper_bound(x)==ind.end()) break;
                x = *ind.upper_bound(x);
                if(x>r) break;
                fen.Update(x,-v[x], n);
                v[x] = sqrt(v[x]);
                fen.Update(x, v[x], n);
                if(v[x]==1) ind.erase(x);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int tc=1;
    while(cin>>tc){
        solve(tc);
    }
    return 0;
}
