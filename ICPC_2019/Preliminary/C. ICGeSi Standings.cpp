#include <bits/stdc++.h>
using namespace std;

int main()
{

    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {

        int penalty[100],team[51],acc[100],frozen[100],rr[100];
        vector<int> prefix[51];
        for(int i=1; i<=50; i++) prefix[i].push_back(0);
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            acc[a]=b,penalty[a]=c,frozen[a]=d;
            for(int j=0; j<d; j++)
            {
                int r;
                scanf("%d",&r);
                prefix[a].push_back((prefix[a].back()+r));
            }


        }
        for(int j=0; j<n; j++)
        {
            scanf("%d",&rr[j]);
        }
        int curS = acc[rr[0]] + frozen[rr[0]];
        int curP = penalty[rr[0]] + prefix[rr[0]].back();
        int cp = 0;
        for(int i=1; i<n; i++)
        {
            int tid = rr[i];
            int sol = acc[tid];
            int pen = penalty[tid];
            int rem = curS - sol;
            if(sol>curS)
            {
                cp=1;
                break;
            }

            if(sol==curS)
            {
                if(curP > pen)
                {
                    cp=1;
                    break;
                }
                else
                {
                    curP = pen;
                }

            }
            if(sol<curS)
            {
                if(rem <=frozen[tid] )
                {
                    int tryP = pen + prefix[tid][rem];

                    if(tryP < curP )
                    {
                        rem--;
                        if(rem<=0)
                        {
                            curS = sol;
                            curP = pen;

                        }
                        else
                        {
                            curS = sol + rem;
                            curP = pen + prefix[tid][rem];
                        }
                    }
                    else
                    {
                        curP=tryP;
                        curS = sol + rem;
                    }
                }
                else
                {

                    curS = sol + frozen[tid];
                    curP = pen + prefix[tid][frozen[tid]];

                }
            }
        }

        if(cp==0) printf( "Case %d: We respect our judges :)\n",t);
        else printf( "Case %d: Say no to rumour >:\n",t);
    }

}

