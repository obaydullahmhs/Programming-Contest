//а¦¬а¦їа¦ёа¦®а¦їа¦Іа§Ќа¦Іа¦ѕа¦№а¦їа¦°_а¦°а¦№а¦®а¦ѕа¦Ёа¦їа¦°_а¦°а¦№а§Ђа¦®
#include<bits/stdc++.h>
#define     pie                          acos(-1.0)
#define     N                            2000005
#define     esp                          1e-9
#define     pii                          pair<int,int>
#define     pb                           push_back
#define     ff                           first
#define     ss                           second
#define     nl                           '\n'
#define     mod                          1000000007
#define     sp                           " "
#define     CLR(a)                       memset(a,0,sizeof(a))
#define     SET(a)                       memset(a,-1,sizeof(a))
#define     mp                           make_pair
#define     all(x)                       x.begin(),x.end()
#define     sz(x)                        (int)(x).size()
#define     Fast_Read                    ios_base::sync_with_stdio(false); cin.tie(nullptr);  cout.tie(nullptr);
#define     Precision(x)                 cout.setf(ios::fixed); cout.precision(x);
#define     bug                          cout<<"debug"<<nl;
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
typedef long long ll;
typedef long double ld;
int main(){
    Fast_Read
    Precision(10)
    // freopen ("output.txt","w",stdout);
    //freopen ("input.txt","r",stdin);
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int ans=INT_MAX;
    for(int i=(1<<(n-1));i>=0;i--){
        int plusminus=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) plusminus+=ar[j];
            else plusminus-=ar[j];
        }
        ans=min(ans,abs(plusminus));
    }
    cout<<ans<<nl;


    return 0;
}
