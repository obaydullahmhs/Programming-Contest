#include<bits/stdc++.h>
using namespace std;
int ar[100000];
int BinarySearch(int n,int a)
{
    int high = n-1, low = 0, posf=0;
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(ar[mid]==a){
            posf=mid;
            posf=posf+1;
            break;
        }
        else if(ar[mid]>a)
        {
            posf=mid;
            posf=posf+1;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return posf;

}
int BinarySearch1(int n,int b)
{
    int high = n-1, low = 0, posl=0;
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(ar[mid]==b){
            posl=mid;
            posl=posl+1;
            break;
        }
        else if(ar[mid]<b)
        {
            posl=mid;
            posl=posl+1;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

        return posl;


}
int main(){
    int p,n,m,a,b;
    scanf("%d",&p);
    for(int i=1;i<=p;i++){
            printf("Case %d:\n",i);
        scanf("%d%d",&n,&m);
        for(int j=0;j<n;j++){
            scanf("%d",&ar[j]);
        }
        for(int j=0;j<m;j++){
            scanf("%d%d",&a,&b);
            int got=BinarySearch(n,a);
            int got1=BinarySearch1(n,b);
            if(got==0||got1==0){
                printf("%d\n",0);
            }
            else{
            int fin=got1-got;
            printf("%d\n",fin+1);
            }
        }
    }





    return 0;
}
