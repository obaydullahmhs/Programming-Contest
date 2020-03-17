#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    double n,rb,rs,a,pi=acos(-1.0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>rb>>a;
        double b=360/a*1.0;
        b=b/2;
        double c=(pi*b)/180;
        double d=sin(c);
        rs=(rb*d)/(d+1);
        cout<<fixed<<setprecision(10)<<"Case "<<i<<": "<<rs<<endl;
    }


 return 0;
}
