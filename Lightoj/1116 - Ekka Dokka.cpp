#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,flag=0,c=0,d=0,even,odd;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a%2==1){
            cout<<"Case "<<i<<": Impossible"<<endl;
        }
        else{
             even=2;
             odd=a/2;
                while(odd%2==0){
                    odd=odd/2;
                    even=even*2;
                }

                cout<<"Case "<<i<<": "<<odd<<" "<<even<<endl;
        }

    }

 return 0;
}
