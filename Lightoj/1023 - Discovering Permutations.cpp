#include<bits/stdc++.h>
using namespace std;
string in;
int n,vis[100],Size,xx=0;
void permutation(string s)
{
    if(s.size()==n)
    {
        xx++;
        cout<<s<<endl;
      //  if(xx=Size){ exit(0);}
        return;
    }
        for(int i=0;i<n;i++){
            if(vis[i]==1) continue;
           string t=s+in[i];
            vis[i]=1;
            if(xx<Size)
            	permutation(t);
            vis[i]=0;
        }


}
int main()
{
    //freopen ("output.txt","w",stdout);
    int tc,cs=0;
    cin>>tc;
    while(tc--){
        cout<<"Case "<<++cs<<":"<<endl;
        int inn;
        cin>>inn>>Size;
        memset(vis,0,sizeof(vis));
        in.clear();
        xx=0;
        for(int i=0;i<inn;i++){
            in+=(char)('A'+i);
        }
        n=in.size();
        permutation("");
    }


}
