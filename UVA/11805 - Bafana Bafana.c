#include<stdio.h>
int main(){
    int tc,cs=0;
    scanf("%d",&tc);
    while (tc--)
    {
        int n,k,p;
        scanf("%d %d %d",&n,&k,&p);
        k = k + p;
        k = k % n;
        if(k==0) k=n;

        printf("Case %d: %d\n",++cs,k);
    }

}