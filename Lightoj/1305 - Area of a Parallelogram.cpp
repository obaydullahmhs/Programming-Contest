#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc,AX,AY,BX,BY,CX,CY,DX,DY,AREA;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cin>>AX>>AY>>BX>>BY>>CX>>CY;
        int xd=CX-BX;
        int yd=CY-BY;
        AREA=(((AX*BY)+(BX*CY)+(CX*AY))-((AY*BX)+(BY*CX)+(CY*AX)));
        cout<<"Case "<<i<<": "<<xd+AX<<" "<<yd+AY<<" "<<abs(AREA)<<endl;
    }


 return 0;
}
