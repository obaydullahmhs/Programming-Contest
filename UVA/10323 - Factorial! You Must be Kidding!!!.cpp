#include<bits/stdc++.h>
using namespace std;

long long Factorial(int n)
{

    long long mul=1;

    for(long long i=n; i>=1; i--)
    {
        mul=mul*i;
    }
    return mul;


}
int main()
{
    long long ans;
    while(cin>>ans)
    {

        if(ans<0 )
        {
         ans=ans*-1ll;
         if(ans%2==1){
            cout<<"Overflow!"<<endl;
         }
         else{
            cout<<"Underflow!"<<endl;
         }
         continue;
        }
        if(ans>13)
        {
            cout<<"Overflow!"<<endl;
        }
        else
        {
            long long res=Factorial(ans);

            if(res<10000){
                cout<<"Underflow!"<<endl;
            }
            else{
                cout<<res<<endl;
            }
        }

    }



    return 0;
}

