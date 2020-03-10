#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
            int mx=0;
        for(int i=min(a,b);i<=max(a,b);i++){
            int cnt=1,n=i;
            while(n>1){
                if(n%2==0){
                    n=n/2;
                    cnt++;
                }
                else{
                    n=(n*3)+1;
                    cnt++;
                }
            }
            mx=max(mx,cnt);
        }

        printf("%d %d %d\n",a,b,mx);

        }


 return 0;
}

