#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
class KMP{
private:
    int n;
    bool found;
    vector<int> lps;
    vector<int> storeIndex;
public:
    KMP(){
        n=1e5;found=false;
    }
    KMP(int _n){
        n=_n;found=false;
    }
    void Assign(int _n){
        lps.assign(_n+5,0);
        storeIndex.clear();
    }
    void preProcess(const string& str){
        Assign((int)str.size());
        int i=0,j=1;
        while(j<(int)str.size()){
            if(str[i]==str[j]){
                lps[j]=i+1;
                i++,j++;
            }else{
                if(i!=0){
                    i=lps[i-1];
                }else{
                    lps[j]=0;
                    j++;
                }
            }
        }
    }
    void Search(const string& str, const string& pat){
        preProcess(pat);
        int i=0,j=0;
        while(j<(int)str.size()){
            if(pat[i]==str[j]){
                i++,j++;
            }else{
                if(i!=0) i=lps[i-1];
                else{
                    j++;
                }
            }
            if(i==pat.size()){
                found=true;
                storeIndex.push_back(j-(int)pat.size());
                i=lps[i-1];
            }
        }
    }
    int NumberOfSubstring(const string& str, const string& pat){
        Search(str,pat);
        return (int)storeIndex.size();
    }

}kmp;
int main() {
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        string x,y;
        cin>>x>>y;
        printf("Case %d: %d\n",i,kmp.NumberOfSubstring(x,y));
    }

}


