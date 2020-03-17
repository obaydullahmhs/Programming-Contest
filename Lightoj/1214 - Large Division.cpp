#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define    N        2000005
#define    ESP      1e-9
#define    pii      pair<int,int>
#define    vi       vector<int>
#define    vl       vector<ll>
#define    pb       push_back
#define    pp       pop_back
#define    ff       first
#define    ss       second
ll convert=0;
void operation(char c){
    convert=convert*10+(ll)(c-'0');
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        ll n;
        string s;
        cin>>s>>n;
        for(int j=0;j<s.size();j++){
            if(s[j]=='-') continue;
            operation(s[j]);
            convert=convert%n;
        }
        if(convert) cout<<"Case "<<i<<": "<<"not divisible"<<endl;
        else cout<<"Case "<<i<<": "<<"divisible"<<endl;
        convert=0;

    }

    return 0;
}
