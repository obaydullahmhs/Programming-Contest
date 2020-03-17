#include<bits/stdc++.h>
using namespace std;
int S,T;
vector< int > adj[10000];
void primefactor( int n){
    int ind = n;
    int div = 2;
    int add = 0 ;
    while(n > 1){
        add = 0;
        while( n % div == 0 ){
            add = div;
            n /= div;
        }
        div += 1;
        if( add ) adj[ind].push_back(add);
    }
    if( add == ind ) adj[ind].clear();
}
int bfs( ){
    int dist[1001];
    memset(dist, -1, sizeof(dist));
    dist[S] = 0;
    queue < int > q;
    q.push(S);
    int from, to;
    while( !q.empty() ){
        from = q.front();
        q.pop();
        for( int i = 0; i < (int) adj[from].size(); i++ ){
            to = from + adj[from][i];
            if( to <= T && dist[to] == -1 ) {
                q.push(to);
                dist[to] = dist[from] + 1;
                if( to  == T) return dist[T];
            }
        }
    }
    return dist[T];
}
int main(){
    int tc;
    for(int i=2;i<=1000;i++) primefactor(i);
    scanf("%d",&tc);
    int Case=1;
    while(tc--){
        scanf("%d%d",&S,&T);
        printf("Case %d: %d\n",Case++,bfs());
    }
}
