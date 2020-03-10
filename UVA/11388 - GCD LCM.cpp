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
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10);
    cout.tie(nullptr); cin.tie(nullptr);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(b%a==0) printf("%d %d\n",a,b);
        else printf("-1\n");

    }

    return 0;
}

