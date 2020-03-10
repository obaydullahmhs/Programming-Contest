#include<bits/stdc++.h>
using namespace std;
int main()
{
    int H,M;
    string s;
    while(cin>>s&&s!="0:00"){
    if((int)s.size()==5)
    {
        int h1=s[0]-'0';
        int m1=s[3]-'0';
        int h2=s[1]-'0';
        int m2=s[4]-'0';
        H=(h1*10)+h2;
        M=(m1*10)+m2;
    }
    else
    {
        int m1=s[2]-'0';
        int m2=s[3]-'0';
        H=s[0]-'0';
        M=(m1*10)+m2;
    }
    if(M==0){
        long double ans=abs(12-H)*30.0;
        if(ans>180){
            ans=360-ans;
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    else{
        long double tmp=(long double)5/(60.0/M);
        long double Htmp=tmp+(5*H);
        long double ans=abs(Htmp-M);
        ans=ans*6;
        if(ans>180){
            ans=360-ans;
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    }

        return 0;
    }

