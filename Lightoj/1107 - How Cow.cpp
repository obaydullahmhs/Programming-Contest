#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int main(){
    int n,a,b,c,d,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c>>d;
        cin>>m;
        cout<<"Case "<<i<<":"<<endl;
        for(int j=1;j<=m;j++){
            int e,f;
            cin>>e>>f;
            if(e>=a&&e<=c&&f>=b&&f<=d){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }

        }
    }


 return 0;
}
