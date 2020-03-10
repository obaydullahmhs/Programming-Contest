#include<bits/stdc++.h>
using namespace std;
int	main(){
    string key[4];
    key[0]="`1234567890-=";key[1]="qwertyuiop[]";key[1]+=(char)92;key[2]="asdfghjkl;'";key[3]="zxcvbnm,./";
    string str;
    while(getline(cin,str)){

        for(auto &it:str){
            for(int i=0;i<4;i++){
                if(key[i].find(tolower(it))!=-1){
                    int ind=key[i].find(tolower(it));
                    it=toupper(it);
                    if(ind==0) break;
                    it=toupper(key[i][ind-1]);
                    break;
                }
            }
        }
        cout<<str<<endl;
    }


    return 0;
}
