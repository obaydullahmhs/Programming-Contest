#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b;
    cin>>n;
    for(long long i=1;i<=n;i++){
            cin>>a>>b;
            long long c=a/(2*b);
            b=b*b;
            cout<<"Case "<<i<<": "<<c*b<<endl;
    }


 return 0;
}
