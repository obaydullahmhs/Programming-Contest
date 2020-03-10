#include<bits/stdc++.h>
using namespace std;
int main(){
    long long tc,Salary;
    cin>>tc;
    for(long long i=1;i<=tc;i++){
       double Tax=0;
       cin>>Salary;
       if(Salary<=180000){
        cout<<"Case "<<i<<": "<<0<<endl;
       }
       else{
            Salary-=180000;
            long long a,b,c,d;
            if(Salary>=300000){
                a=300000;
            }
            else{
                a=Salary;
                if(a<0)a=0;
            }
            Salary-=300000;
            if(Salary>=400000){
                b=400000;
            }
            else{
                b=Salary;
                if(b<0)b=0;
            }
            Salary-=400000;
            if(Salary>=300000){
                c=300000;
            }
            else{
                c=Salary;
                if(c<0)c=0;
            }
            Salary-=300000;
            if(Salary>0){
                d=Salary;
            }
            else{
                d=0;
            }
         Tax=((a*10.0)/100)+((b*15.0)/100)+((c*20.0)/100)+((d*25.0)/100);
         Tax=ceil(Tax);
            if(Tax<2000)
                Tax=2000;
            cout<<"Case "<<i<<": "<<(long long)Tax<<endl;

       }
       }



 return 0;
}
