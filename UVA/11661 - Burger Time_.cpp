#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;

    if(s.find('Z')!=-1){
        cout<<0<<endl;
        return;
    }
    int ind=0;
    while (s[ind]=='.') ind++;
    bool ok=false;
    if(s[ind]=='D') ok=true;
    int ans=INT_MAX/3; 
    for(int i=ind+1;i<s.size();i++){
        if(s[i]=='.') continue;
        if(s[i]=='R' && ok==true){
            ans=min(ans,i-ind);ind=i;ok=!ok;
        }else if(s[i]=='D' && ok==false){
            ans=min(ans,i-ind);ok=!ok;ind=i;
        }else ind=i;
    }
    cout<<ans<<endl;

}
int	main(){

    int tc;
    while (scanf("%d",&tc))
    {
        if(tc==0) break;
        solve();
    }
    


    return 0;
}
