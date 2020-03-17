

#include <bits/stdc++.h>

using namespace std;
class Trie{
public:
    long long ans;
    struct Node{
        Node* ar[4];
        bool endmark;
        long long cnt;
        Node(){
            cnt=0;
            endmark=false;
            for(int i=0; i<4; i++) ar[i]=NULL;
        }
    };
    Node* root;
    Trie(){
        root=new Node();
        ans=0;
    }
    void Insert(const string& s){
        Node* cur=root;
        for(long long i=0; i<s.size(); i++){
            int ascii;
            if(s[i]=='A') ascii=0;
            else if(s[i]=='C') ascii=1;
            else if(s[i]=='T') ascii=2;
            else ascii=3;
            if(cur->ar[ascii]==NULL) {
                cur->ar[ascii]=new Node();
            }
            cur=cur->ar[ascii];
            cur->cnt++;
            ans=max(ans,(i+1LL)*cur->cnt);
        }
        cur->endmark=true;
    }
    void Del(Node* cur)
    {
        for(int i=0; i<4; i++){
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
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        trie.Insert(s);
    }
    printf("Case %d: %lld\n",++cs,trie.ans);
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
