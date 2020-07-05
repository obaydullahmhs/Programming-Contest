#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<typename T>
class segmentWithLazy{
private:
    struct data{
        T prop,sum;
        data():prop(0),sum(0){}
        data(T _sum,T _prop):sum(_sum),prop(_prop){}
    };
    int n;
    vector<data> tree;
public:
    segmentWithLazy():n(2e5),tree(4*n+15,data(0,-1)){}
    segmentWithLazy(int _n):n(_n),tree(4*n+15,data(0,-1)){}
    void init(int _n){n =_n,tree.assign(4*n+15,data(0,-1));}
    void propagate(int node,int low,int hi){
        int left=2*node;
        int right=left+1;
        int mid =(low+hi)/2;
        tree[node].sum=(hi-low+1)*tree[node].prop;
        if(hi!=low){
            tree[left].prop=tree[node].prop;
            tree[right].prop=tree[node].prop;
        }
        tree[node].prop=-1;
    }
    void update(int node,int low,int hi,int i,int j,T value){
        int left=2*node;
        int right=left+1;
        if(tree[node].prop!=-1) propagate(node,low,hi);
        if(hi<i|j<low) return;
        if(low>=i&&hi<=j){
            tree[node].sum=(hi-low+1)*value;
            if(hi!=low){
                tree[left].prop=value;
                tree[right].prop=value;
            }
            tree[node].prop=-1;
            return ;
        }
        int mid=(low+hi)/2;
        update(left,low,mid,i,j,value);
        update(right,mid+1,hi,i,j,value);
        tree[node].sum=tree[left].sum+tree[right].sum;
    }
    T query(int node,int low,int hi,int i,int j){
        int left=2*node;
        int right=left+1;
        if(tree[node].prop!=-1) propagate(node,low,hi);
        if(hi<i||j<low) return 0;
        if(low>=i&&hi<=j)
            return tree[node].sum;
        int mid=(low+hi)/2;
        T x= query(left,low,mid,i,j);
        T y= query(right,mid+1,hi,i,j);
        return x+y;
    }
};
int cs = 0;
void solve(){
    int n, q;
    scanf("%d %d", &n, &q);
    segmentWithLazy<ll> seg(n);
    printf("Case %d:\n",++cs);
    while(q--){
        int choose, l, r;scanf("%d", &choose);
        if(choose==1){
            ll val;
            scanf("%d %d %lld",&l, &r, &val);l++, r++;
            seg.update(1,1,n,l,r,val);
        }else{
            scanf("%d %d", &l, &r);l++, r++;
            ll val = seg.query(1,1,n,l,r);
            if(val%(r-l+1)==0) printf("%lld\n", val/(r-l+1));
            else{
                ll gcd = __gcd(val, (ll)(r-l+1));
                printf("%lld/%lld\n",val/gcd,(r-l+1)/gcd);
            }
        }
    }
}
int main() {
    int tc=1;
    scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}
