#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int main(){
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a==0){
            cout<<0<<" "<<0<<endl;
        }
        else if(a<=10){
            cout<<1<<" "<<a-1<<endl;
        }
        else{
            cout<<10<<" "<<a-10<<endl;
        }
    }


 return 0;
}
