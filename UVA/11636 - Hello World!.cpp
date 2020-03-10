#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define    pie      acos(-1)
#define    N        2000005
#define    ESP      1e-9
#define    pii      pair<int,int>
#define    vi       vector<int>
#define    vl       vector<ll>
#define    pb       push_back
#define    pp       pop_back
#define    ff       first
#define    ss       second
int ar[10000];
int action()
{
    ar[0]=1;
    ar[1]=2;
    int i=2;
    while(ar[i-1]<10002)
    {
        ar[i]=ar[i-1]*2;
        i++;
    }
    return i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int input;
    int n=action();
    int tc=0;
    while(cin>>input)
    {
        if(input<0) break;
        for(int i=0; i<n; i++)
        {
            if(ar[i]>=input)
            {
                cout<<"Case "<<++tc<<": "<<i<<endl;
                break;
            }
        }
    }

    return 0;
}

