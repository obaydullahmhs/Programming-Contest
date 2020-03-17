#include<bits/stdc++.h>
using namespace std;
double AREA(double a, double b, double c)
{
    double s=(a+b+c)/2.0;
    double area=sqrt(s*(s-a)*(s-b)*(s-c))*1.0;
    return area;
}

int main()
{
    double n,a,b,c,rat;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>b>>c>>rat;
        cout<<"Case "<<i<<": ";

        double low=0,high=a,mid,Ratio,d,e,ABC,BDEC,ADE;
        while(low+0.000000001<high)
        {
            mid=(low+high)/2;
            Ratio=mid/a;
            d=Ratio*b;
            e=Ratio*c;
            ABC=AREA(a,b,c);
            ADE=AREA(mid,d,e);
            BDEC=ABC-ADE;
            double ra=ADE/BDEC;
            if(ra>rat)
            {
                high=mid;
            }
            else if(ra<rat)
            {
                low=mid;
            }
            else if(ra==rat)
            {
                cout<<fixed<<setprecision(10)<<mid<<endl;
                break;
            }
        }
        cout<<fixed<<setprecision(10)<<mid<<endl;

    }


    return 0;
}
