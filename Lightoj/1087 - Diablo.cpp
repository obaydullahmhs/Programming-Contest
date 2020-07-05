#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int cs = 0;
void solve(){
    int n, q; scanf("%d %d", &n, &q);
    ordered_set<pair<int,int> > st;
    for(int i=0;i<n;i++){
        int in; scanf("%d", &in);
        st.insert({i,in});
    }
    int x = n;
    printf("Case %d:\n",++cs);
    while(q--){
        char c[5]; int k; scanf("%s %d",c, &k);
        if(c[0]=='a'){
            st.insert({x++,k});
        }else{
            if(k>st.size()){
                printf("none\n"); continue;
            }
            auto it = *st.find_by_order(k-1);
            printf("%d\n", it.second);
            st.erase(st.find_by_order(k-1));
        }
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
