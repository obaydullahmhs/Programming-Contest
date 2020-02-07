#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,t;
    cin>>t;
    while(t--)
    {
        cin>>a;
        c=1;
        b=0;
    	while(a/c>0)
        	{
        		c=c*5;
        		b=b+(a/c);
        	}
        	cout<<b<<endl;
    }
        return 0;
}
