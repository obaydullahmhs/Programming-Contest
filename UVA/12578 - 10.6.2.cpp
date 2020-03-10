#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double a;
    double pi=acos(-1);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        double radarea=pi*a*a/25.0;
        double recarea=(3*a*a/5.0)-radarea;
        cout<<fixed<<setprecision(2)<<radarea<<" "<<recarea<<endl;
    }

    return 0;
}

