#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
class segment{

private:

    struct data{
        long long sum,left,right,mx;
        data(){
            sum=left=right=mx=0;
        }
        data(long long val){
            sum=left=right=mx=val;
        }
    };
    vector<data> tree;

public:

    segment(){

        tree=vector<data>(400020,data(0));
    }

    segment(int n){

        tree=vector<data>(n*4+20);
    }

    data returnMax(data q1, data q2){

        data q(0);
        q.sum = q1.sum + q2.sum;

        q.left = max(q1.left, q1.sum + q2.left);
        q.right = max(q2.right, q1.right + q2.sum);

        q.mx = max(q1.mx, q2.mx);
        q.mx = max(q.mx, q1.right + q2.left);
        q.mx = max(q.mx, q.sum);
        q.mx = max(q.mx, q.left);
        q.mx = max(q.mx, q.right);

        return q;

    }

    void mergedata(int idx){

        int left=idx*2, right=idx*2 +1;
        tree[idx].sum = tree[left].sum + tree[right].sum;

        tree[idx].left = max(tree[left].left, tree[left].sum + tree[right].left);
        tree[idx].right = max(tree[right].right, tree[left].right + tree[right].sum);

        tree[idx].mx = max(max(max(tree[idx].sum,tree[left].right + tree[right].left), tree[left].mx), tree[right].mx);
        tree[idx].mx = max(tree[idx].mx, tree[idx].left);
        tree[idx].mx = max(tree[idx].mx, tree[idx].right);
    }

    void SegmentTree(vector<long long> &given, int node, int low, int high){

        if(low>high) return;
        if (low == high)
        {
            tree[node] = data(given[low]);
            return;
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (low + high) / 2;

        SegmentTree(given, left, low, mid);
        SegmentTree(given, right, mid + 1, high);

        mergedata(node);
    }

    data query(int node, int low, int hi, int i, int j){

        if (i>hi || j<low)
            return data(INT_MIN);

        if (low >= i&&hi <= j)
            return tree[node];

        int mid = (low + hi) / 2;
        int left = 2 * node;
        int right = left + 1;

        data x = query(left, low, mid, i, j);
        data y = query(right, mid + 1, hi, i, j);

        return returnMax(x,y);
    }

    long long RET(int node,int low, int hi, int i, int j){

        return query(node,low,hi,i,j).mx;
    }
};

void solve(){

    int n;
    cin>>n;
    segment seg(n);

    vector<ll> v;
    v.push_back(0);
    for(ll in, i=0;i<n;i++){

        cin>>in;
        v.push_back(in);
    }

    seg.SegmentTree(v,1,1,n);
    int q;
    cin>>q;

    while(q--){

        int a,b;
        cin>>a>>b;

        cout<<seg.RET(1,1,n,a,b)<<endl;
    }

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

	int tc=1;
	while(tc--){

        solve();
	}

	return 0;
}

