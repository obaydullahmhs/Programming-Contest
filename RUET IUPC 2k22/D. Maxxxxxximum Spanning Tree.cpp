#include <stdio.h>

int n;
int path[1000005], sz[1000005];

inline int findUnion(int x) {
  if(path[x] == x) return x;
  return path[x] = findUnion(path[x]);
}

inline bool mergeUnion(int x, int y) {
  int pa = findUnion(x);
  int pb = findUnion(y);
  if(pa == pb) return false;
  if(sz[pa] < sz[pb]) path[pa] = pb, sz[pb] += sz[pa];
  else path[pb] = pa, sz[pa] += sz[pb];
  return true;
}

long long getMST(){
  long long ans = 0;
  int cnt = 0;
  for(int i = n; i > 0; i--){
    for(int j = i + i; j <= n; j += i){
      if(mergeUnion(i, j)){
        ++cnt;
        ans += i;
        if(cnt == n - 1) return ans;
      }
    }
  }
  return ans;
}


int cs;
void solve(){
  scanf("%d", &n);
  for(int i = 0; i <= n; i++) path[i] = i, sz[i] = 1;
  printf("Case %d: %lld\n", ++cs, getMST());
}
int main(){

  int tc = 1; scanf("%d", &tc);
  while(tc--){
    solve();
  }

  return 0;
}
/**

**/
