#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b){
        if(a==-1&&b==-1){
            break;
        }
        else{
            int dif=abs(a-b);
            int bac=a+(100-b);
            int fron=b+(100-a);
            int ans=min(dif,bac);
            ans=min(ans,fron);
            cout<<ans<<endl;
        }
    }


    return 0;
}

