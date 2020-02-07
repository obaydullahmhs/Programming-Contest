#include<bits/stdc++.h>
using namespace std;
const int N=200015;
int path[N];
void root(int n)
{
    for(int i=0; i<=n; i++)
        path[i]=i;
}
int findUnion(int x)        ///Find root of x
{
    if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
void mergeUnion(int x,int y)
{
    path[findUnion(x)]=findUnion(y); ///making same root of both x and y
}
bool isSameSet(int x,int y)   ///check two elements are in same set or not
{
    return findUnion(x)==findUnion(y);
}
int main(){
    int n,m;
    cin>>n>>m;
    root(n+5);
    set<int> st,pt;
    int ans=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        int par=findUnion(u);
        if(isSameSet(u,v)){
            if(st.find(par)!=st.end()){
                if(pt.find(par)==pt.end()){
                    ans--;pt.insert(par);
                }
            }
            else{
                ans++;
                st.insert(par);
            }
        }else{
            int paru=findUnion(v);
            if(st.find(par)!=st.end()){
                if(pt.find(par)==pt.end()){
                    ans--;pt.insert(par);
                }
            }
            else if(st.find(paru)!=st.end()){
                if(pt.find(paru)==pt.end()){
                    ans--;pt.insert(paru);
                }
            }
            mergeUnion(u,v);
        }
    }
    cout<<ans<<endl;
}

