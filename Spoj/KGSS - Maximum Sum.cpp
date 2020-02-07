#include <bits/stdc++.h>

using namespace std;
class segment
{
private:
    vector<pair<int,int>> tree;
public:
    segment(){

        tree=vector<pair<int,int>>(400020,pair<int,int>(0,0));
    }

    segment(int n){

        tree=vector<pair<int,int>>(4*(n+10),pair<int,int>(0,0));
    }

    pair<int,int> mergefirst(pair<int,int> a,pair<int,int> b){

        priority_queue<int> pq;
        pq.push(a.first);
        pq.push(a.second);
        pq.push(b.first);
        pq.push(b.second);

        pair<int,int> ans;
        ans.first=pq.top();pq.pop();
        ans.second=pq.top();

        return ans;

    }
    void SegmentTree(vector<int> &given, int node, int low, int high){

        if (low == high){
            tree[node] = pair<int,int>(given[low],0);
            return;
        }

        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (low + high) / 2;

        SegmentTree(given, left, low, mid);
        SegmentTree(given, right, mid + 1, high);

        tree[node]=mergefirst(tree[left], tree[right]);

    }
    void update(int node, int low, int hi, int i, int value){

        if (low == hi){

            tree[node].first = value;
            return;
        }

        int mid = (low + hi) / 2;
        int left = 2 * node;
        int right = left + 1;

        if (i <= mid)
            update(left, low, mid, i, value);
        else
            update(right, mid + 1, hi, i, value);

        tree[node]=mergefirst(tree[left], tree[right]);

    }
    pair<int,int> query(int node, int low, int hi, int i, int j)
    {
        if (i>hi || j<low)
            return pair<int,int>(0,0);
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
        return ans.second+ans.first;
    }
};

void solve(){

    int n;
    cin>>n;

    vector<int> v;
    v.push_back(0);

    for(int in,i=0;i<n;i++){
        cin>>in;
        v.push_back(in);
    }

    segment seg(n);

    seg.SegmentTree(v,1,1,n);

    int q;
    cin>>q;

    while(q--){

        char c;
        int a,b;
        cin>>c;
        cin>>a>>b;
        if(c=='U'){
            seg.update(1,1,n,a,b);
        }
        else cout<<seg.RET(1,1,n,a,b)<<endl;

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

