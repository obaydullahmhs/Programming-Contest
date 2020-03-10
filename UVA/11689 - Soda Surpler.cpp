#include<bits/stdc++.h>
using namespace std;
int	main(){

    int tc;
    scanf("%d",&tc);

    while (tc--){
        int e,f,c;
        scanf("%d %d %d",&e,&f,&c);
        int tot=e+f;
        int ans=0;
        while (tot>=c)
        {
            int div=tot/c;
            tot%=c;
            tot+=div;ans+=div;
        }
        cout<<ans<<endl;
    }
    


    return 0;
}
