#include<bits/stdc++.h>
using namespace std;
int BINTODEC(string s){
    int n=s.size();
    int m=n;
    int sum=0;
    for(int i=0;i<m;i++){
        int temp=s[i]-'0';
        if(temp==0){
            sum=sum+0;
            n--;
        }
        else{
        int mul=1;
        for(int j=0;j<n-1;j++){
            mul=mul*2*temp;
        }
        sum=sum+mul;
        n--;
    }
    }

        return sum;
}
int CTI(string s){
    int n=s.size();
    int sum=0;
    for(int i=0;i<n;i++){
        int temp=s[i]-'0';
        sum=sum*10+temp;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    string s,t,o,m[100];
    for(int i=1;i<=n;i++){
        cin>>s>>t;
        s=s+'.';
        t=t+'.';
        int x=0;

        for(int j=0;j<s.size();j++){
            if(s[j]=='.'){
                m[x]=o;
                o.clear();
                x++;
            }
            else{
                o=o+s[j];
            }
        }
           for(int j=0;j<t.size();j++){
            if(t[j]=='.'){
                m[x]=o;
                o.clear();
                x++;

            }
            else{
                o=o+t[j];
            }
        }
        int m0=CTI(m[0]);
        int m1=CTI(m[1]);
        int m2=CTI(m[2]);
        int m3=CTI(m[3]);
        int m4=BINTODEC(m[4]);
        int m5=BINTODEC(m[5]);
        int m6=BINTODEC(m[6]);
        int m7=BINTODEC(m[7]);
     if(m0==m4&&m1==m5&&m2==m6&&m3==m7){
        cout<<"Case "<<i<<": Yes"<<endl;
     }
     else{
        cout<<"Case "<<i<<": No"<<endl;
     }
    }


 return 0;
}
