#include <bits/stdc++.h>

using namespace std;
inline int nxt(){ int aaa; scanf("%d",&aaa); return aaa;}
typedef long long ll;
namespace Mo{       /// 0 Base
    int k = 345, sum = 0, l = 0, r = -1;
    vector<int> input, ans;
    vector<int> cnt(1e6+5, 0);
    struct info{
        int l, r, id;
        info():l(0),r(0),id(0){}
        info(int _l, int _r, int _id):l(_l),r(_r),id(_id){}
        bool operator <(const info& a)const{
            if(a.l/k == l/k) return a.r>r;
            return a.l>l; ///non decreasing
        }
    };
    vector<info> query;
    void add(int ind){
        cnt[input[ind]]++;
        if(cnt[input[ind]]==1) sum++;
    }
    void remove(int ind){
        cnt[input[ind]]--;
        if(cnt[input[ind]]==0) sum--;
    }
    void clear(){
        input.clear();ans.clear();
        query.clear();cnt.assign(1e6,0);
    }
}
using namespace Mo;
int cs = 0;
void solve(){
    int n = nxt();
    int q=nxt();
    for(int i=0;i<n;i++){
        input.push_back(nxt());
    }
    k = sqrt(n);
    for(int i=0;i<q;i++){
        l=nxt(), r= nxt();
        query.emplace_back(--l,--r,i);
        ans.push_back(0);
    }
    sort(query.begin(),query.end());
    l=0, r = -1, sum = 0;
    for(int i=0;i<q;i++){
        while(r<query[i].r) add(++r);
        while(r>query[i].r) remove(r--);
        while(l<query[i].l) remove(l++);
        while(l>query[i].l) add(--l);
        ans[query[i].id] = sum;
    }
    printf("Case %d:\n",++cs);
    for(int i = 0;i<q;i++){
        printf("%d\n", ans[i]);
    }
    clear();
}
int main() {
    int tc=nxt();
    while(tc--){
        solve();
    }
    return 0;
}
