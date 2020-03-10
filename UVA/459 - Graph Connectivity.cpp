
#include<bits/stdc++.h>
using namespace std;
struct node{
    int Size;
    int val;
};
node ar[26];
void makeset(){
    for(int i=0;i<26;i++){
        ar[i].val=i,ar[i].Size=1;
    }
}
int find(int a){
    if(ar[a].val==a) return a;
    return find(ar[a].val);
}
void Join(int a,int b){
    int x=find(a);
    int y=find(b);
    if(ar[x].Size>ar[y].Size) ar[y].val=ar[x].val,ar[x].Size+=ar[y].Size;
    else ar[x].val=ar[y].val,ar[y].Size+=ar[x].Size;
}
bool check(int a,int b){
    return find(a)==find(b);
}
int main()
{
    fflush(stdout);
    int tc;
    cin>>tc;
    while(tc--){
        char c;
        cin>>c;
        makeset();
        int ans=c-'A'+1;
        cin.ignore();
        string s;
        while(getline(cin,s) && s!=""){
            if(s[0]=='\0') break;
            int a=s[0]-'A',b=s[1]-'A';
            bool ok=check(a,b);
            if(!ok){
                ans--;
                Join(a,b);
            }

        }
        printf("%d\n",ans);
        if(tc) puts("");
    }

    return 0;
}
