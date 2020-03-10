#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>b;
        if(a>b){
            cout<<">"<<endl;
        }
        else if(a<b){
            cout<<"<"<<endl;
        }
        else{
            cout<<"="<<endl;
        }
    }

    return 0;
}

