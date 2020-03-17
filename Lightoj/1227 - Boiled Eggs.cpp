#include<bits/stdc++.h>
using namespace std;
int ar[100];
int main(){
    long long tc,n,p,q,pos=0;
    cin>>tc;
    for(long long i=1;i<=tc;i++){
        cin>>n>>p>>q;
        for(long long j=0;j<n;j++){
            cin>>ar[j];
        }
        long long sum=0;
        for(long long j=0;j<n;j++){
            if(sum<q&&j<p){
                sum=sum+ar[j];
                pos=j+1;
            }
            if(sum>q){
                sum=sum-ar[j];
                pos=j;
                break;
            }
        }
        cout<<"Case "<<i<<": "<<pos<<endl;
    }

 return 0;
}
