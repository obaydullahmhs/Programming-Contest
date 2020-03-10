#include<bits/stdc++.h>

#define     ll      long long
#define     pb      push_back
#define     eps     1e-9

using namespace std;

int main()
{
    //freopen("myfile.txt","w",stdout);
    int tc;
    cin>>tc;
    getchar();
    getchar();
    while(tc--)
    {
        map<string,double>tree;
        string s;
        int input=0;
        while(getline(cin,s))
        {
            if(s.size()==0)
            {
                break;
            }
            tree[s]++;
            input++;
        }
        for(auto x:tree)
        {
            x.second=(x.second*100.0)/(input*1.0);
            cout<<fixed<<setprecision(4)<<x.first<<" "<<x.second<<endl;
        }
        if(tc) puts("");
    }
    return 0;
}

