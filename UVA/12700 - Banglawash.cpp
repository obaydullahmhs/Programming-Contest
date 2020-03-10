#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define    pie      acos(-1.0)
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
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10);
    cout.tie(nullptr); cin.tie(nullptr);
    //freopen ("myfile.txt","w",stdout);
    int tc;
    cin>>tc;
    for(int cs=1;cs<=tc;cs++){
        int n;
        string s;
        cin>>n>>s;
        int world=0,bd=0,ab=0,t=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='B') bd++;
            else if(s[i]=='W') world++;
            else if(s[i]=='A') {
                ab++;
                n--;
            }
            else {
                n--;
                t++;
            }
        }
        if(world==n&&n!=0&&t==0) cout<<"Case "<<cs<<": WHITEWASH"<<endl;
        else if(bd==n&&n!=0&&t==0) cout<<"Case "<<cs<<": BANGLAWASH"<<endl;
        else if((int)s.size()==ab) cout<<"Case "<<cs<<": ABANDONED"<<endl;
        else if(world>bd) cout<<"Case "<<cs<<": WWW "<<world<<" - "<<bd<<endl;
        else if(bd>world) cout<<"Case "<<cs<<": BANGLADESH "<<bd<<" - "<<world<<endl;
        else if(bd==world)cout<<"Case "<<cs<<": DRAW "<<bd<<" "<<t<<endl;
    }
    return 0;
}


