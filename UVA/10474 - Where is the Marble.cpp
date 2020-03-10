#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<iomanip>
#include<math.h>
using namespace std;
int ar[100000];
int BinarySearch(int n,int k)
{
    int high = n-1, low = 0, flag=0, posf=0;
    while(low<=high)
    {
        int mid = (high + low)/2;
        if(ar[mid]==k)
        {
            posf=mid;
            flag=1;
            high=mid-1;
        }
        else if(ar[mid]>k)
        {
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
int main()
{
    int n, k, got, N, Q;
    int z=1;
    while(cin>>N>>Q)
    {
        if(N==0&&Q==0)
        {
            break;
        }
        cout<<"CASE# "<<z<<":"<<endl;
        z++;
        for(int i=0; i<N; i++)
        {
            cin>>ar[i];
        }
        sort(ar,ar+N);
        for(int i=1; i<=Q; i++)
        {
            cin>>k;
            got = BinarySearch(N, k);
            if(got==-1)
            {
                cout<<k<<" not found"<<endl;
            }
            else{
                cout<<k<<" found at "<<got+1<<endl;
            }
        }

    }

    return 0;
}

