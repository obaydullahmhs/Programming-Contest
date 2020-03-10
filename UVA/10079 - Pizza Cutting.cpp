#include<bits/stdc++.h>
using namespace std;
int main(){
    long long slice;
    while(cin>>slice){
        if(slice<0){
            break;
        }
        long long ans=(slice*(slice+1))/2;
        cout<<ans+1<<endl;
    }


 return 0;
}
