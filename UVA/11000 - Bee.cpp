#include<bits/stdc++.h>
using namespace std;
int main(){
    long long input;
    while(cin>>input){
        if(input==-1)break;
        else{
            long long male=1,female=1,sum=0,temp=0;
            for(long long i=0;i<input;i++){
                sum=male+female;
                temp=male;
                male=temp+female;
                female=temp+1;
            }
            if(input==0) temp = 0,sum = 1;
            cout<<temp<<" "<<sum<<endl;
        }
    }

 return 0;
}

