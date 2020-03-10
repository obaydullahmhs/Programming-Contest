#include<bits/stdc++.h>
using namespace std;
bool ar[1100000];
int main()
{
    int n=1000000,m;
    ar[1]=1;
    ar[2]=1;
    int sq=sqrt(n);
    for(int i=4; i<=n; i+=2)
        ar[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(ar[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
                ar[j]=1;
        }
    }
    while(cin>>m)
    {
        if(m==0)
        {
            break;
        }

        for(int i=1; i<m; i++)
        {
            if(ar[i]==0)
            {
                int rem=m-i;

                if(ar[rem]==0)
                {
                    cout<<m<<" = "<<i<<" + "<<rem<<endl;
                    break;
                }

            }

        }
    }

    return 0;
}
