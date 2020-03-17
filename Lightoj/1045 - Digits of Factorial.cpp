#include<bits/stdc++.h>
using namespace std;
double ar[1000005];
int main(){
    for(int i=1;i<1000005;i++){
        ar[i]=log10(i)+(ar[i-1]);
    }
    int tc,base,num;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cin>>num>>base;
        double sum=ar[num]/log10(base);

        cout<<"Case "<<i<<": "<<(int)(sum+1)<<endl;
    }


 return 0;
}
