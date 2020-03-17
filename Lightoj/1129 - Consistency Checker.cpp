clude <bits/stdc++.h>

using namespace std;
class Trie{
public:
    bool ok;
    struct Node{
        Node* ar[10];
        bool endmark;
        Node(){
            endmark=false;
            for(int i=0; i<10; i++) ar[i]=NULL;
        }
    };
    Node* root;
    Trie(){
        root=new Node();
        ok=false;
    }
    void Insert(const string& s){
        Node* cur=root;
        for(int i=0; i<s.size(); i++){
            int ascii=s[i]-'0';
            if(cur->ar[ascii]==NULL) {
                cur->ar[ascii]=new Node();
            }
            if(cur->endmark==true) ok=true;
            cur=cur->ar[ascii];
        }
        cur->endmark=true;
    }
    void Del(Node* cur)
    {
        for(int i=0; i<10; i++){
            if(cur->ar[i]!=NULL) Del(cur->ar[i]);
        }
        delete(cur);
    }
    void Delete(){
        Del(root);
    }
};
int cs=0;
void solve()
{
    Trie trie;
    int n;
    scanf("%d",&n);
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),[](string a, string b){return a.size()<b.size();});
    for(int i=0;i<v.size();i++) trie.Insert(v[i]);
    printf("Case %d: ",++cs);
    if(trie.ok) printf("NO\n");
    else printf("YES\n");
    trie.Delete();
}
int main()
{
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
