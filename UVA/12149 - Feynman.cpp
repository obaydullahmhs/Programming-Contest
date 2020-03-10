
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)){
        if(n==0) break;
        int ans=0;
        for(int i=n;i>=1;i--){
            ans+=i*i;
        }
        printf("%d\n",ans);
    }
    return 0;
}

