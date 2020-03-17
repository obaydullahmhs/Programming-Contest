#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc,students;
    cin>>tc;
    for(int i=1;i<=tc;i++){
            cin>>students;
            int ans=0;
        for(int j=0;j<students;j++){
            int dust;
            cin>>dust;
            if(dust>=0){
                ans+=dust;
            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }


 return 0;
}
