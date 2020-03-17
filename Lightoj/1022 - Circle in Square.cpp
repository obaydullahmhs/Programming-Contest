#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
int main(){

    double n,a,pi = 2 * acos (0.0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        double b=4*a*a*1.0;
        double c=pi*a*a*1.0;
        cout<<fixed<<setprecision(2)<<"Case "<<i<<": "<<b-c<<endl;

    }


 return 0;
}

