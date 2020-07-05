#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<typename T>
class segmentWithLazy{
private:
    struct data{
        T prop,one,two,zero;
        data():prop(0),one(0),two(0),zero(0){}
        data(T _prop, T _one,T _two, T _zero):prop(_prop),one(_one),two(_two),zero(_zero){}
    };
    int n;
    vector<data> tree;
public:
    segmentWithLazy():n(2e5),tree(3*n+15,data(0,0,0,0)){}
    segmentWithLazy(int _n):n(_n),tree(3*n+15,data(0,0,0,0)){}
    void init(int _n){n =_n,tree.assign(3*n+15,data(0,0,0,0));}
    void SegmentTree(int node, int low, int high){
        if (low == high){
            tree[node] = data(0,0,0,1);
            return;
        }
        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (low + high) / 2;
        SegmentTree(left, low, mid);
        SegmentTree(right, mid + 1, high);
        tree[node].zero = tree[left].zero + tree[right].zero;
    }
    void propagate(int node,int low,int hi){
        int left=2*node;
        int right=left+1;
        int mid =(low+hi)/2;
        tree[node].prop%=3;
        data input; input.one = tree[node].one,input.two = tree[node].two, input.zero=tree[node].zero;
        if(tree[node].prop==1) tree[node].one = input.zero, tree[node].zero=input.two,tree[node].two = input.one;
        else if(tree[node].prop==2) tree[node].one = input.two, tree[node].zero=input.one,tree[node].two = input.zero;
        if(hi!=low){
            tree[left].prop+=tree[node].prop;
            tree[right].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }
    void update(int node,int low,int hi,int i,int j,T value){
        int left=2*node;
        int right=left+1;
        if(tree[node].prop) propagate(node,low,hi);
        if(hi<i|j<low) return;
        if(low>=i&&hi<=j){
            assert(value==1);
            data input; input.one = tree[node].one,input.two = tree[node].two, input.zero=tree[node].zero;
            tree[node].one = input.zero, tree[node].zero=input.two,tree[node].two = input.one;
            if(hi!=low){
                tree[left].prop+=value;
                tree[right].prop+=value;
            }
            tree[node].prop=0;
            return ;
        }
        int mid=(low+hi)/2;
        update(left,low,mid,i,j,value);
        update(right,mid+1,hi,i,j,value);
        tree[node].one = tree[left].one + tree[right].one;
        tree[node].two = tree[left].two + tree[right].two;
        tree[node].zero = tree[left].zero + tree[right].zero;
    }
    T query(int node,int low,int hi,int i,int j){
        int left=2*node;
        int right=left+1;
        if(tree[node].prop) propagate(node,low,hi);
        if(hi<i||j<low) return 0;
        if(low>=i&&hi<=j)
            return tree[node].zero;
        int mid=(low+hi)/2;
        T x= query(left,low,mid,i,j);
        T y= query(right,mid+1,hi,i,j);
        return x+y;
    }
};
int cs = 0;
void solve(){
    int n, q; scanf("%d %d",&n, &q);
    segmentWithLazy<int> seg(n);
    seg.SegmentTree(1,1,n);
    printf("Case %d:\n",++cs);
    while(q--){
        int choose, l, r; scanf("%d %d %d",&choose, &l, &r);
        if(choose==1) printf("%d\n",seg.query(1,1,n,l+1,r+1));
        else seg.update(1,1,n,l+1,r+1,1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int tc=1; scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}

