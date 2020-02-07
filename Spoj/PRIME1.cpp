///বিসমিল্লাহির_রহমানির_রহীম
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
ll ar[N];
int main(){
    Fast_Read
    Precision(10)
    // freopen ("output.txt","w",stdout);
    //freopen ("input.txt","r",stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int first,last;
        cin>>first>>last;
        int sq=sqrt(last);
        for(int i=max(2,first);i<=last;i++){
            bool prime=true;
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0&&i!=j){
                    prime=false;
                    break;
                }
            }
            if(prime) cout<<i<<nl;
        }
    }
    return 0;

}

