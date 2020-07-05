#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
namespace Mo{       /// 0 Base
    int k = 345, sum = 0, l = 0, r = -1;
    vector<int> input, ans,cnt,counting, paglu;
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
    inline void add(int ind){
        cnt[input[ind]]++;
        counting[cnt[input[ind]]]++;
        counting[cnt[input[ind]]-1]--;
        if(cnt[input[ind]]>paglu.back()) paglu.push_back(cnt[input[ind]]);
    }
    inline void remove(int ind){
        cnt[input[ind]]--;
        counting[cnt[input[ind]]]++;
        counting[cnt[input[ind]]+1]--;
        if(counting[paglu.back()]==0) paglu.pop_back();
    }
    void clear(){
        input.clear();ans.clear();
        query.clear(); paglu.clear();
    }
    ///clear if multiple test case
}
int cs = 0;
using namespace Mo;
void solve(){
    clear();
    int n,c,q; scanf("%d %d %d",&n, &c, &q);
    cnt.assign(c+1,0); counting.assign(n+1,0);
    paglu.push_back(0);
    for(int i=0;i<n;i++){
        int in; scanf("%d",&in);
        input.push_back(in);
    }
    k = 4*sqrt(n);
    for(int i=0;i<q;i++){
        int l, r; scanf("%d %d", &l, &r);
        query.emplace_back(info(l-1,r-1,i));
        ans.push_back(0);
    }
    sort(query.begin(),query.end());
    l=0, r = -1, sum = 0;
    for(int i=0;i<q;i++){
        while(Mo::r<Mo::query[i].r) Mo::add(++Mo::r);
        while(Mo::r>Mo::query[i].r) Mo::remove(Mo::r--);
        while(Mo::l<Mo::query[i].l) Mo::remove(Mo::l++);
        while(Mo::l>Mo::query[i].l) Mo::add(--Mo::l);
        Mo::ans[Mo::query[i].id] = paglu.back();
    }
    printf("Case %d:\n",++cs);
    for(int i = 0;i<q;i++){
        printf("%d\n", ans[i]);
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ///freopen("output.txt","w",stdout);
    int tc=1; scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}
