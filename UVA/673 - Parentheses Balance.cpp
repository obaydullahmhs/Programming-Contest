///বিসমিল্লাহির_রহমানির_রহীম
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define    pie              acos(-1)
#define    N                2000005
#define    ESP              1e-9
#define    pii              pair<int,int>
#define    vi               vector<int>
#define    vl               vector<ll>
#define    pb               push_back
#define    pp               pop_back
#define    ff               first
#define    ss               second
#define    nl               "\n"
#define    mod              1000000007
int ar[N];
int main(){
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10);
    cin.tie(nullptr);  cout.tie(nullptr);
    // freopen ("output.txt","w",stdout);
    // freopen ("input.txt","r",stdin);
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        stack<char> brackets;
        string s;
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            if(brackets.empty()) brackets.push(s[i]);
            else if((brackets.top()=='(' && s[i]==')')||(brackets.top()=='[' && s[i]==']')) brackets.pop();
            else brackets.push(s[i]);
        }
        if(brackets.empty()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }



    return 0;
}
