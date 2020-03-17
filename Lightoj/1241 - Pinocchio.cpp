///বিসমিল্লাহির_রহমানির_রহীম
#include<bits/stdc++.h>
#define     pie                          acos(-1.0)
#define     N                            2000005
#define     eps                          1e-9
#define     ff                           first
#define     ss                           second
#define     nl                           '\n'
#define     mod                          1000000007
#define     sp                           " "
#define     CLR(a)                       memset(a,0,sizeof(a))
#define     SET(a)                       memset(a,-1,sizeof(a))
#define     all(x)                       x.begin(),x.end()
#define     allr(x)                      x.rbegin(),x.rend()
#define     sz(x)                        (int)(x).size()
#define     Fast_Read                    ios_base::sync_with_stdio(false); cin.tie(nullptr);  cout.tie(nullptr);
#define     Precision(x)                 cout.setf(ios::fixed); cout.precision(x);
#define     bug                          cout<<"debug"<<nl;
using namespace std;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
int main()
{
    //Fast_Read
    Precision(10)
    //freopen ("output.txt","w",stdout);
    //freopen ("input.txt","r",stdin);
    int tc,cs=0;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,ans=0;
        cin>>n;
        vector<int>v(n+1);
        v[0]=2;
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        for(int i=1;i<=n;i++){
            ans+=((v[i]-v[i-1]+4)/5);
        }
        cout<<"Case "<<++cs<<": "<<ans<<nl;

    }


    return 0;
}
