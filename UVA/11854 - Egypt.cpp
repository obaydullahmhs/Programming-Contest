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
int main()
{
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed);cout.precision(2);
    cout.tie(nullptr);cin.tie(nullptr);
    int ar[4];
    while( cin>>ar[0]>>ar[1]>>ar[2]){
        if(ar[0]==0&&ar[1]==0&&ar[2]==0) break;
        sort(ar,ar+3);
        if(ar[0]*ar[0]+ar[1]*ar[1]==ar[2]*ar[2])
           cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;
    }

    return 0;
}

