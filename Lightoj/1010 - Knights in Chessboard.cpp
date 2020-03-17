#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,m,n;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        cin>>m>>n;
        int mul=m*n,ans=0;
        if(m==1||n==1)
        {
            ans=mul;
        }
        else if(m==2||n==2)
        {
            if(m==2)
            {
                ans=(n/4)*4;
                if(n%4==1)
                    ans=ans+2;
                else if(n%4>1)
                    ans=ans+4;
            }
            else
            {
                ans=(m/4)*4;
                if(m%4==1)
                    ans=ans+2;
                else if(m%4>1)
                    ans=ans+4;
            }
        }
        else
        {
            if(mul%2==0)
            {
                ans=mul/2;
            }
            else
            {
                ans=(mul/2)+1;

            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;

    }

    return 0;
}
