#include <bits/stdc++.h>

using namespace std;
inline int next()
{
    int aaa;
    scanf("%d",&aaa);
    return aaa;
}
class segment
{
public:
    vector<int> tree;
    segment(int n)
    {
        tree=vector<int>(4*n+20);
    }
    void SegmentTree(vector<int> &given, int node, int low, int high)
    {
        if (low == high)
        {
            tree[node] = given[low];
            return;
        }
        int left = 2 * node;
        int right = 2 * node + 1;
        int mid = (low + high) / 2;
        SegmentTree(given, left, low, mid);
        SegmentTree(given, right, mid + 1, high);
        tree[node] = min(tree[left], tree[right]);
    }

    int query(int node, int low, int hi, int i, int j)
    {
        if (i>hi || j<low)
            return INT_MAX;
        if (low >= i&&hi <= j)
            return tree[node];
        int mid = (low + hi) / 2;
        int left = 2 * node;
        int right = left + 1;
        int x = query(left, low, mid, i, j);
        int y = query(right, mid + 1, hi, i, j);
        return min(x,y);
    }
};
int cs=0;
void solve()
{
    vector<int> v;
    v.push_back(0);
    int n=next(),q=next();
    segment seg(n);
    for(int i=0; i<n; i++)
    {
        v.push_back(next());
    }
    seg.SegmentTree(v,1,1,n);
    printf("Case %d:\n",++cs);
    while(q--)
    {
        int u=next(),v=next();
        printf("%d\n",seg.query(1,1,n,u,v));
    }

}
int main()
{
    int tc=next();
    while(tc--)
    {
        solve();
    }
    return 0;
}

