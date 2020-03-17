#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int main(){
    int n,a,b,c;
    cin>>n;
    for(int i=1;i<=n;i++){
            int flag=0;
        cin>>a>>b>>c;
        if(a>b&&a>c){
            if(a*a==b*b+c*c){
                flag=1;
            }

        }
        else if(b>a&&b>c){
            if(b*b==a*a+c*c){
                flag=1;
            }

        }
         else{
            if(a*a+b*b==c*c){
                flag=1;
            }

        }

    if(flag==1){
        cout<<"Case "<<i<<": yes"<<endl;
    }
    else{
        cout<<"Case "<<i<<": no"<<endl;

    }

    }
 return 0;
}
