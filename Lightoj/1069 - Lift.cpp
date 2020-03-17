#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,mypos,liftpos;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mypos>>liftpos;
        int Distance_Lift_And_Me=abs(mypos-liftpos);
        int res=19+(Distance_Lift_And_Me*4)+mypos*4;
        cout<<"Case "<<i<<": "<<res<<endl;
    }


 return 0;
}
