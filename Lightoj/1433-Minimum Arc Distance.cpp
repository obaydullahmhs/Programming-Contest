#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,ox,oy,ax,ay,bx,by;
   cin>>n;
   int x=0;
   while(n--){
        x++;
    cin>>ox>>oy>>ax>>ay>>bx>>by;
    double OA=sqrt(((ox-ax)*(ox-ax))+((oy-ay)*(oy-ay)));
    double OB=sqrt(((ox-bx)*(ox-bx))+((oy-by)*(oy-by)));
    double AB=sqrt(((bx-ax)*(bx-ax))+((by-ay)*(by-ay)));
    double angle=acos(((OA*OA)+(OB*OB)-(AB*AB))/(2.0*OA*OB));
    double ans=angle*OA;
    cout<<fixed<<setprecision(8)<<"Case "<<x<<": "<<ans<<endl;
   }

    return 0;
}

