
#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>b;
        int sum=0;
        if(a%2==1)
        {
            for(int j=a; j<=b; j=j+2)
            {
                sum+=j;
            }
        }
        else
        {
            for(int j=a+1; j<=b; j=j+2)
            {
                sum+=j;
            }
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }

    return 0;
}
