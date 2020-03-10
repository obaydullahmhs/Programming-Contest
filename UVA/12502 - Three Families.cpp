#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    long double x,y,z;
    while(tc--){
        cin>>x>>y>>z;
        long double per_family=(x+y)/3;
        //cout<<per_family<<endl;
        x=x-per_family;
       // cout<<x<<endl;
        y=y-per_family;
        //cout<<y<<endl;
        long double ans=z*x/(x+y);
        cout<<ans<<endl;

    }


    return 0;
}

