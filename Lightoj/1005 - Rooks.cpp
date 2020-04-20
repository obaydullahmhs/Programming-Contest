#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[32][32][905];
int cs=0;
ll F(int n, int m, int k){
	if(k>n || k>m ) return 0;
	if(k==0) return 1LL;
	if(n<=0 || m<=0) return 0;
	ll& ret = dp[n][m][k];

	if(ret!=-1) return ret;

	ret = n*F(n-1,m-1,k-1) + F(n, m-1, k);

	return ret;
}
void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	memset(dp,-1,sizeof dp);
	printf("Case %d: %lld\n",++cs, F(n,n,k));

}
int main(int argc, char const *argv[])
{
	int tc;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
}