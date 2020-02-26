#include <bits/stdc++.h>

using namespace std;
int cs=0;
void solve(){
    int n,m;
    scanf("%d %d",&n, &m);

    vector<int> v(n);
    for(int& it:v){
        scanf("%d",&it);
    }

    priority_queue<pair<int, pair<int,int>> > pq;
    sort(v.begin(),v.end());
    int initial=0,mx=0;
    for(int i=0;i<n;i++){
        int dif=v[i]-initial;
        mx=max(mx,dif);
        pq.push({dif,{dif,1}});
        initial=v[i];
    }
    int dif=m-initial;
    mx=max(mx,dif);
    pq.push({dif,{dif,1}});

    vector<int> ans(m+5);
    ans[0]=mx;
    for(int i=1;i<=m+2;i++){

        if(pq.top().first==1){
            ans[i]=1;
            continue;
        }
        pair<int,pair<int,int>> out=pq.top();pq.pop();
        int day=out.second.second;
        int big=(out.second.first+day)/(day+1);
        out.first=big,out.second.second=day+1;
        pq.push(out);
        ans[i]=pq.top().first;

    }

    int q;
    scanf("%d",&q);
    printf("Case %d:\n",++cs);
    while(q--){
        int day;
        scanf("%d",&day);
        printf("%d\n",ans[day]);
    }
}
int main() {
	int tc=1;
	scanf("%d",&tc);
	while(tc--){
        solve();
	}
	return 0;
}
