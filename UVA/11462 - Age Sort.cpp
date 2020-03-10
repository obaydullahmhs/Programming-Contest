#include<bits/stdc++.h>
using namespace std;
int ar[1000005];
int main()
{
    int input;
    while(true)
    {
        scanf("%d",&input);
        if(input==0)break;
        for(int i=0;i<input;i++){
            scanf("%d",&ar[i]);
        }
        sort(ar,ar+input);
        for(int i=0;i<input-1;i++){
            printf("%d ",ar[i]);
        }
        printf("%d\n",ar[input-1]);
    }
    return 0;
}

