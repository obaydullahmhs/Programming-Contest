#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int main(){
    int n,a;
    stack<int>mystack;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        int cnt=0;
        while(a>0){
            int z=a%2;
            a=a/2;
            if(z==1){
                cnt+=1;
            }
        }
       if(cnt%2==0){
        cout<<"Case "<<i<<": even"<<endl;
       }
       else{
        cout<<"Case "<<i<<": odd"<<endl;

       }
    }


 return 0;
}
