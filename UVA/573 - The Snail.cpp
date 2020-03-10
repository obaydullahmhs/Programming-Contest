#include<bits/stdc++.h>
using namespace std;
int main()
{
    float h,day,d,f;
    while(cin>>h>>day>>d>>f)
    {
        if(h==0)
        {
            break;
        }
        float height=0,a;
        int x=1;
        a=(f/100)*day*1.0;
        while(true)
        {
            height=(height+day);
            if(day>0){
            day=day-a;
            }
            if(height>h)
            {
                cout<<"success on day "<<x<<endl;
                break;
            }
            height=height-d;


            if(height<0)
            {
                cout<<"failure on day "<<x<<endl;
                break;

            }
            x++;
        }

    }



    return 0;
}
