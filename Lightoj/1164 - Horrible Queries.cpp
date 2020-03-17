#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
class segmentWithLazy
{
private:
    struct data{
        ll prop,sum;
        data(){
            prop=sum=0;
        }
        data(ll _sum,ll _prop){
            sum=_sum;
            prop=_prop;
        }
    };
public:
    vector<data> tree;
    segmentWithLazy(){
        tree=vector<data>(400020,data(0,0));
    }

    segmentWithLazy(int n){

        tree=vector<data>(4*(n+10),data(0,0));
    }

    void SegmentTree(vector<ll> &given, int node, int low, int high)
    {
        if (low == high)
        {
            tree[node].sum = given[low];
            return;
        }
        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (low + high) / 2;
        SegmentTree(given, left, low, mid);
        SegmentTree(given, right, mid + 1, high);
        tree[node].sum = tree[left].sum + tree[right].sum;
    }
    void update(int node, int low, int hi, int i, int j, ll value)
    {
        if (i>hi || j<low)
            return;
        if (low >= i&&hi <= j){
            tree[node].sum+=((hi-low+1)*value);
            tree[node].prop+=value;
            return;
        }

        int mid = (low + hi) / 2;
        int left = 2 * node;
        int right = left + 1;
        update(left, low, mid, i, j, value);
        update(right, mid + 1, hi, i, j, value);

        tree[node].sum=tree[left].sum+tree[right].sum+(hi-low+1)*tree[node].prop;
    }
    ll query(int node, int low, int hi, int i, int j,ll carry=0)
    {
        if (i>hi || j<low)
            return 0LL;
        if (low >= i&&hi <= j)
            return tree[node].sum+(hi-low+1)*carry;
        int mid = (low + hi) / 2;
        int left = 2 * node;
        int right = left + 1;

        ll x = query(left, low, mid, i, j,carry+tree[node].prop);
        ll y = query(right, mid + 1, hi, i, j,carry+tree[node].prop);

        return x + y;
    }
};
int cs=0;
void solve(){

    cout<<"Case "<<++cs<<":\n";
    int n,q;
    cin>>n>>q;

    segmentWithLazy seg(n);


    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        b++,c++;
        if(a==0){
            ll d;
            cin>>d;
            seg.update(1,1,n,b,c,d);
        }
        else cout<<seg.query(1,1,n,b,c)<<endl;

    }
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

