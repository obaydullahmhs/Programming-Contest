#include<bits/stdc++.h>
using namespace std;
inline double dxt(){double fun;scanf("%lf",&fun); return fun;}
double eps=1e-9;
typedef long long ll;
int cs=0;
double x,y,c;
bool possible(double n){
    double m=sqrt(x*x-n*n);
    m=1.0/m;
    double z=sqrt(y*y-n*n);
    z=1.0/z;
    m+=z;
    double k=1.0/c;
    return (m+eps)>=k;
}
void solve()
{
    x=dxt(),y=dxt(),c=dxt();
    printf("Case %d: ",++cs);
    double low=0.0,high=min(x,y),mid=0.0;
    while(high-low>eps){
        mid=(low+high)/2.0;
        if(possible(mid)){
            high=mid-eps;
        }else{
            low=mid+eps;
        }
    }
    cout<<fixed<<setprecision(7)<<mid<<endl;
}
int main()
{
    int tc=1;
    scanf("%d",&tc);
    while(tc--)
    {
        solve();
    }
    return 0;
}
