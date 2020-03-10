#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<iomanip>
#include<math.h>
int ar[100000];
int BinarySearch(int n,int k)
{
    int high = n-1, low = 0, flag=0, posf=0;
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(ar[mid]>k)
        {
            posf=ar[mid];
            flag=1;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(flag==0)
    {
        return -1;
    }
    else
    {
        return posf;
    }

}
int BinarySearch1(int n,int k)
{
    int high = n-1, low = 0, flag=0, posl=0;
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(ar[mid]<k)
        {
            posl=ar[mid];
            flag=1;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==0)
    {
        return -1;
    }
    else
    {
        return posl;
    }

}
using namespace std;
int main(){
    int n,m,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>k;
        int got1=BinarySearch(n, k);
        int got=BinarySearch1(n,k);
        if(got==-1){
        cout<<"X"<<" ";
        }
        else{
            cout<<got<<" ";
        }
        if(got1==-1){
            cout<<"X"<<endl;
        }
        else{
            cout<<got1<<endl;
        }
    }

 return 0;
}
