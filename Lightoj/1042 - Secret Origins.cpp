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
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
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
        int n;
        cin>>n;
        int pos;
        for(int i=1;i<32;i++){
            if(ison(n,i)==false&&ison(n,i-1)==true){
                pos=i-1;
                break;
            }
        }
        n=bitoff(n,pos);
        n=biton(n,pos+1);
        int one=0;
        for(int i=0;i<pos;i++){
            if(n&(1<<i)) one++;
        }
        for(int i=0;i<=pos;i++){
            if(i<one){
                n=biton(n,i);
            }
            else{
                n=bitoff(n,i);
            }
        }
        cout<<"Case "<<++cs<<": "<<n<<nl;

    }


    return 0;
}

