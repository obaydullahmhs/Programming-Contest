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
vector<string> v;
int n,m;
int vis[501][501],d[501][501];
bool isValid(int x,int y)
{
    if((x>=0&&x<n)&&(y>=0&&y<m))
    {
        if(v[x][y]!='#'&&vis[x][y]==0) return true;
        else return false;
    }
    else return false;
}
void update(int result)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j]==1&&d[i][j]==-1) d[i][j]=result;
        }
    }
}
int bfs(int x,int y)
{
    int cnt=0;
    vis[x][y]=1;
    queue<pii> q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pii unbox=q.front();
        if(v[unbox.ff][unbox.ss]=='C') cnt++;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=unbox.ff+dx[i];
            int yy=unbox.ss+dy[i];
            if(isValid(xx,yy))
            {
                vis[xx][yy]=1;
                q.push(make_pair(xx,yy));
            }
        }
    }
    update(cnt);
}
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
        CLR(vis);
        int q;
        scanf("%d%d%d",&n,&m,&q);
        char ar[m];
        v.clear();
        SET(d);
        for(int i=0; i<n; i++)
        {
            string s;
            scanf("%s",ar);
            s=ar;
            v.push_back(s);
        }
        printf("Case %d:\n",++cs);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(vis[x-1][y-1]!=1) bfs(x-1,y-1);
            printf("%d\n",d[x-1][y-1]);
        }


    }


    return 0;
}

