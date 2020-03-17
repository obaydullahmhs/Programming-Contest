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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        ld a,b,c;
        cin>>a>>b>>c;
        ld ab=a+b,bc=b+c,ac=a+c;
        ld abc=(ab+bc+ac)/2;
        ld area=sqrt(abc*(abc-ab)*(abc-bc)*(abc-ac));
        ld bc_a=acos((ac*ac+ab*ab-bc*bc)/(2*ab*ac));
        ld ac_b=acos((-ac*ac+ab*ab+bc*bc)/(2*ab*bc));
        ld ab_c=acos((ac*ac-ab*ab+bc*bc)/(2*bc*ac));
        ld ans=area-((bc_a/2)*a*a+(ac_b/2)*b*b+(ab_c/2)*c*c);
        cout<<fixed<<setprecision(10)<<"Case "<<i<<": "<<ans<<endl;

    }

    return 0;
}

