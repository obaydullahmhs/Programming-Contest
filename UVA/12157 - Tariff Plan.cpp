#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,n,call;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        cin>>n;
        int Mile=0,Juice=0;
        for(int j=0;j<n;j++){
            cin>>call;
            int temp=(call/30)+1;
            Mile+=temp*10;
            temp=(call/60)+1;
            Juice+=temp*15;
        }
        if(Juice<Mile) cout<<"Case "<<i<<": Juice "<<Juice<<endl;
        else if(Mile<Juice) cout<<"Case "<<i<<": Mile "<<Mile<<endl;
        else cout<<"Case "<<i<<": Mile Juice "<<Juice<<endl;
    }
    return 0;
}

