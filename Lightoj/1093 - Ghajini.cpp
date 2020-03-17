#include <bits/stdc++.h>

using namespace std;
class segment
{
private:
    vector<pair<int,int>> tree;
public:
    segment(){

        tree.assign(400020,pair<int,int>(0,0));
    }

    segment(int n){

        tree.assign(4*(n+10),pair<int,int>(0,0));
    }

    pair<int,int> mergefirst(pair<int,int> a,pair<int,int> b){

        pair<int,int> ans;
        if(a.first!=-1 && b.first==-1) ans.first=max(a.first,a.second),ans.second=min(a.first,a.second);
        else if(b.first!=-1 && a.first==-1) ans.first=max(b.first,b.second),ans.second=min(b.first,b.second);
        else ans.first=max(a.first,max(a.second,max(b.first,b.second))),ans.second=min(a.first,min(a.second,min(b.first,b.second)));
        if(a.first==-1 && b.first==-1) assert(false);
        return ans;

    }
    void SegmentTree(vector<int> &given, int node, int low, int high){

        if (low == high){
            tree[node] = pair<int,int>(given[low],given[low]);
            return;
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (low + high) / 2;

        SegmentTree(given, left, low, mid);
        SegmentTree(given, right, mid + 1, high);

        tree[node]=mergefirst(tree[left], tree[right]);

    }
    pair<int,int> query(int node, int low, int hi, int i, int j)
    {
        if (i>hi || j<low)
            return pair<int,int>(-1,-1);
        if (low >= i&&hi <= j)
            return tree[node];

        int mid = (low + hi) / 2;
        int left = 2 * node;
        int right = left + 1;

        pair<int,int> x = query(left, low, mid, i, j);
        pair<int,int> y = query(right, mid + 1, hi, i, j);

        return mergefirst(x,y);
    }
    int RET(int node,int low,int high, int i, int j){

        pair<int,int> ans=query(node,low,high,i,j);
        return abs(ans.second-ans.first);
    }
};
int cs=0;
void solve(){

    int n,d;
    cin>>n>>d;

    vector<int> v;
    v.push_back(0);

    for(int in,i=0;i<n;i++){
        cin>>in;
        v.push_back(in);
    }

    segment seg(n);

    seg.SegmentTree(v,1,1,n);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i+d-1>n) break;
        ans=max(ans,seg.RET(1,1,n,i,i+d-1));
    }
    cout<<"Case "<<++cs<<": ";
    cout<<ans<<endl;
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

