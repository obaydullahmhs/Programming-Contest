#include<bits/stdc++.h>
using namespace std;
class DSU{

private:
    vector<int> path;
public:
    DSU(){
        path=vector<int>(2e5+25);
        root(2e5+20);
    }
    DSU(int n){
        path=vector<int>(n+25);
        root(n+20);
    }
    void root(int n) {
        for(int i=0; i<=n; i++)
            path[i]=i;
    }
    int findUnion(int x) {
        if(path[x]==x) return x;
        return path[x]=findUnion(path[x]);

    }
    void mergeUnion(int x,int y) {
        path[findUnion(x)]=findUnion(y);
    }
    bool sameSet(int x,int y) {
        return findUnion(x)==findUnion(y);
    }
};
int cs=0;
int main(){
    int a, b;
    DSU dsu;
    vector<pair<int,int>> v;
    int n=0;
    while (cin>>a>>b)
    {
        if(a==-1 && b==-1) break;
        if(a==0 && b==0){
            bool ok=false;
            dsu.root(n+5);
            for(int i=0;i<v.size();i++){
                if(dsu.sameSet(v[i].first,v[i].second)){ ok=true;break;}
                dsu.mergeUnion(v[i].first,v[i].second);
            }
            set<int> st;
            for(int i=0;i<v.size();i++){
                st.insert(dsu.findUnion(v[i].first));
                st.insert(dsu.findUnion(v[i].second));
            }
            if(st.size()>1 || ok) cout<<"Case "<<++cs<<" is not a tree.\n";
            else cout<<"Case "<<++cs<<" is a tree.\n";
            v.clear();
            continue;
        }
        n=max(n,max(a,b));
        v.emplace_back(a,b);

    }
    
	

}