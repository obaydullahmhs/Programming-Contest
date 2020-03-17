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
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
vector<string> v;
int n,m;
int vis[21][21],d[21][21];
bool isValid(int x,int y){
    if((x>=0&&x<n)&&(y>=0&&y<m)){
        if(v[x][y]!='#'&&v[x][y]!='m'&&vis[x][y]!=1) return true;
        else return false;
    }
    else return false;
}
int bfs(int x,int y){
    CLR(vis);
    CLR(d);
    vis[x][y]=1;
    queue<pii> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pii unbox=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx=unbox.ff+dx[i];
            int yy=unbox.ss+dy[i];
            if(isValid(xx,yy)){
                vis[xx][yy]=1;
                d[xx][yy]=d[unbox.ff][unbox.ss]+1;
                q.push(make_pair(xx,yy));
            }
        }
    }
}
pii searchChar(char c){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==c) return {i,j};
        }
    }
}
int main(){
    //Fast_Read
    Precision(10)
    //freopen ("output.txt","w",stdout);
    //freopen ("input.txt","r",stdin);
    int tc,cs=0;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        v.clear();
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        pii H=searchChar('h');
        bfs(H.ff,H.ss);
        pii A=searchChar('a');
        pii B=searchChar('b');
        pii C=searchChar('c');
        int ans=max(d[A.ff][A.ss],max(d[B.ff][B.ss],d[C.ff][C.ss]));
        cout<<"Case "<<++cs<<": "<<ans<<nl;

    }


    return 0;
}

