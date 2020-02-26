#include <bits/stdc++.h>

using namespace std;
int cs=0;
void solve(){
    int n;
    cin>>n;

    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    string pat;
    cin>>pat;
    vector<int> ans;
    for(int i=0;i<(int)v.size();i++){
        int k=0;
        for(int j=0;j<(int)v[i].size();j++){
            if(k==(int)pat.size()) break;
            if(v[i][j]==pat[k]) k++;
        }
        if(k==(int)pat.size()) ans.push_back(i+1);
    }
    printf("Case %d:\n",++cs);
    if((int)ans.size()==0){
        printf("No files found!\n");
        return;
    }
    for(int i=0;i<(int)ans.size();i++){
        if(i!=0) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");

}
int main() {
	int tc=1;
	cin>>tc;
	while(tc--){
        solve();
	}
	return 0;
}
