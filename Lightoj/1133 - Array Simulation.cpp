#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<iomanip>
#include<math.h>
using namespace std;
int ar[10000];
int main(){
    int n;
    char z;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m,o,p,q,r,s,t;
        cin>>m>>o;
        for(int j=0;j<m;j++){
            cin>>ar[j];
        }
        for(int j=0;j<o;j++){
            cin>>z;
            if(z=='P'){
                cin>>p>>q;
                int temp=0;
                temp=ar[q];
                ar[q]=ar[p];
                ar[p]=temp;
            }
            else if(z=='R'){
                for(int k=0;k<m/2;k++){
                    int temp=0;
                    temp=ar[k];
                    ar[k]=ar[m-1-k];
                    ar[m-1-k]=temp;
                }
            }

            else if(z=='D'){
                    cin>>p;
                for(int k=0;k<m;k++){
                    ar[k]=ar[k]/p;
                }
            }
            else if(z=='M'){
                cin>>p;
                for(int k=0;k<m;k++){
                    ar[k]=ar[k]*p;
                }
            }
            else if(z=='S'){
                cin>>p;
                for(int k=0;k<m;k++){
                    ar[k]=ar[k]+p;
                }
            }
        }
        cout<<"Case "<<i<<": "<<endl;
        for(int j=0;j<m-1;j++){
            cout<<ar[j]<<" ";
        }
        cout<<ar[m-1]<<endl;
    }


 return 0;
}
