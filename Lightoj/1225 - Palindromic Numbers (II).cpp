#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int siz=s.size(),cnt=0;;
        for(int j=0;j<siz;j++){
            if(s[j]!=s[siz-1-j]){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<"Case "<<i<<": Yes"<<endl;
        }
        else{
            cout<<"Case "<<i<<": No"<<endl;
        }
    }


 return 0;
}
