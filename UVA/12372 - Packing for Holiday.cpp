#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc,L,W,H;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cin>>L>>W>>H;
        if(L>20||W>20||H>20){
            cout<<"Case "<<i<<": bad"<<endl;
        }
        else{
            cout<<"Case "<<i<<": good"<<endl;
        }
    }


 return 0;
}

