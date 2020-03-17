#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
    int n,r1,c1,r2,c2;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r1>>c1>>r2>>c2;
        if(abs(r2-r1)==abs(c2-c1)){
            cout<<"Case "<<i<<": 1"<<endl;
        }
        else if((r1+c1)%2==(r2+c2)%2){
            cout<<"Case "<<i<<": 2"<<endl;
        }
        else{
            cout<<"Case "<<i<<": impossible"<<endl;
        }
    }


 return 0;
}
