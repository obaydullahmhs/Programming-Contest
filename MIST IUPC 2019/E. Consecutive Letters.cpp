#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cs = 0, n;
const int N = 2e5 + 10;
char s[N];
set<int> st[27];
int result(int ind, int index){
    int mn = -1, mx = n;
    for(int i = 0;i<=26;i++){
        if(st[i].empty() || i==ind) continue;

        auto it = st[i].upper_bound(index);
        if(it!=st[i].end()) mx = min(*it, mx);
        if(it!=st[i].begin()){
            it--;
            mn = max(mn, *it);
        }
    }

    return mx - mn - 1;
}
void solve(){
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0;i<n;i++) st[s[i] - 'A'].insert(i);

    int q; scanf("%d", &q);
    printf("Case %d:\n", ++cs);

    while(q--){
        int c, ind; scanf("%d %d", &c, &ind);
        if(c==1){
            printf("%d\n", result(s[ind] - 'A', ind - 1));
        }else{
            st[s[ind] - 'A'].erase(ind);
            st[26].insert(ind);
        }
    }

    for(int i = 0;i<=26;i++) st[i].clear();
}
int main(){

//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1; scanf("%d", &tc);
    while(tc--){
        solve();
    }

    return 0;
}
