#include<bits/stdc++.h>
using namespace std;
int main(){
    int input,nimu;
    priority_queue<int>v;
    while(cin>>input){
        if(input==0) break;

        for(int i=0;i<input;i++){
            cin>>nimu;
            v.push(-nimu);
        }
        int sum=0;
        while((int)v.size()>1){
            int x=v.top();
            v.pop();
            int y=v.top();
            v.pop();
            v.push(x+y);
            sum+=abs(x+y);
        }
        cout<<sum<<endl;
        v.pop();
    }

 return 0;
}

