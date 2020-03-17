#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    string s;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        int n,sum=0,donate;
        cin>>n;
        cout<<"Case "<<i<<":"<<endl;
        for(int j=0;j<n;j++){
            cin>>s;
            if(s=="donate"){
                cin>>donate;
                sum+=donate;
            }
            else if(s=="report"){
                cout<<sum<<endl;
            }
        }
    }


 return 0;
}
