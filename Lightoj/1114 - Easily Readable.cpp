

#include <bits/stdc++.h>

using namespace std;
class Trie{
public:
    struct Node{
        Node* ar[52];
        int endmark;
        Node(){
            endmark=0;
            for(int i=0; i<52; i++) ar[i]=NULL;
        }
    };
    Node* root;
    Trie(){
        root=new Node();
    }
    void Insert(const string& s){
        Node* cur=root;
        for(int i=0; i<s.size(); i++){
            int ascii;
            if(isupper(s[i])) ascii=26+s[i]-'A';
            else ascii=s[i]-'a';
            if(cur->ar[ascii]==NULL) cur->ar[ascii]=new Node();
            cur=cur->ar[ascii];
        }
        cur->endmark++;
    }
    int Search(const string& s){
        Node* cur=root;
        for(int i=0; i<s.size(); i++){
            int ascii;
            if(isupper(s[i])) ascii=26+s[i]-'A';
            else ascii=s[i]-'a';
            if(cur->ar[ascii]==NULL) return 0;
            cur=cur->ar[ascii];
        }
        return cur->endmark;
    }
    void Del(Node* cur)
    {
        for(int i=0; i<52; i++){
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
    //Trie trie;
    int n;
    scanf("%d",&n);
    string s;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s.size()>3)
            sort(s.begin()+1,s.end()-1);
        //trie.Insert(s);
        mp[s]++;
    }
    printf("Case %d:\n",++cs);
    int q;
    scanf("%d",&q);
    cin.ignore();
    while(q--){
        getline(cin,s);
        stringstream ss(s);
        long long ans=1;
        while(ss>>s){
            if(s.size()>3)
                sort(s.begin()+1,s.end()-1);
            ans*=(long long)mp[s];//trie.Search(s);
        }
        printf("%lld\n",ans);
    }
    //trie.Delete();
}
int main()
{
    //freopen("output.txt","w",stdout);
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
