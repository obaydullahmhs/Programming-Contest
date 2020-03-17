
#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int n,m;
int getSolution(int last, int sz){
    if(sz==n){
         return 1;
    }
    int ans=0;
    if(last==0){
        for(int i=0;i<m;i++) ans+=getSolution(v[i],sz+1);
    }else{
        for(int i=0;i<m;i++){
            if(abs(last-v[i])<=2) ans+=getSolution(v[i],sz+1);
        }
    }
    return ans;

}
int cs=0;
void solve(){
    cin>>m>>n;
    v.clear();
    for(int i=0;i<m;i++){
        int in;
        cin>>in;
        v.push_back(in);
    }
    cout<<"Case "<<++cs<<": ";
    cout<<getSolution(0,0)<<endl;
}
int main() {
	int tc=1;
	cin>>tc;
	while(tc--){
        solve();
	}
	return 0;
}
