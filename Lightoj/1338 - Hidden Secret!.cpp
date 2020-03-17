#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    int tc;
    cin>>tc;

    for(int i=1;i<=tc;i++){
        cin.ignore();
        getline(cin,s);
        getline(cin,t);
        int sn=s.size();
        int tn=t.size();
        int ss=0,ts=0;
        for(int j=0;j<sn;j++){
            if(s[j]>='A'&&s[j]<='Z'){
                s[j]=s[j]+' ';
            }
            if(s[j]==' '){
                ss++;
            }
        }
        for(int j=0;j<tn;j++){
             if(t[j]>='A'&&t[j]<='Z'){
                t[j]=t[j]+' ';
            }
            if(t[j]==' '){
                ts++;
            }
        }
        //cout<<s<<endl;
        //cout<<t<<endl;
        int cnt=0;
        if(tn>=sn){
            for(int j=0;j<sn;j++){
                for(int k=0;k<tn;k++){
                    if(s[j]==' '){
                        break;
                    }
                    if(s[j]==t[k]){
                        cnt++;
                        t[k]=',';
                       //cout<<t<<" "<<cnt<<endl;
                        break;
                    }
                }
            }
        }
        else{

            for(int j=0;j<tn;j++){
                for(int k=0;k<sn;k++){
                    if(t[j]==' '){
                        break;
                    }
                    if(t[j]==s[k]){
                        cnt++;
                        s[k]=',';
                        break;
                    }
                }
            }
        }
        int mn=min((tn-ts),(sn-ss));
        if(cnt==mn){
            cout<<"Case "<<i<<": "<<"Yes"<<endl;
        }
        else{
            cout<<"Case "<<i<<": "<<"No"<<endl;
        }

    }


 return 0;
}
