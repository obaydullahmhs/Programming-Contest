#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, set<string> > adj;
int cs = 0;
int main(){
    int tc; cin>>tc;
    while(tc--){
        int m;
        cin>>m;
        adj.clear();

        bool ok = true;
        for(int i = 0;i<m;i++){
            string u, v; cin>>u>>v;
            if(adj.find(v)!=adj.end() && adj[v].find(u)!=adj[v].end()) ok  = false;
            adj[u].insert(v);
        }

        cout<<"Case "<<++cs<<": "<<(ok? "Yes":"No")<<"\n";
    }

    return 0;
}

